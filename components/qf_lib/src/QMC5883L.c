
#include "qmc5883l.h"

#if qmc5883l_lib_compile_en

#define DATA_OUTPUT_X_LSB 0X00
#define DATA_OUTPUT_X_MSB 0X01
#define DATA_OUTPUT_Y_LSB 0X02
#define DATA_OUTPUT_Y_MSB 0X03
#define DATA_OUTPUT_Z_LSB 0X04
#define DATA_OUTPUT_Z_MSB 0X05

#define STATUS 0X06
#define BIT_DOR 0X04  // “0”: normal, “1”: data skipped for reading
#define BIT_OVL 0X02  // 0”: normal, “1”: data overflow
#define BIT_DRDY 0X01 // 0”: no new data, “1”: new data is ready

#define TEMP_LSB 0X07 // in 2’s complement,  100 LSB/℃
#define TEMP_MSB 0X08

#define CONTROL_1 0X09

#define CONTROL_2 0X0A
#define BIT_INT_ENB 0X01  // INT_ENB: “0”: enable interrupt PIN, “1”: disable interrupt PIN
#define BIT_ROL_PNT 0X40  // ROL_PNT: “0”: Normal, “1”: Enable pointer phi-over function
#define BIT_SOFT_RST 0X80 // SOFT_RST: “0”: Normal “1”: Soft reset, restore default value of all registers.

#define SET_RESET_PERIOD 0X0B
#define CHIP_ID 0X0D

#define ID_VALUE 0XFF

typedef struct
{
    uint8_t mode : 2;
    uint8_t odr : 2;
    uint8_t range : 2;
    uint8_t osr : 2;
} reg_control_1_t;

typedef struct
{
    uint8_t int_enb : 6;
    uint8_t rol_pnt : 2;
} reg_control_2_t;

typedef struct
{
    int16_t offset[3]; // 偏移
    float weight[3];   // 权重
} calibration_t;

static qmc5883l_trans_cb_t trans_cb = {NULL, NULL};
static qmc_xyz_range_t range = {0, 0, 0, 0, 0, 0};
static uint8_t range_updata_en = 0;
static reg_control_1_t contron_1_reg_value;
static reg_control_2_t contron_2_reg_value;
static calibration_t calibration;

void qmc5883l_attach_trans_cb(qmc5883l_trans_cb_t *cbs)
{
    trans_cb = *cbs;
}

void qmc5883l_sleep(uint8_t en)
{
    contron_1_reg_value.mode = !en;
    trans_cb.write_byte(qmc5883l_ADDR, CONTROL_1, *(uint8_t *)&contron_1_reg_value);
}

void qmc5883l_reset()
{
    trans_cb.write_byte(qmc5883l_ADDR, CONTROL_2, BIT_SOFT_RST);
}

//**************************************************************

// 初始化qmc5883l，配置相应模式**************
uint8_t qmc5883l_begin(qmc5883l_mode_t mode, qmc5883l_odr_t odr, qmc5883l_range_t range, qmc5883l_osr_t osr)
{
    uint8_t tmp = 0;
    if (trans_cb.read_bytes == NULL)
    {
#if qmc5883l_DEBUG
        qmc5883l_DEBUG_LOG_PRINTF("qmc5883l initialization failed, iic trans cb is not register!\n");
#endif
        return 1;
    }

    trans_cb.read_bytes(qmc5883l_ADDR, CHIP_ID, &tmp, 1);
    if (tmp != 0xff)
    {
#if qmc5883l_DEBUG
        qmc5883l_DEBUG_LOG_PRINTF("qmc5883l read failed, chek connect!\n");
#endif
        return 2;
    }

    trans_cb.write_byte(qmc5883l_ADDR, SET_RESET_PERIOD, 0x01);

    contron_1_reg_value.mode = mode;
    contron_1_reg_value.range = range;
    contron_1_reg_value.odr = odr;
    contron_1_reg_value.osr = osr;

    trans_cb.write_byte(qmc5883l_ADDR, CONTROL_1, *(uint8_t *)&contron_1_reg_value);

    contron_2_reg_value.int_enb = 0;
    contron_2_reg_value.rol_pnt = 0;
    trans_cb.write_byte(qmc5883l_ADDR, CONTROL_2, *(uint8_t *)&contron_2_reg_value);

    return 0;
}
//***********************************************************************

void qmc5883l_get_xyz(int16_t *x, int16_t *y, int16_t *z)
{
    uint8_t buffer[6];
    int16_t var[3];
    trans_cb.read_bytes(qmc5883l_ADDR, DATA_OUTPUT_X_LSB, buffer, sizeof(buffer));

    var[0] = (buffer[1] << 8) | buffer[0];
    var[1] = (buffer[3] << 8) | buffer[2];
    var[2] = (buffer[5] << 8) | buffer[4];

#if qmc5883l_reverse
    var[0] = -var[0];
    var[1] = -var[1];
#endif

    if (range_updata_en)
    {

        if (var[0] < range.x_min)
            range.x_min = var[0];
        if (var[0] > range.x_max)
            range.x_max = var[0];

        if (var[1] < range.y_min)
            range.y_min = var[1];
        if (var[1] > range.y_max)
            range.y_max = var[1];

        if (var[2] < range.z_min)
            range.z_min = var[2];
        if (var[2] > range.z_max)
            range.z_max = var[2];
    }

    if (x != NULL)
    {
        *x = (int16_t)((var[0] - calibration.offset[0]) * calibration.weight[0]);
    }
    if (y != NULL)
    {
        *y = (int16_t)((var[1] - calibration.offset[1]) * calibration.weight[1]);
    }
    if (z != NULL)
    {
        *z = (int16_t)((var[2] - calibration.offset[2]) * calibration.weight[2]);
    }
}

qmc_xyz_range_t qmc5883l_get_xyz_range()
{
    return range;
}

int16_t qmc5883l_get_angle()
{
    int16_t x, y, z;
    qmc5883l_get_xyz(&x, &y, &z);

    // float bx = x, by = y, bz = z;

    // float roll = atan2(by, bz) * (180.0 / M_PI);
    // float pitch = atan2(bx, bz) * (180.0 / M_PI);

    // float tiltCompensationX = sin(roll * M_PI / 180.0);
    // float tiltCompensationY = sin(pitch * M_PI / 180.0);

    // bx += bx * tiltCompensationX;
    // by += by * tiltCompensationY;

    int16_t heading = atan2(y, x) * (180.0 / M_PI);
    heading += qmc5883l_xy_offset_angle;

    return (heading % 360);
}

void qmc5883l_set_calibration(qmc_xyz_range_t *range)
{
    float x_avg_delta = (range->x_max - range->x_min) / 2;
    float y_avg_delta = (range->y_max - range->y_min) / 2;
    float z_avg_delta = (range->z_max - range->z_min) / 2;

    float avg_delta = (x_avg_delta + y_avg_delta + z_avg_delta) / 3;

    calibration.offset[0] = (range->x_min + range->x_max) / 2;
    calibration.offset[1] = (range->y_min + range->y_max) / 2;
    calibration.offset[2] = (range->z_min + range->z_max) / 2;
    calibration.weight[0] = avg_delta / x_avg_delta;
    calibration.weight[1] = avg_delta / y_avg_delta;
    calibration.weight[2] = avg_delta / z_avg_delta;
}

void qmc5883l_clear_calibration()
{
    calibration.offset[0] = 0;
    calibration.offset[1] = 0;
    calibration.offset[2] = 0;
    calibration.weight[0] = 1.;
    calibration.weight[0] = 1.;
    calibration.weight[0] = 1.;
}

void qmc5883l_xyz_range_updata(uint8_t en)
{
    if (en)
    {
        range.x_min = 32767;
        range.y_min = 32767;
        range.z_min = 32767;
        range.x_max = -32768;
        range.y_max = -32768;
        range.z_max = -32768;
    }
    range_updata_en = en;
}

#endif

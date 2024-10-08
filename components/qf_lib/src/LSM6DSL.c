
#include "LSM6DSL.h"

#if lsm6dsl_lib_compile_en

static lsm6dsl_trans_cb_t _trans_cb = {NULL, NULL};

void lsm6dsl_attach_trans_cb(lsm6dsl_trans_cb_t *cbs)
{
    _trans_cb = *cbs;
}

/**
 * @brief 读取
 *
 * @param get_type 读取类型
 * @param buffer 缓存
 * @return lsm6dsl_ret_t
 */
lsm6dsl_ret_t lsm6dsl_read(lsm6dsl_get_t get_type, void *buffer)
{
    lsm6dsl_ret_t ret = LSM6DSL_OK;

    if (_trans_cb.read_bytes == NULL)
        return LSM6DSL_NO_TRANS_CB;

    if (get_type == LSM6DSL_GET_GY)
    {
        //_trans_cb.read_bytes(...)
        //*(uint16_t *)buffer = ....
        //
        return ret;
    }
    if (get_type == LSM6DSL_GET_XL)
    {

        return ret;
    }

    return LSM6DSL_DATA_ERR;
}

/**
 * @brief 设置
 *
 * @param set_type 设置类型
 * @param buffer 缓存
 * @return lsm6dsl_ret_t
 */
lsm6dsl_ret_t lsm6dsl_set(lsm6dsl_set_t set_type, void *buffer)
{
    lsm6dsl_ret_t ret = LSM6DSL_OK;

    if (_trans_cb.write_byte == NULL)
        return LSM6DSL_NO_TRANS_CB;

    if (set_type == LSM6DSL_SET_GY_RANGE)
    {
        // uint8_t range = *(uint8_t *)buffer;
        //  _trans_cb.write_byte(...)
        return ret;
    }
    return LSM6DSL_DATA_ERR;
}
//**************************************************************

// 初始化lsm6dsl，根据需要请参考pdf进行修改**************
lsm6dsl_ret_t lsm6dsl_begin()
{

    if (_trans_cb.read_bytes == NULL || _trans_cb.write_byte == NULL)
    {
#if lsm6dsl_DEBUG
        lsm6dsl_DEBUG_LOG_PRINTF("lsm6dsl initialization failed, iic trans cb is not attach\n");
#endif
        return LSM6DSL_NO_TRANS_CB;
    }

    //  _trans_cb.read_bytes(lsm6dsl_ADDR, lsm6dsl_CHIP_ID, buffer, 1);

    //     if (buffer[0] != lsm6dsl_DEFAULT_CHIP_ID)
    //     {
    // #if lsm6dsl_DEBUG
    //         lsm6dsl_DEBUG_LOG_PRINTF("lsm6dsl initialization failed,please chek hardware connect and iic slave address\n");
    // #endif
    //         return 2;
    //     }

    // _trans_cb.write_byte(lsm6dsl_ADDR, lsm6dsl_CTRL_MEAS_REG, lsm6dsl_MODE);
    // _trans_cb.write_byte(lsm6dsl_ADDR, lsm6dsl_CONFIG_REG, 5 << 2);

    return LSM6DSL_OK;
}
//***********************************************************************

#endif

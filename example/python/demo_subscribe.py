import time
import signal
import fi_fsa_v3

stop_flag = False

def signal_handler(sig, frame):
    global stop_flag
    if sig == signal.SIGINT:
        stop_flag = True
        print("\nReceived SIGINT, terminating...\n")

def main():
    global stop_flag

    signal.signal(signal.SIGINT, signal_handler)
    print(f"Hello, FSA!\n")
    device = fi_fsa_v3.FSA()
    ret = device.Init("192.168.137.101")
    if ret != fi_fsa_v3.ret_e.SUCCESS:
        print(f"FSA Init failed, ret: {int(ret)}")
        exit(1)
    print(f"FSA initialized\n")

    subs_config = fi_fsa_v3.subs_config_t()
    ret = device.EnableSubscribe(subs_config, 1000, 0)
    if ret != fi_fsa_v3.ret_e.SUCCESS:
        print(f"EnableSubscribe failed, ret: {int(ret)}\n")
        exit(1)

    subs_data = fi_fsa_v3.subs_data_t()

    while not stop_flag:
        ret = device.GetSubsData(subs_data)
        if ret != fi_fsa_v3.ret_e.SUCCESS:
            print(f"GetSubsData failed, ret: {int(ret)}\n")
        else:
            print(
                f"cnt: {subs_data.cnt}, "
                f"p: {subs_data.pvct.pos:.4f}, "
                f"v: {subs_data.pvct.vel:.4f}, "
                f"c: {subs_data.pvct.cur:.4f}, "
                f"t: {subs_data.pvct.tor:.4f}, "
                f"te: {subs_data.pvct.tor_e:.4f}\n"
            )

            print(
                f"mos: {subs_data.temp_vbus.mos:f}, "
                f"coil: {subs_data.temp_vbus.coil:f}, "
                f"vbus: {subs_data.temp_vbus.vbus:f}\n"
            )

            for i in range(8):
                print(f"error[{i}]: {subs_data.error[i]}\n")

        err_code = fi_fsa_v3.err_code_t()
        ret = device.GetErrCode(err_code, 1000, 0)
        if ret != fi_fsa_v3.ret_e.SUCCESS:
            print(f"GetErrCode failed, ret: {int(ret)}\n")
        for i in range(8):
            print(f"err_code[{i}]: 0x{err_code.arr[i]:X}\n")

        parsed_err_codes = fi_fsa_v3.parsed_err_code_t()
        ret = device.ParseErrCode(err_code, parsed_err_codes)
        if ret != fi_fsa_v3.ret_e.SUCCESS:
            print(f"ParseErrCode failed, ret: {int(ret)}\n")
        print(f"parsed_err_codes size: {len(parsed_err_codes.vec)}\n")
        for e in parsed_err_codes.vec:
            print(
                f"err_level: {e.err_level}, "
                f"err_u32_index: {e.err_u32_index}, "
                f"err_bit_index: {e.err_bit_index}, "
                f"parsed_code: 0x{e.parsed_code:X}, "
                f"str_for_log: {e.str_for_log}\n"
            )

        time.sleep(0.001)

    subs_config.enable = 0
    ret = device.EnableSubscribe(subs_config)
    if ret != fi_fsa_v3.ret_e.SUCCESS:
        print(f"DisableSubscribe failed, ret: {int(ret)}\n")
    else:
        print("Subscription disabled successfully\n")

if __name__ == "__main__":
    main()






# import time
# import fi_fsa_v3

# device = fi_fsa_v3.FSA()
# ret = device.Init("192.168.137.101")
# if ret != fi_fsa_v3.ret_e.SUCCESS:
#     print(f"Init returned: {ret}")
#     exit(1)

# subs_config = fi_fsa_v3.subs_config_t()
# subs_config.enable = 1
# subs_config.freq = 2000
# subs_config.keepalive_time_ms = 10000
# subs_config.pos = 1
# subs_config.vel = 1
# subs_config.cur = 1
# subs_config.tor = 1
# subs_config.tor_em = 1
# subs_config.error = 1
# subs_config.error_ext2 = 1
# subs_config.error_ext3 = 1
# subs_config.error_ext4 = 1
# subs_config.error_ext5 = 1
# subs_config.error_ext6 = 1
# subs_config.error_ext7 = 1
# subs_config.error_ext8 = 1
# subs_config.temp_mos = 1
# subs_config.temp_coil = 1
# subs_config.vbus = 1

# ret = device.EnableSubscribe(subs_config)
# if ret != fi_fsa_v3.ret_e.SUCCESS:
#     print(f"EnableSubscribe returned: {ret}")
#     exit(1)

# subs_data = fi_fsa_v3.subs_data_t()

# while True:
#     time.sleep(0.1)
#     # 获取订阅数据
#     ret = device.GetSubsData(subs_data)
#     if ret != fi_fsa_v3.ret_e.SUCCESS:
#         print(f"GetSubsData returned: {ret}")
#         continue
#     # 打印订阅数据，位置、速度、电流、力矩（位置单位为弧度，速度单位为弧度每秒，电流单位为安培，力矩单位为牛米）
#     print(f"pos: {subs_data.pvct.pos}, vel: {subs_data.pvct.vel}, cur: {subs_data.pvct.cur}, tor: {subs_data.pvct.tor}, tor_e: {subs_data.pvct.tor_e}")
#     # 打印原始错误码
#     print(f"error: {subs_data.error[0]}, error_ext2: {subs_data.error[1]}, error_ext3: {subs_data.error[2]}, error_ext4: {subs_data.error[3]}, error_ext5: {subs_data.error[4]}, error_ext6: {subs_data.error[5]}, error_ext7: {subs_data.error[6]}, error_ext8: {subs_data.error[7]}")
#     # 打印温度和电压
#     print(
#         f"temp_mos: {subs_data.temp_vbus.mos}, temp_coil: {subs_data.temp_vbus.coil}, vbus: {subs_data.temp_vbus.vbus}")
#     # 打印计数和延迟
#     print(
#         f"cnt: {subs_data.cnt}, latency_from_recv_ns: {subs_data.latency_from_recv_ns}")
#     # 将原始错误码解析为可读格式
#     parsed_err_code = fi_fsa_v3.parsed_err_code_t()
#     err_code = fi_fsa_v3.err_code_t()
#     err_code.arr = subs_data.error
#     ret = device.ParseErrCode(err_code, parsed_err_code)
#     if ret != fi_fsa_v3.ret_e.SUCCESS:
#         print(f"ParseErrCode returned: {ret}")
#     else:
#         have_error = False
#         for item in parsed_err_code.vec:
#             have_error = True
#             parsed_code_hex = hex(item.parsed_code)
#             print(f"  err_level: {item.err_level}, err_u32_index: {item.err_u32_index}, err_bit_index: {item.err_bit_index}, parsed_code: {parsed_code_hex}, str_for_log: {item.str_for_log}")
#         if not have_error:
#             print("  no error")

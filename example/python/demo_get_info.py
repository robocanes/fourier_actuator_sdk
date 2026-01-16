import time
import fi_fsa_v3


def main():
    print(f"Hello, FSA!\n")
    device = fi_fsa_v3.FSA()
    ret = device.Init("192.168.137.101")
    if ret != fi_fsa_v3.ret_e.SUCCESS:
        print(f"FSA Init failed, ret: {int(ret)}\n")
        exit(1)
    print("FSA initialized\n")

    while True:
        rx_PVCTTe = fi_fsa_v3.pvctte_t()
        ret = device.GetPVCTTe(rx_PVCTTe, 1000, 0)
        if ret != fi_fsa_v3.ret_e.SUCCESS:
            print(f"GetPVCTTe failed, ret: {int(ret)}\n")
        else:
            print(
                f"p: {rx_PVCTTe.pos:.4f}, "
                f"v: {rx_PVCTTe.vel:.4f}, "
                f"c: {rx_PVCTTe.cur:.4f}, "
                f"t: {rx_PVCTTe.tor:.4f}, "
                f"te: {rx_PVCTTe.tor_e:.4f}\n"
            )

        rx_temp_vbus = fi_fsa_v3.temp_vbus_t()
        ret = device.GetTempVbus(rx_temp_vbus, 1000, 0)
        if ret != fi_fsa_v3.ret_e.SUCCESS:
            print(f"GetTempVbus failed, ret: {int(ret)}\n")
        else:
            print(
                f"mos: {rx_temp_vbus.mos:f}, "
                f"coil: {rx_temp_vbus.coil:f}, "
                f"vbus: {rx_temp_vbus.vbus:f}\n"
            )

        err_code = fi_fsa_v3.err_code_t()
        ret = device.GetErrCode(err_code, 1000, 0)
        if ret != fi_fsa_v3.ret_e.SUCCESS:
            print(f"GetErrCode failed, ret: {int(ret)}\n")
        else:
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

        rx_pid_param = fi_fsa_v3.pid_param_t()
        ret = device.GetPIDParams(rx_pid_param, 1000, 0)
        if ret != fi_fsa_v3.ret_e.SUCCESS:
            print(f"FSA Get PID Params failed with code: {int(ret)}\n")
        else:
            print(
                f"PID: pos_kp={rx_pid_param.pos_kp:.4f}, "
                f"vel_kp={rx_pid_param.vel_kp:.4f}, "
                f"vel_ki={rx_pid_param.vel_ki:.4f}\n"
            )

        rx_pd_param = fi_fsa_v3.pd_param_t()
        ret = device.GetPDParams(rx_pd_param, 1000, 0)
        if ret != fi_fsa_v3.ret_e.SUCCESS:
            print(f"FSA Get PD Params failed with code: {int(ret)}\n")
        else:
            print(
                f"PD: kp={rx_pd_param.pd_kp:.4f}, "
                f"kd={rx_pd_param.pd_kd:.4f}\n"
            )

        type_subversion = fi_fsa_v3.type_subversion_t()
        ret = device.GetTypeSubversion(type_subversion, 1000, 0)
        if ret != fi_fsa_v3.ret_e.SUCCESS:
            print(f"GetTypeSubversion failed, ret: {int(ret)}\n")
        else:
            print(
                f"type: {''.join(type_subversion.type).rstrip('\x00')}, "
                f"sub_version: {''.join(type_subversion.sub_version).rstrip('\x00')}\n"
            )

        comm_req_get = fi_fsa_v3.comm_req_get_t()
        comm_resp_get = fi_fsa_v3.comm_resp_get_t()
        ret = device.GetCommConfig(comm_req_get, comm_resp_get, 1000, 0)
        if ret != fi_fsa_v3.ret_e.SUCCESS:
            print(f"GetCommConfig failed, ret: {int(ret)}\n")
        else:
            print(
                f"name: {''.join(comm_resp_get.name).rstrip('\x00')}, "
                f"type: {''.join(comm_resp_get.type).rstrip('\x00')}, "
                f"mcu_fw_version: {''.join(comm_resp_get.mcu_fw_version).rstrip('\x00')}, "
                f"mac_address: {''.join(comm_resp_get.mac_address).rstrip('\x00')}, "
                f"uid: {''.join(comm_resp_get.uid).rstrip('\x00')}, "
                f"sn: {''.join(comm_resp_get.sn).rstrip('\x00')}, "
                f"PCBA_sn: {''.join(comm_resp_get.PCBA_sn).rstrip('\x00')}, "
                f"gearbox_sn: {''.join(comm_resp_get.gearbox_sn).rstrip('\x00')}, "
                f"static_IP: {''.join(comm_resp_get.static_IP).rstrip('\x00')}, "
                f"gateway: {''.join(comm_resp_get.gateway).rstrip('\x00')}, "
                f"subnet_mask: {''.join(comm_resp_get.subnet_mask).rstrip('\x00')}, "
                f"dns_1: {''.join(comm_resp_get.dns_1).rstrip('\x00')}, "
                f"dns_2: {''.join(comm_resp_get.dns_2).rstrip('\x00')}, "
                f"DHCP_enable: {comm_resp_get.DHCP_enable}\n"
            )

        time.sleep(1)

if __name__ == "__main__":
    main()

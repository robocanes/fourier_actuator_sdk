import fi_fsa_v3
import time

def main():
    print(f"Hello, FSA!\n")
    device = fi_fsa_v3.FSA()
    ret = device.Init("192.168.137.101")
    if ret != fi_fsa_v3.ret_e.SUCCESS:
        print(f"Init returned: {ret}")
        exit(1)
    print(f"FSA initialized\n")

    ret = device.EnableControl(fi_fsa_v3.ctrl_mode_e.POSITION_MODE, 1000, 0)
    if ret != fi_fsa_v3.ret_e.SUCCESS:
        print(f"FSA Enable Control failed with code: {ret}")

    ret = device.SetPIDParams(0.6, 0.1, 0.1, 1000, 0)
    if ret != fi_fsa_v3.ret_e.SUCCESS:
        print(f"FSA Set PID Params failed with code: {ret}")

    rx_pid_param = fi_fsa_v3.pid_param_t()
    ret = device.GetPIDParams(rx_pid_param, 1000, 0)
    if ret != fi_fsa_v3.ret_e.SUCCESS:
        print(f"FSA Get PID Params failed with code: {ret}")
    else:
        print(f"FSA: pos_kp: {rx_pid_param.pos_kp:.4f}, " f"vel_kp: {rx_pid_param.vel_kp:.4f}, " f"vel_ki: {rx_pid_param.vel_ki:.4f}")

    rx_PVCTTe = fi_fsa_v3.pvctte_t()
    ret = device.GetPVCTTe(rx_PVCTTe, 1000, 0)
    if ret != fi_fsa_v3.ret_e.SUCCESS:
        print(f"GetPVCTTe failed, ret: {ret}")

    for size_t in range(1000):
        rx_PVCTTe.pos += 0.001
        ret = device.SetPosition(rx_PVCTTe.pos, 0, 0)
        if ret != fi_fsa_v3.ret_e.SUCCESS:
            print(f"FSA Set Position failed with code: {ret}")
        time.sleep(0.002)

    for size_t in range(1000, 0, -1):
        rx_PVCTTe.pos -= 0.001
        ret = device.SetPosition(rx_PVCTTe.pos, 0, 0)
        if ret != fi_fsa_v3.ret_e.SUCCESS:
            print(f"FSA Set Position failed with code: {ret}")
        time.sleep(0.002)

    ret = device.DisableControl()
    if ret != fi_fsa_v3.ret_e.SUCCESS:
        print(f"FSA Disable Control failed with code: {ret}")

if __name__ == "__main__":
    main()

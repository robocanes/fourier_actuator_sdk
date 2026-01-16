import time
import fi_fsa_v3

def main():
    print(f"Hello, FSA!\n")
    device = fi_fsa_v3.FSA()
    ret = device.Init("192.168.137.101")
    if ret != fi_fsa_v3.ret_e.SUCCESS:
        print(f"Init returned: {ret}")
        exit(1)
    print(f"FSA initialized\n")

    ret = device.EnableControl( fi_fsa_v3.ctrl_mode_e.TORQUE_MODE, 1000, 0 )
    if ret != fi_fsa_v3.ret_e.SUCCESS:
        print(f"FSA Enable Control failed with code: {ret}")

    tor = 0
    for size_t in range(30):
        tor += 0.1
        ret = device.SetTorque(tor)
        if ret != fi_fsa_v3.ret_e.SUCCESS:
            print(f"FSA Set Torque failed with code: {ret}")
        time.sleep(0.2)

    for size_t in range(30, 0, -1):
        tor -= 0.1
        ret = device.SetTorque(tor)
        if ret != fi_fsa_v3.ret_e.SUCCESS:
            print(f"FSA Set Torque failed with code: {ret}")
        time.sleep(0.2)

    ret = device.DisableControl()
    if ret != fi_fsa_v3.ret_e.SUCCESS:
        print(f"FSA Disable Control failed with code: {ret}")

if __name__ == "__main__":
    main()

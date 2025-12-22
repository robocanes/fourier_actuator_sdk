#include "fsav2.h"

#include <unistd.h>

#include <cstdio>

using namespace AC2;

int main() {
  FSA fsa;
  const char *ip = "192.168.137.101";

  FSA::ret_e ret = fsa.Init(ip, FSA::net_recv_mode_e::YIELD_WAIT);
  if (ret != FSA::ret_e::SUCCESS) {
    printf("FSA(%s): init failed with code: %d\n", ip, static_cast<int>(ret));
    return -1;
  }

  ret = fsa.EnableControl(FSA::ctrl_mode_e::POSITION_MODE);
  if (ret != FSA::ret_e::SUCCESS)
    printf("FSA(%s): Enable Control failed with code: %d\n", ip,
           static_cast<int>(ret));

  ret = fsa.SetPIDParams(0.1, 0.01, 0.0001);
  if (ret != FSA::ret_e::SUCCESS)
    printf("FSA(%s): Set PID Params failed with code: %d\n", ip,
           static_cast<int>(ret));

  FSA::pid_param_t rx_pid_param{};
  ret = fsa.GetPIDParams(rx_pid_param);
  if (ret != FSA::ret_e::SUCCESS)
    printf("FSA(%s): Get PID Params failed with code: %d\n", ip,
           static_cast<int>(ret));
  else
    printf("FSA(%s): pos_kp: %.4lf, vel_kp: %.4lf, vel_ki: %.4lf\n", ip,
           rx_pid_param.pos_kp, rx_pid_param.vel_kp, rx_pid_param.vel_ki);

  FSA::pvctte_t rx_pvctte{};
  ret = fsa.GetPVCTTe(rx_pvctte);
  if (ret != FSA::ret_e::SUCCESS)
    printf("FSA(%s): Get PVCT failed with code: %d\n", ip,
           static_cast<int>(ret));

  for (size_t i = 0; i < 1000; i++) {
    rx_pvctte.pos += 0.001;
    ret = fsa.SetPosition(rx_pvctte.pos, 0, 0);
    if (ret != FSA::ret_e::SUCCESS)
      printf("FSA(%s): Set Position failed with code: %d\n", ip,
             static_cast<int>(ret));

    usleep(2000);
  }

  for (size_t i = 1000; i > 0; i--) {
    rx_pvctte.pos -= 0.001;
    ret = fsa.SetPosition(rx_pvctte.pos, 0, 0);
    if (ret != FSA::ret_e::SUCCESS)
      printf("FSA(%s): Set Position failed with code: %d\n", ip,
             static_cast<int>(ret));

    usleep(2000);
  }

  ret = fsa.DisableControl();
  if (ret != FSA::ret_e::SUCCESS)
    printf("FSA(%s): Disable Control failed with code: %d\n", ip,
           static_cast<int>(ret));

  return 0;
}

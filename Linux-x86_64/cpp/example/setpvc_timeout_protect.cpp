#include "fsav2.h"

#include "unistd.h"

#include <chrono>
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

  FSA::setpvc_timeout_protect_config_t tx_setpvc_timeout_protect_config{
      .enable = 1,
      .timeout_ms = 100,
      .protect_control_mode = FSA::ctrl_mode_e::POSITION_MODE,
      .is_close_back_last_control_mode = 1,
      .is_ignore_set_control_mode = 1};

  ret = fsa.ClearSetPVCTimeOutProtect(0);
  if (ret != FSA::ret_e::SUCCESS)
    printf("FSA(%s): Clear SetPVC TimeOut Protect failed with code: %d\n", ip,
           static_cast<int>(ret));

  ret = fsa.EnableSetPVCTimeOutProtect(tx_setpvc_timeout_protect_config);
  if (ret != FSA::ret_e::SUCCESS)
    printf("FSA(%s): Enable SetPVC TimeOut Protect failed with code: %d\n", ip,
           static_cast<int>(ret));

  fsa.EnableControl(FSA::ctrl_mode_e::TORQUE_MODE);

  while (true) {
    auto start = std::chrono::steady_clock::now();
    ret = fsa.SetTorque(2);
    if (ret != FSA::ret_e::SUCCESS)
      printf("FSA(%s): Set Torque failed with code: %d\n", ip,
             static_cast<int>(ret));
    auto end = std::chrono::steady_clock::now();

    usleep(2000);

    printf("FSA(%s): elapsed time: %ld us\n", ip,
           std::chrono::duration_cast<std::chrono::microseconds>(end - start)
               .count());
  }

  return 0;
}

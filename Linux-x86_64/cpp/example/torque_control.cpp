#include "fsav2.h"

#include <unistd.h>

#include <cstdio>

using namespace AC2;

int
main() {
  FSA         fsa;
  const char *ip = "192.168.137.101";

  FSA::ret_e ret = fsa.Init(ip, FSA::net_recv_mode_e::YIELD_WAIT);
  if (ret != FSA::ret_e::SUCCESS) {
    printf("FSA(%s): init failed with code: %d\n", ip, static_cast<int>(ret));
    return -1;
  }

  ret = fsa.EnableControl(FSA::ctrl_mode_e::TORQUE_MODE);
  if (ret != FSA::ret_e::SUCCESS)
    printf("FSA(%s): Enable Control failed with code: %d\n", ip, static_cast<int>(ret));

  double tor = 0;
  for (size_t i = 0; i < 30; i++) {
    tor += 0.1;
    ret = fsa.SetTorque(tor);
    if (ret != FSA::ret_e::SUCCESS)
      printf("FSA(%s): Set Torque failed with code: %d\n", ip, static_cast<int>(ret));

    usleep(200000);
  }

  for (size_t i = 30; i > 0; i--) {
    tor -= 0.1;
    ret = fsa.SetTorque(tor);
    if (ret != FSA::ret_e::SUCCESS)
      printf("FSA(%s): Set Torque failed with code: %d\n", ip, static_cast<int>(ret));

    usleep(200000);
  }

  ret = fsa.DisableControl();
  if (ret != FSA::ret_e::SUCCESS)
    printf("FSA(%s): Disable Control failed with code: %d\n", ip, static_cast<int>(ret));

  return 0;
}

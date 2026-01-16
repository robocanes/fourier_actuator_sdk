#include <stdio.h>
#include <thread>

#include "fsav3.h"
using namespace AC3;

int main() {
    printf("Hello, FSA!\n");
    FSA        fsa;
    FSA::ret_e ret;
    ret = fsa.Init( "192.168.137.101" );
    if ( ret != FSA::ret_e::SUCCESS ) {
       printf( "FSA Init failed, ret: %d\n", ( int )ret );
       return 0;
    }
    printf( "FSA initialized\n" );
    
    ret = fsa.EnableControl( FSA::ctrl_mode_e::POSITION_MODE, 1000, 0 );
    if ( ret != FSA::ret_e::SUCCESS ) {
        printf( "FSA Enable Control failed with code: %d\n", ( int )ret );
    }

    ret = fsa.SetPIDParams( 0.6, 0.1, 0.1 , 1000 , 0 );
    if ( ret != FSA::ret_e::SUCCESS ) {
        printf( "FSA Set PID Params failed with code: %d\n", ( int )ret );
    }

    FSA::pid_param_t rx_pid_param{};
    ret = fsa.GetPIDParams( rx_pid_param, 1000, 0 );
    if ( ret != FSA::ret_e::SUCCESS ) {
        printf( "FSA Get PID Params failed with code: %d\n", ( int )ret );
    }
    else {
        printf( "FSA: pos_kp: %.4lf, vel_kp: %.4lf, vel_ki: %.4lf\n",
                rx_pid_param.pos_kp, rx_pid_param.vel_kp, rx_pid_param.vel_ki );
    }

    FSA::pvctte_t rx_PVCTTe;
    ret = fsa.GetPVCTTe( rx_PVCTTe, 1000, 0 );
    if ( ret != FSA::ret_e::SUCCESS ) {
        printf( "GetPVCTTe failed, ret: %d\n", ( int )ret );
    }
    
    for (size_t i = 0; i < 1000; i++) {
        rx_PVCTTe.pos += 0.001;
        ret = fsa.SetPosition( rx_PVCTTe.pos, 0, 0 );
        if (ret != FSA::ret_e::SUCCESS)
            printf( "FSA Set Position failed with code: %d\n", ( int )ret );
        std::this_thread::sleep_for( std::chrono::microseconds( 2000 ) );
    }

    for (size_t i = 1000; i > 0; i--) {
        rx_PVCTTe.pos -= 0.001;
        ret = fsa.SetPosition( rx_PVCTTe.pos, 0, 0 );
        if (ret != FSA::ret_e::SUCCESS)
            printf( "FSA Set Position failed with code: %d\n", ( int )ret );
        std::this_thread::sleep_for( std::chrono::microseconds( 2000 ) );
    }

    ret = fsa.DisableControl();
    if (ret != FSA::ret_e::SUCCESS) {
        printf( "FSA Disable Control failed with code: %d\n", ( int )ret );
    }

    return 0;
}
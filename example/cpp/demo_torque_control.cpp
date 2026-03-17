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
    
    ret = fsa.EnableControl( FSA::ctrl_mode_e::TORQUE_MODE, 1000, 0 );
    if ( ret != FSA::ret_e::SUCCESS ) {
        printf( "FSA Enable Control failed with code: %d\n", ( int )ret );
    }

    double tor = 0;
    for (size_t i = 0; i < 30; i++) {
        tor += 0.1;
        ret = fsa.SetTorque(tor);
        if ( ret != FSA::ret_e::SUCCESS ) {
            printf("FSA Set Torque failed with code: %d\n", ( int )ret );
        }
        std::this_thread::sleep_for( std::chrono::microseconds( 200000 ) );
    }

    for (size_t i = 30; i > 0; i--) {
        tor -= 0.1;
        ret = fsa.SetTorque(tor);
        if ( ret != FSA::ret_e::SUCCESS ) {
        printf("FSA Set Torque failed with code: %d\n", ( int )ret );
        }
        std::this_thread::sleep_for( std::chrono::microseconds( 200000 ) );
    }

    ret = fsa.DisableControl();
    if ( ret != FSA::ret_e::SUCCESS ) {
        printf("FSA Disable Control failed with code: %d\n", ( int )ret );
    }

    return 0;
}
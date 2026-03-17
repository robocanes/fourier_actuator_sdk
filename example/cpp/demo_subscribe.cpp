#include <chrono>
#include <csignal>
#include <cstdio>
#include <thread>

#include "fsav3.h"
#include <cstring>

volatile sig_atomic_t stop_flag = 0;

void signal_handler( int sig ) {
    if ( sig == SIGINT ) {
        stop_flag = 1;
        printf( "\nReceived SIGINT, terminating...\n" );
    }
}

using namespace AC3;

int main() {
    signal( SIGINT, signal_handler );
    printf( "Hello, FSA!\n" );
    FSA        fsa;
    FSA::ret_e ret;
    ret = fsa.Init( "192.168.137.101" );
    if ( ret != FSA::ret_e::SUCCESS ) {
        printf( "FSA Init failed, ret: %d\n", ( int )ret );
        return 0;
    }
    printf( "FSA initialized\n" );

    FSA::subs_config_t subs_config;
    ret = fsa.EnableSubscribe( subs_config, 1000, 0 );
    if ( ret != FSA::ret_e::SUCCESS ) {
        printf( "EnableSubscribe failed, ret: %d\n", ( int )ret );
        return 0;
    }

    FSA::subs_data_t subs_data;
    memset( &subs_data, 0, sizeof( subs_data ) );
    while ( !stop_flag ) 
    {
        ret = fsa.GetSubsData( subs_data );
        if ( ret != FSA::ret_e::SUCCESS ) {
            printf( "GetSubsData failed, ret: %d\n", ( int )ret );
        }
        else {
            printf( "cnt: %lu, p: %f, v: %f, c: %f, t: %f, te: %f\n",
                    subs_data.cnt,
                    subs_data.pvct.pos,
                    subs_data.pvct.vel,
                    subs_data.pvct.cur,
                    subs_data.pvct.tor,
                    subs_data.pvct.tor_e );
            printf( "mos: %f, coil: %f, vbus: %f\n", subs_data.temp_vbus.mos, subs_data.temp_vbus.coil, subs_data.temp_vbus.vbus );
            for ( int i = 0; i < 8; ++i ) {
                printf( "error[%d]: %u\n", i, subs_data.error[ i ] );
            }
        }

        FSA::err_code_t err_code;
        ret = fsa.GetErrCode( err_code, 1000, 0 );
        if ( ret != FSA::ret_e::SUCCESS ) {
            printf( "GetErrCode failed, ret: %d\n", ( int )ret );
        }
        // print as hex
        printf( "err_code[0]: 0x%X\n", err_code.arr[ 0 ] );
        printf( "err_code[1]: 0x%X\n", err_code.arr[ 1 ] );
        printf( "err_code[2]: 0x%X\n", err_code.arr[ 2 ] );
        printf( "err_code[3]: 0x%X\n", err_code.arr[ 3 ] );
        printf( "err_code[4]: 0x%X\n", err_code.arr[ 4 ] );
        printf( "err_code[5]: 0x%X\n", err_code.arr[ 5 ] );
        printf( "err_code[6]: 0x%X\n", err_code.arr[ 6 ] );
        printf( "err_code[7]: 0x%X\n", err_code.arr[ 7 ] );
        FSA::parsed_err_code_t parsed_err_codes;
        ret = FSA::ParseErrCode( err_code, parsed_err_codes );
        if ( ret != FSA::ret_e::SUCCESS ) {
            printf( "ParseErrCode failed, ret: %d\n", ( int )ret );
        }
        printf( "parsed_err_codes size: %zu\n", parsed_err_codes.vec.size() );
        for ( size_t i = 0; i < parsed_err_codes.vec.size(); i++ ) {
            printf( "err_level: %d, err_u32_index: %d, err_bit_index: %d, parsed_code: 0x%X, str_for_log: %s\n",
                    parsed_err_codes.vec[ i ].err_level,
                    parsed_err_codes.vec[ i ].err_u32_index,
                    parsed_err_codes.vec[ i ].err_bit_index,
                    parsed_err_codes.vec[ i ].parsed_code,
                    parsed_err_codes.vec[ i ].str_for_log );
        }

        std::this_thread::sleep_for( std::chrono::milliseconds( 1 ) );
    }

    subs_config.enable = 0;

    ret = fsa.EnableSubscribe( subs_config );
    if ( ret != FSA::ret_e::SUCCESS ) {
        printf( "DisableSubscribe failed, ret: %d\n", ( int )ret );
    }
    else {
        printf( "Subscription disabled successfully\n" );
    }

    return 0;
}

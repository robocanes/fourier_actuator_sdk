#include <stdio.h>
#include <thread>

#include "fsav3.h"
using namespace AC3;

int main() {
    printf( "Hello, FSA!\n" );
    FSA        fsa;
    FSA::ret_e ret;
    ret = fsa.Init( "192.168.137.101" );
    if ( ret != FSA::ret_e::SUCCESS ) {
        printf( "FSA Init failed, ret: %d\n", ( int )ret );
        return 0;
    }
    printf( "FSA initialized\n" );

    while ( 1 ) {
        FSA::pvctte_t rx_PVCTTe;
        ret = fsa.GetPVCTTe( rx_PVCTTe, 1000, 0 );
        if ( ret != FSA::ret_e::SUCCESS ) {
            printf( "GetPVCTTe failed, ret: %d\n", ( int )ret );
        }
        printf( "p: %f, v: %f, c: %f, t: %f, te: %f\n", rx_PVCTTe.pos, rx_PVCTTe.vel, rx_PVCTTe.cur, rx_PVCTTe.tor, rx_PVCTTe.tor_e );

        FSA::temp_vbus_t rx_temp_vbus;
        ret = fsa.GetTempVbus( rx_temp_vbus, 1000, 0 );
        if ( ret != FSA::ret_e::SUCCESS ) {
            printf( "GetTempVbus failed, ret: %d\n", ( int )ret );
        }
        printf( "mos: %f, coil: %f, vbus: %f\n", rx_temp_vbus.mos, rx_temp_vbus.coil, rx_temp_vbus.vbus );

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

        FSA::pid_param_t rx_pid_param;
        ret = fsa.GetPIDParams( rx_pid_param, 1000, 0 );
        if ( ret != FSA::ret_e::SUCCESS ) {
            printf( "FSA Get PID Params failed with code: %d\n", ( int )ret );
        }
        else {
            printf( "FSA: pos_kp: %.4lf, vel_kp: %.4lf, vel_ki: %.4lf\n",
                rx_pid_param.pos_kp, rx_pid_param.vel_kp, rx_pid_param.vel_ki );
        }

        FSA::pd_param_t rx_pd_param;
        ret = fsa.GetPDParams( rx_pd_param, 1000, 0 );
        if ( ret != FSA::ret_e::SUCCESS ) {
            printf( "FSA Get PD Params failed with code: %d\n", ( int )ret );
        }
        else {
            printf( "FSA: pd_kp: %.4lf, pd_kd: %.4lf\n",
                    rx_pd_param.pd_kp, rx_pd_param.pd_kd );
        }

        FSA::type_subversion_t type_subversion;
        ret = fsa.GetTypeSubversion( type_subversion, 1000, 0 );
        if ( ret != FSA::ret_e::SUCCESS ) {
            printf( "GetTypeSubversion failed, ret: %d\n", ( int )ret );
        }
        printf( "type: %s, sub_version: %s\n", type_subversion.type.data(), type_subversion.sub_version.data() );

        FSA::comm_req_get_t comm_req_get;
        FSA::comm_resp_get_t comm_resp_get;
        ret = fsa.GetCommConfig( comm_req_get, comm_resp_get, 1000, 0 );
        if ( ret != FSA::ret_e::SUCCESS ) {
            printf( "GetCommConfig failed, ret: %d\n", ( int )ret );
        }
        printf( "name: %s, type: %s, mcu_fw_version: %s, mac_address: %s, uid: %s, sn: %s, PCBA_sn: %s, gearbox_sn: %s, static_IP: %s, gateway: %s, subnet_mask: %s, dns_1: %s, dns_2: %s, DHCP_enable: %d\n", 
                comm_resp_get.name.data(), 
                comm_resp_get.type.data(), 
                comm_resp_get.mcu_fw_version.data(), 
                comm_resp_get.mac_address.data(), 
                comm_resp_get.uid.data(), 
                comm_resp_get.sn.data(),
                comm_resp_get.PCBA_sn.data(),
                comm_resp_get.gearbox_sn.data(),
                comm_resp_get.static_IP.data(),
                comm_resp_get.gateway.data(),
                comm_resp_get.subnet_mask.data(),
                comm_resp_get.dns_1.data(),
                comm_resp_get.dns_2.data(),
                comm_resp_get.DHCP_enable
            );
        
        std::this_thread::sleep_for( std::chrono::milliseconds( 1000 ) );
    }

    return 0;
}

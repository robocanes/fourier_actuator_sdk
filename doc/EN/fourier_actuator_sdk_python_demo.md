# Actuator Python Script Example Documentation

## demo\_lookup.py

**Code Description:**

This script is mainly used to demonstrate how to get the basic properties of the actuator.

This script performs the following operations: `demo_lookup.py`

1.  Use the `broadcast_func` function to discover all Fourier self-developed devices on the network.
    
2.  Use the `get_comm_root` function to retrieve the basic properties of each detected Fourier self-developed device.
    
3.  Display the basic properties of the last Fourier self-developed device in the terminal.
    

**Usage:**

To run this script, follow these steps:`demo_lookup.py`

1.  Make sure you have set up the Python environment and installed the FSA SDK as described in the Quick Start Guide.
    
2.  Connect to the FSA actuator.
    
3.  Open a terminal and navigate to the directory containing`demo_lookup.py`
    
4.  Run the script using the following command:
    
    ```python
    python demo_lookup.py
    ```
    
5.  Running results (actual execution may differ from the demo, such as IP information):
    

```plaintext
len3@len3-System-Product-Name:~/wiki-fsa/v2/example$ python3 ./demo_lookup.py 
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v1
Log Already Existed ./log/2024/10/
[2024.10.30 09:24:53.652.378]  Info:    FSA start listening for broadcast...
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v2
Log Already Existed ./log/2024/10/
[2024.10.30 09:24:53.654.011]  Info:    FSA start listening for broadcast...
[2024.10.30 09:24:53.654.051]  Info:    FSA start listening for broadcast...


[2024.10.30 09:24:53.657.026]  Info:    Received from ('192.168.137.51', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA-0","serial_number":"A4D32BE0F908","driver_version":"0.2.8.35","firmware_version":"0.3.9.9","connect_mode":"ETH","mac_address":"08:F9:E0:2B:D3:A7","ip_address":"192.168.137.51","IP":"192.168.137.51"}


found servers
['192.168.137.51']
lookup Finished! 

[2024.10.30 09:24:56.658.454]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/", "property": ""}
[2024.10.30 09:24:56.661.219]  Info:    Received from ('192.168.137.51', 2334):{"status":"OK","reqTarget":"/","property":"","type":"Actuator","model":"","name":"FSA-0","serial_number":"A4D32BE0F908","driver_version":"0.2.8.35","firmware_version":"0.3.9.9","connect_mode":"ETH","mac_address":"08:F9:E0:2B:D3:A7","ip_address":"192.168.137.51","IP":"192.168.137.51","DHCP_enable":false,"SSID":"FSA","password":"fftai2015","static_IP":[192,168,137,51],"gateway":[192,168,137,1],"subnet_mask":[255,255,255,0],"dns_1":[114,114,114,114],"dns_2":[8,8,8,8],"OTAstatus":"HTTP_UPDATE_IDLE","OTADriverstatus":"HTTP_UPDATE_DRIVER_IDLE"}
The communication root is:  {'status': 'OK', 'reqTarget': '/', 'property': '', 'type': 'Actuator', 'model': '', 'name': 'FSA-0', 'serial_number': 'A4D32BE0F908', 'driver_version': '0.2.8.35', 'firmware_version': '0.3.9.9', 'connect_mode': 'ETH', 'mac_address': '08:F9:E0:2B:D3:A7', 'ip_address': '192.168.137.51', 'IP': '192.168.137.51', 'DHCP_enable': False, 'SSID': 'FSA', 'password': 'fftai2015', 'static_IP': [192, 168, 137, 51], 'gateway': [192, 168, 137, 1], 'subnet_mask': [255, 255, 255, 0], 'dns_1': [114, 114, 114, 114], 'dns_2': [8, 8, 8, 8], 'OTAstatus': 'HTTP_UPDATE_IDLE', 'OTADriverstatus': 'HTTP_UPDATE_DRIVER_IDLE'}

```

**Common Issues:**

If you encounter any issues when running this script, consider the following:

1.  Make sure you use a compatible Python version as recommended in the Quick Start Guide.
    
2.  Verify that your network configuration is correct and the FSA actuator is accessible.
    
3.  Check if the actuator has any existing faults that need to be cleared.
    
## demo\_comm\_driver\_firmware\_version\_get.py

**Code Description:**

This script is mainly used to demonstrate how to get the driver firmware version of the actuator and communication firmware version.

This script performs the following operations: `demo_comm_driver_firmware_version_get.py`

1.  Use the `broadcast_func_with_filter` function to discover all Fourier self-developed actuators on the network.
    
2.  Use the `get_comm_driver_version` and `get_comm_firmware_version` functions to retrieve the communication version and driver version of each detected Fourier self-developed device.
    
3.  Display the communication version and driver version of each detected Fourier self-developed device in the terminal.
    
4.  Pause for 1 second.
        

**Usage:**

To run this script, follow these steps:`demo_comm_driver_firmware_version_get.py`

1.  Make sure you have set up the Python environment and installed the FSA SDK as described in the Quick Start Guide.
    
2.  Connect to the FSA actuator.
    
3.  Open a terminal and navigate to the directory containing`demo_comm_driver_firmware_version_get.py`
    
4.  Run the script using the following command:
    
    ```python
    python demo_comm_driver_firmware_version_get.py
    ```
    
5.  Running results (actual execution may differ from the demo, such as IP information):
    

```python
len3@len3-System-Product-Name:~/wiki-fsa/v2/example$ python3 ./demo_comm_driver_firmware_version_get.py 
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v1
Log Already Existed ./log/2024/10/
[2024.10.30 10:31:21.816.769]  Info:    FSA start listening for broadcast...
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v2
Log Already Existed ./log/2024/10/
[2024.10.30 10:31:21.817.742]  Info:    FSA start listening for broadcast...
[2024.10.30 10:31:21.817.772]  Info:    FSA start listening for broadcast...


[2024.10.30 10:31:21.820.757]  Info:    Received from ('192.168.137.51', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA-0","serial_number":"A4D32BE0F908","driver_version":"0.2.8.35","firmware_version":"0.3.9.9","connect_mode":"ETH","mac_address":"08:F9:E0:2B:D3:A7","ip_address":"192.168.137.51","IP":"192.168.137.51"}


found servers
['192.168.137.51']
lookup Finished! 

[2024.10.30 10:31:24.822.164]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/", "property": ""}
[2024.10.30 10:31:24.825.019]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/", "property": ""}
{"driver_version":"0.2.8.35"}
{"firmware_version":"0.3.9.9"}

```

**Common Issues:**

If you encounter any issues when running this script, consider the following:

1.  Make sure you use a compatible Python version as recommended in the Quick Start Guide.
    
2.  Verify that your network configuration is correct and the FSA actuator is accessible.
    
3.  Check if the actuator has any existing faults that need to be cleared.
    
## demo\_comm\_config\_get.py

**Code Description:**

This script is mainly used to demonstrate how to get the actuator's config properties.

This script performs the following operations: `demo_comm_config_get.py`

1.  Use the `broadcast_func_with_filter` function to discover FSA actuators on the network.
    
2.  Use the `get_comm_config` function to retrieve and print the communication configuration of each detected FSA actuator.
        

**Configuration Parameters:**

Communication configuration parameters include:

*   **"name" (str):** Device name.
    
*   **"DHCP\_enable" (bool):** Enable DHCP (True) or use static IP (False).
    
*   **"SSID" (str):** Network SSID.
    
*   **"password" (str):** Network password.
    
*   **"static\_IP" (str):** Static IP address (if DHCP is disabled).
    
*   **"gateway" (str):** Gateway address (if DHCP is disabled).
    
*   **"subnet\_mask" (str):** Subnet mask (if DHCP is disabled).
    
*   **"dns\_1" (str):** Primary DNS server (if DHCP is disabled).
    
*   **"dns\_2" (str):** Secondary DNS server (if DHCP is disabled).
    

**Usage:**

To run this script, follow these steps:`demo_comm_config_get.py`

1.  Make sure you have set up the Python environment and installed the FSA SDK as described in the Quick Start Guide.
    
2.  Open a terminal and navigate to the directory containing`demo_comm_config_get.py`
    
3.  Run the script using the following command:
    
    ```plaintext
    python demo_comm_config_get.py
    ```
    
4.  Running results (actual execution may differ from the demo, such as IP information):
    

```python
(base) len3@len3-System-Product-Name:~/wiki-fsa/v2/example$ python3 ./demo_comm_config_get.py 
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v1
Log Already Existed ./log/2024/10/
[2024.10.30 10:59:21.728.891]  Info:    FSA start listening for broadcast...
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v2
Log Already Existed ./log/2024/10/
[2024.10.30 10:59:21.729.890]  Info:    FSA start listening for broadcast...
[2024.10.30 10:59:21.729.921]  Info:    FSA start listening for broadcast...


[2024.10.30 10:59:21.731.356]  Info:    Received from ('192.168.137.101', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA-0","serial_number":"F0BE83CD31E8","driver_version":"0.2.9.1","firmware_version":"0.3.9.9","connect_mode":"ETH","mac_address":"E8:31:CD:83:BE:F3","ip_address":"192.168.137.101","IP":"192.168.137.101"}


found servers
['192.168.137.101']
lookup Finished! 

[2024.10.30 10:59:24.731.949]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/config", "property": ""}
[2024.10.30 10:59:24.733.415]  Info:    Received from ('192.168.137.101', 2334):{"status":"OK","reqTarget":"/config","property":"","DHCP_enable":false,"SSID":"fftai-6","password":"fftai2015","name":"FSA-0","static_IP":[192,168,137,101],"gateway":[192,168,137,1],"subnet_mask":[255,255,255,0],"dns_1":[114,114,114,114],"dns_2":[8,8,8,8]}

```

**Common Issues:**

If you encounter any issues when running this script, consider the following:

1.  Make sure you use a compatible Python version as recommended in the Quick Start Guide.
    
2.  Verify that your network configuration is correct and the FSA actuator is accessible.
    
## demo\_comm\_config\_set.py

**Code Description:**

This script is mainly used to demonstrate how to set the actuator's config properties.

This script performs the following operations: `demo_comm_config_set.py`

1.  Use the `broadcast_func_with_filter` function to discover FSA actuators on the network and filter by actuator type.
    
2.  Use the `set_comm_config` function to set new communication configuration for each Actuator. The new configuration includes parameters such as `name`, `DHCP_enable`, `SSID`, `password`, `static_IP`, `gateway`, `subnet_mask`, `dns_1`, `dns_2`.
    
3.  Wait for one second.
    
4.  Use the `get_comm_config` function to get the new communication configuration of each Actuator.
    
5.  Use the `reboot` function to restart each Actuator to apply the new communication configuration.
        

**Configuration Parameters:**

Communication configuration parameters include:

*   **"name" (str):** Device name.
    
*   **"DHCP\_enable" (bool):** Enable DHCP (True) or use static IP (False).
    
*   **"SSID" (str):** Network SSID.
    
*   **"password" (str):** Network password.
    
*   **"static\_IP" (str):** Static IP address (if DHCP is disabled).
    
*   **"gateway" (str):** Gateway address (if DHCP is disabled).
    
*   **"subnet\_mask" (str):** Subnet mask (if DHCP is disabled).
    
*   **"dns\_1" (str):** Primary DNS server (if DHCP is disabled).
    
*   **"dns\_2" (str):** Secondary DNS server (if DHCP is disabled).
    

**Usage:**

To run this script, follow these steps:`demo_comm_config_set.py`

1.  Make sure you have set up the Python environment and installed the FSA SDK as described in the Quick Start Guide.
    
2.  Open a terminal and navigate to the directory containing`demo_comm_config_set.py`
    
3.  Run the script using the following command:
    
    ```plaintext
    python demo_comm_config_set.py
    
    ```
    
4.  Running results (actual execution may differ from the demo, such as IP information):
    

```python
len3@len3-System-Product-Name:~/wiki-fsa/v2/example$ python3 ./demo_comm_config_set.py 
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v1
Log Already Existed ./log/2024/10/
[2024.10.30 11:43:08.337.742]  Info:    FSA start listening for broadcast...
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v2
Log Already Existed ./log/2024/10/
[2024.10.30 11:43:08.338.789]  Info:    FSA start listening for broadcast...
[2024.10.30 11:43:08.338.823]  Info:    FSA start listening for broadcast...


[2024.10.30 11:43:08.340.208]  Info:    Received from ('192.168.137.101', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA-0","serial_number":"F0BE83CD31E8","driver_version":"0.2.9.1","firmware_version":"0.3.9.9","connect_mode":"ETH","mac_address":"E8:31:CD:83:BE:F3","ip_address":"192.168.137.101","IP":"192.168.137.101"}


found servers
['192.168.137.101']
lookup Finished! 

[2024.10.30 11:43:11.341.567]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/config", "property": "", "name": "FSA-0", "DHCP_enable": false, "SSID": "fftai-6", "password": "fftai2015", "static_IP": [192, 168, 137, 101], "gateway": [192, 168, 137, 1], "subnet_mask": [255, 255, 255, 0], "dns_1": [114, 114, 114, 114], "dns_2": [8, 8, 8, 8]}
[2024.10.30 11:43:11.543.882]  Info:    Received from ('192.168.137.101', 2334):{"status":"OK","reqTarget":"/config","property":""}


[2024.10.30 11:43:12.544.228]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/config", "property": ""}
[2024.10.30 11:43:12.545.935]  Info:    Received from ('192.168.137.101', 2334):{"status":"OK","reqTarget":"/config","property":"","DHCP_enable":false,"SSID":"fftai-6","password":"fftai2015","name":"FSA-0","static_IP":[192,168,137,101],"gateway":[192,168,137,1],"subnet_mask":[255,255,255,0],"dns_1":[114,114,114,114],"dns_2":[8,8,8,8]}


[2024.10.30 11:43:12.546.139]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/reboot", "property": ""}
[2024.10.30 11:43:12.547.780]  Info:    Received from ('192.168.137.101', 2333):{"status":"OK","reqTarget":"/reboot","property":""}

```

**Common Issues:**

If you encounter any issues when running this script, consider the following:

1.  Make sure you use a compatible Python version as recommended in the Quick Start Guide.
    
2.  Verify that your network configuration is correct and the FSA actuator is accessible.
    
## demo\_set\_subscribe.py

**Code Description:**

This script is mainly used to demonstrate how to selectively send the actuator's position, velocity, current, and torque data to a specified port.

This script performs the following operations: `demo_set_subscribe.py`

1.  Use the `broadcast_func_with_filter` function to discover FSA actuators on the network and filter by actuator type.
    
2.  Use the `set_subscribe` function to set subscribe configuration parameters for each Actuator.
    
3.  Check if sending is enabled. If sending is enabled, loop to receive position, velocity, current, torque and other data information sent by the actuator.
        

**Usage:**

To run this script, follow these steps:`demo_set_subscribe.py`

1.  Make sure you have set up the Python environment and installed the FSA SDK as described in the Quick Start Guide.
    
2.  Open a terminal and navigate to the directory containing`demo_set_subscribe.py`
    
3.  Run the script using the following command:
    
    ```plaintext
    python demo_set_subscribe.py
    ```
    
4.  Running results (actual execution may differ from the demo, such as IP information):
    

```python
[2024.12.30 20:53:50.084.473]  Info:    FSA start listening for broadcast...
Socket is bound to port: 53063
[2024.12.30 20:53:50.084.473]  Info:    FSA start listening for broadcast...


[2024.12.30 20:53:50.086.441]  Info:    Received from ('192.168.137.101', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA","serial_number":"F0BE83CD31E8","driver_version":"0.2.10.11","firmware_version":"0.3.12.17","connect_mode":"ETH","mac_address":"E8:31:CD:83:BE:F3","ip_address":"192.168.137.101","IP":"192.168.137.101"}


found servers
['192.168.137.101']
lookup Finished! 

[2024.12.30 20:53:53.096.084]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/", "property": ""}
[2024.12.30 20:53:53.098.371]  Info:    Send JSON Obj: {"port": 53063, "enable": 1, "position": 1, "velocity": 1, "current": 1, "torque": 1, "error": 1, "error_ext2": 1, "error_ext3": 1, "error_ext4": 1, "error_ext5": 1, "error_ext6": 1, "error_ext7": 1, "error_ext8": 1, "method": "SET", "reqTarget": "/subscribe", "property": ""}
[2024.12.30 20:53:53.100.387]  Info:    Received from ('192.168.137.101', 2334):{"status":"OK","reqTarget":"/subscribe","property":""}
: Server received from ('192.168.137.101', 2336):b'\x02\xba1\xbbS\x03\xbeu\xac\x93\x04\x80\x00\x00\x00\x05\xbd\x8a\x1c0\x06\x00\x00\x00\x00\x07\x00\x00\x00\x10\x08\x00\x00\x00\x01\t\x00\x00\x00\x00\n\x00\x00\x00\x00\x0b\x00\x00\x00\x00\x0c\x00\x00\x00\x00\r\x00\x00\x00\x00\x0e\x00\x00\x00\x00'
65
index = 0x02, position = -0.000678
index = 0x03, velocity = -0.239916
index = 0x04, current = -0.000000
index = 0x05, torque = -0.067437
index = 0x06, cnt = 0
index = 0x07, error = 16
index = 0x08, error_ext2 = 1
index = 0x09, error_ext3 = 0
index = 0x0A, error_ext4 = 0
index = 0x0B, error_ext5 = 0
index = 0x0C, error_ext6 = 0
index = 0x0D, error_ext7 = 0
index = 0x0E, error_ext8 = 0
: Server received from ('192.168.137.101', 2336):b'\x02\xba1\xbbS\x03\xbeu\xac\x93\x04\x80\x00\x00\x00\x05\xbd\x8a\x1c0\x06\x00\x00\x00\x01\x07\x00\x00\x00\x10\x08\x00\x00\x00\x01\t\x00\x00\x00\x00\n\x00\x00\x00\x00\x0b\x00\x00\x00\x00\x0c\x00\x00\x00\x00\r\x00\x00\x00\x00\x0e\x00\x00\x00\x00'
65
index = 0x02, position = -0.000678
index = 0x03, velocity = -0.239916
index = 0x04, current = -0.000000
index = 0x05, torque = -0.067437
index = 0x06, cnt = 1
index = 0x07, error = 16
index = 0x08, error_ext2 = 1
index = 0x09, error_ext3 = 0
index = 0x0A, error_ext4 = 0
index = 0x0B, error_ext5 = 0
index = 0x0C, error_ext6 = 0
index = 0x0D, error_ext7 = 0
index = 0x0E, error_ext8 = 0
: Server received from ('192.168.137.101', 2336):b'\x02\xba\x10\xbaw\x03>\xb0e`\x04\x80\x00\x00\x00\x05\xbd\x18\xd1\n\x06\x00\x00\x00\x02\x07\x00\x00\x00\x10\x08\x00\x00\x00\x01\t\x00\x00\x00\x00\n\x00\x00\x00\x00\x0b\x00\x00\x00\x00\x0c\x00\x00\x00\x00\r\x00\x00\x00\x00\x0e\x00\x00\x00\x00'
65
index = 0x02, position = -0.000552
index = 0x03, velocity = 0.344523
index = 0x04, current = -0.000000
index = 0x05, torque = -0.037309
index = 0x06, cnt = 2
index = 0x07, error = 16
index = 0x08, error_ext2 = 1
index = 0x09, error_ext3 = 0
index = 0x0A, error_ext4 = 0
index = 0x0B, error_ext5 = 0
index = 0x0C, error_ext6 = 0
index = 0x0D, error_ext7 = 0
index = 0x0E, error_ext8 = 0
: Server received from ('192.168.137.101', 2336):b'\x02\xba\x10\xbaw\x03>\xb0e`\x04\x80\x00\x00\x00\x05\xbd\x18\xd1\n\x06\x00\x00\x00\x03\x07\x00\x00\x00\x10\x08\x00\x00\x00\x01\t\x00\x00\x00\x00\n\x00\x00\x00\x00\x0b\x00\x00\x00\x00\x0c\x00\x00\x00\x00\r\x00\x00\x00\x00\x0e\x00\x00\x00\x00'
65
index = 0x02, position = -0.000552
index = 0x03, velocity = 0.344523
index = 0x04, current = -0.000000
index = 0x05, torque = -0.037309
index = 0x06, cnt = 3
index = 0x07, error = 16
index = 0x08, error_ext2 = 1
index = 0x09, error_ext3 = 0
index = 0x0A, error_ext4 = 0
index = 0x0B, error_ext5 = 0
index = 0x0C, error_ext6 = 0
index = 0x0D, error_ext7 = 0
index = 0x0E, error_ext8 = 0
: Server received from ('192.168.137.101', 2336):b'\x02\xbaf\xf7l\x03\xbe\x044\x04\x04\x80\x00\x00\x00\x05<\xd6\x95\x86\x06\x00\x00\x00\x04\x07\x00\x00\x00\x10\x08\x00\x00\x00\x01\t\x00\x00\x00\x00\n\x00\x00\x00\x00\x0b\x00\x00\x00\x00\x0c\x00\x00\x00\x00\r\x00\x00\x00\x00\x0e\x00\x00\x00\x00'
65
index = 0x02, position = -0.000881
index = 0x03, velocity = -0.129105
index = 0x04, current = -0.000000
index = 0x05, torque = 0.026194
index = 0x06, cnt = 4
index = 0x07, error = 16
index = 0x08, error_ext2 = 1
index = 0x09, error_ext3 = 0
index = 0x0A, error_ext4 = 0
index = 0x0B, error_ext5 = 0
index = 0x0C, error_ext6 = 0
index = 0x0D, error_ext7 = 0
index = 0x0E, error_ext8 = 0
: Server received from ('192.168.137.101', 2336):b'\x02\xbaf\xf7l\x03\xbe\x044\x04\x04\x80\x00\x00\x00\x05<\xd6\x95\x86\x06\x00\x00\x00\x05\x07\x00\x00\x00\x10\x08\x00\x00\x00\x01\t\x00\x00\x00\x00\n\x00\x00\x00\x00\x0b\x00\x00\x00\x00\x0c\x00\x00\x00\x00\r\x00\x00\x00\x00\x0e\x00\x00\x00\x00'
65
index = 0x02, position = -0.000881
index = 0x03, velocity = -0.129105
index = 0x04, current = -0.000000
index = 0x05, torque = 0.026194
index = 0x06, cnt = 5
index = 0x07, error = 16
index = 0x08, error_ext2 = 1
index = 0x09, error_ext3 = 0
index = 0x0A, error_ext4 = 0
index = 0x0B, error_ext5 = 0
index = 0x0C, error_ext6 = 0
index = 0x0D, error_ext7 = 0
index = 0x0E, error_ext8 = 0
: Server received from ('192.168.137.101', 2336):b'\x02\xba\x86.U\x03\xbe\xbc\x92\xeb\x04\x80\x00\x00\x00\x05<\xce\x16\xf4\x06\x00\x00\x00\x06\x07\x00\x00\x00\x10\x08\x00\x00\x00\x01\t\x00\x00\x00\x00\n\x00\x00\x00\x00\x0b\x00\x00\x00\x00\x0c\x00\x00\x00\x00\r\x00\x00\x00\x00\x0e\x00\x00\x00\x00'
65
index = 0x02, position = -0.001024
index = 0x03, velocity = -0.368308
index = 0x04, current = -0.000000
index = 0x05, torque = 0.025157
index = 0x06, cnt = 6
index = 0x07, error = 16
index = 0x08, error_ext2 = 1
index = 0x09, error_ext3 = 0
index = 0x0A, error_ext4 = 0
index = 0x0B, error_ext5 = 0
index = 0x0C, error_ext6 = 0
index = 0x0D, error_ext7 = 0
index = 0x0E, error_ext8 = 0
```

**Common Issues:**

If you encounter any issues when running this script, consider the following:

1.  Make sure you use a compatible Python version as recommended in the Quick Start Guide.
    
2.  Verify that your network configuration is correct and the FSA actuator is accessible.
    
## demo\_ota.py

**Code Description:**

This script is mainly used to demonstrate how to perform communication OTA upgrade on the actuator, with the upgrade version being production.

This script performs the following operations: `demo_ota.py`

1.  Use the `broadcast_func_with_filter` function to discover FSA actuators on the network and filter by actuator type.
    
2.  Use the `ota` function to perform communication OTA upgrade on each Actuator, with the upgrade version being production.
        

**Usage:**

To run this script, follow these steps:`demo_ota.py`

1.  Make sure you have set up the Python environment and installed the FSA SDK as described in the Quick Start Guide.
    
2.  Open a terminal and navigate to the directory containing`demo_ota.py`
    
3.  Run the script using the following command:
    

```plaintext
python demo_ota.py

```

**Common Issues:**

If you encounter any issues when running this script, consider the following:

1.  Make sure you use a compatible Python version as recommended in the Quick Start Guide.
    
2.  Verify that your network configuration is correct and the FSA actuator is accessible.
    
## demo\_ota\_test.py

**Code Description:**

This script is mainly used to demonstrate how to perform communication OTA upgrade on the actuator, with the upgrade version being test.

This script performs the following operations: `demo_ota_test.py`

1.  Use the `broadcast_func_with_filter` function to discover FSA actuators on the network and filter by actuator type.
    
2.  Use the `ota_test` function to perform communication OTA upgrade on each Actuator, with the upgrade version being test.
        

**Usage:**

To run this script, follow these steps:`demo_ota_test.py`

1.  Make sure you have set up the Python environment and installed the FSA SDK as described in the Quick Start Guide.
    
2.  Open a terminal and navigate to the directory containing`demo_ota_test.py`
    
3.  Run the script using the following command:
    

```plaintext
python demo_ota_test.py

```

**Common Issues:**

If you encounter any issues when running this script, consider the following:

1.  Make sure you use a compatible Python version as recommended in the Quick Start Guide.
    
2.  Verify that your network configuration is correct and the FSA actuator is accessible.
    
## demo\_ota\_devel.py

**Code Description:**

This script is mainly used to demonstrate how to perform communication OTA upgrade on the actuator, with the upgrade version being development.

This script performs the following operations: `demo_ota_devel.py`

1.  Use the `broadcast_func_with_filter` function to discover FSA actuators on the network and filter by actuator type.
    
2.  Use the `ota_devel` function to perform communication OTA upgrade on each Actuator, with the upgrade version being development.
    

**Usage:**

To run this script, follow these steps:`demo_ota_devel.py`

1.  Make sure you have set up the Python environment and installed the FSA SDK as described in the Quick Start Guide.
    
2.  Open a terminal and navigate to the directory containing`demo_ota_devel.py`
    
3.  Run the script using the following command:
    

```plaintext
python demo_ota_devel.py

```

**Common Issues:**

If you encounter any issues when running this script, consider the following:

1.  Make sure you use a compatible Python version as recommended in the Quick Start Guide.
    
2.  Verify that your network configuration is correct and the FSA actuator is accessible.
    
## demo\_ota\_cloud.py

**Code Description:**

This script is mainly used to demonstrate how to perform communication OTA upgrade on the actuator, with the upgrade version being cloud.

This script performs the following operations: `demo_ota_cloud.py`

1.  Use the `broadcast_func_with_filter` function to discover FSA actuators on the network and filter by actuator type.
    
2.  Use the `ota_cloud` function to perform communication OTA upgrade on each Actuator, with the upgrade version being cloud.
        

**Usage:**

To run this script, follow these steps:`demo_ota_cloud.py`

1.  Make sure you have set up the Python environment and installed the FSA SDK as described in the Quick Start Guide.
    
2.  Open a terminal and navigate to the directory containing`demo_ota_cloud.py`
    
3.  Run the script using the following command:
    

```plaintext
python demo_ota_cloud.py

```

**Common Issues:**

If you encounter any issues when running this script, consider the following:

1.  Make sure you use a compatible Python version as recommended in the Quick Start Guide.
    
2.  Verify that your network configuration is correct and the FSA actuator is accessible.
    
## demo\_ota\_custom.py

**Code Description:**

This script is mainly used to demonstrate how to perform communication OTA upgrade on the actuator, with the upgrade version being custom.

This script performs the following operations: `demo_ota_custom.py`

1.  Use the `broadcast_func_with_filter` function to discover FSA actuators on the network and filter by actuator type.
    
2.  Set `version_str` to the version you want to upgrade to.
    
3.  Use the `ota_custom` function to perform communication OTA upgrade on each Actuator, with the upgrade version being custom.
        

**Usage:**

To run this script, follow these steps:`demo_ota_custom.py`

1.  Make sure you have set up the Python environment and installed the FSA SDK as described in the Quick Start Guide.
    
2.  Open a terminal and navigate to the directory containing`demo_ota_custom.py`
    
3.  Run the script using the following command:
    

```plaintext
python demo_ota_custom.py

```

**Common Issues:**

If you encounter any issues when running this script, consider the following:

1.  Make sure you use a compatible Python version as recommended in the Quick Start Guide.
    
2.  Verify that your network configuration is correct and the FSA actuator is accessible.
    
## demo\_ota\_driver.py

**Code Description:**

This script is mainly used to demonstrate how to perform driver OTA upgrade on the actuator, with the upgrade version being production.

This script performs the following operations: `demo_ota_driver.py`

1.  Use the `broadcast_func_with_filter` function to discover FSA actuators on the network and filter by actuator type.
    
2.  Use the `ota_driver` function to perform driver OTA upgrade on each Actuator, with the upgrade version being production.
        

**Usage:**

To run this script, follow these steps:`demo_ota_driver.py`

1.  Make sure you have set up the Python environment and installed the FSA SDK as described in the Quick Start Guide.
    
2.  Open a terminal and navigate to the directory containing`demo_ota_driver.py`
    
3.  Run the script using the following command:
    

```plaintext
python demo_ota_driver.py

```

**Common Issues:**

If you encounter any issues when running this script, consider the following:

1.  Make sure you use a compatible Python version as recommended in the Quick Start Guide.
    
2.  Verify that your network configuration is correct and the FSA actuator is accessible.
    
## demo\_ota\_driver\_test.py

**Code Description:**

This script is mainly used to demonstrate how to perform driver OTA upgrade on the actuator, with the upgrade version being test.

This script performs the following operations: `demo_ota_driver_test.py`

1.  Use the `broadcast_func_with_filter` function to discover FSA actuators on the network and filter by actuator type.
    
2.  Use the `ota_driver_test` function to perform driver OTA upgrade on each Actuator, with the upgrade version being test.
        

**Usage:**

To run this script, follow these steps:`demo_ota_driver_test.py`

1.  Make sure you have set up the Python environment and installed the FSA SDK as described in the Quick Start Guide.
    
2.  Open a terminal and navigate to the directory containing`demo_ota_driver_test.py`
    
3.  Run the script using the following command:
    

```plaintext
python demo_ota_driver_test.py
```

**Common Issues:**

If you encounter any issues when running this script, consider the following:

1.  Make sure you use a compatible Python version as recommended in the Quick Start Guide.
    
2.  Verify that your network configuration is correct and the FSA actuator is accessible.
    
## demo\_ota\_driver\_devel.py

**Code Description:**

This script is mainly used to demonstrate how to perform driver OTA upgrade on the actuator, with the upgrade version being development.

This script performs the following operations: `demo_ota_driver_devel.py`

1.  Use the `broadcast_func_with_filter` function to discover FSA actuators on the network and filter by actuator type.
    
2.  Use the `ota_driver_devel` function to perform driver OTA upgrade on each Actuator, with the upgrade version being development.
        

**Usage:**

To run this script, follow these steps:`demo_ota_driver_devel.py`

1.  Make sure you have set up the Python environment and installed the FSA SDK as described in the Quick Start Guide.
    
2.  Open a terminal and navigate to the directory containing`demo_ota_driver_devel.py`
    
3.  Run the script using the following command:
    

```plaintext
python demo_ota_driver_devel.py

```

**Common Issues:**

If you encounter any issues when running this script, consider the following:

1.  Make sure you use a compatible Python version as recommended in the Quick Start Guide.
    
2.  Verify that your network configuration is correct and the FSA actuator is accessible.
    
## demo\_ota\_driver\_cloud.py

**Code Description:**

This script is mainly used to demonstrate how to perform driver OTA upgrade on the actuator, with the upgrade version being cloud.

This script performs the following operations: `demo_ota_driver_cloud.py`

1.  Use the `broadcast_func_with_filter` function to discover FSA actuators on the network and filter by actuator type.
    
2.  Use the `ota_driver_cloud` function to perform driver OTA upgrade on each Actuator, with the upgrade version being cloud.
        

**Usage:**

To run this script, follow these steps:`demo_ota_driver_cloud.py`

1.  Make sure you have set up the Python environment and installed the FSA SDK as described in the Quick Start Guide.
    
2.  Open a terminal and navigate to the directory containing`demo_ota_driver_cloud.py`
    
3.  Run the script using the following command:
    

```plaintext
python demo_ota_driver_cloud.py

```

**Common Issues:**

If you encounter any issues when running this script, consider the following:

1.  Make sure you use a compatible Python version as recommended in the Quick Start Guide.
    
2.  Verify that your network configuration is correct and the FSA actuator is accessible.
    
## demo\_ota\_driver\_custom.py

**Code Description:**

This script is mainly used to demonstrate how to perform driver OTA upgrade on the actuator, with the upgrade version being custom.

This script performs the following operations: `demo_ota_driver_custom.py`

1.  Use the `broadcast_func_with_filter` function to discover FSA actuators on the network and filter by actuator type.
    
2.  Set `version_str` to the version you want to upgrade to.
    
3.  Use the `ota_driver_custom` function to perform driver OTA upgrade on each Actuator, with the upgrade version being custom.
        

**Usage:**

To run this script, follow these steps:`demo_ota_driver_custom.py`

1.  Make sure you have set up the Python environment and installed the FSA SDK as described in the Quick Start Guide.
    
2.  Open a terminal and navigate to the directory containing`demo_ota_driver_custom.py`
    
3.  Run the script using the following command:
    

```plaintext
python demo_ota_driver_custom.py

```

**Common Issues:**

If you encounter any issues when running this script, consider the following:

1.  Make sure you use a compatible Python version as recommended in the Quick Start Guide.
    
2.  Verify that your network configuration is correct and the FSA actuator is accessible.
    
## demo\_enable\_set.py

**Code Description:**

This script is mainly used to demonstrate how to perform enable operation on the actuator, i.e., start the actuator.

This script performs the following operations: `demo_enable_set.py`

1.  Use the `broadcast_func_with_filter` function to discover FSA actuators on the network and filter by actuator type.
    
2.  Use the `set_enable` function to perform enable operation on each actuator.
    
3.  Print a message and wait for 1 second to allow time for enabling the Actuators.
        

**Usage:**

To run this script, follow these steps:`demo_enable_set.py`

1.  Make sure you have set up the Python environment and installed the FSA SDK as described in the Quick Start Guide.
    
2.  Open a terminal and navigate to the directory containing`demo_enable_set.py`
    
3.  Run the script using the following command:
    
    ```plaintext
    python demo_enable_set.py
    
    ```
    
4.  Running results (actual execution may differ from the demo, such as IP information):
    

```python
len3@len3-System-Product-Name:~/wiki-fsa/v2/example$ python3 ./demo_enable_set.py 
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v1
Log Already Existed ./log/2024/10/
[2024.10.31 11:42:45.075.500]  Info:    FSA start listening for broadcast...
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v2
Log Already Existed ./log/2024/10/
[2024.10.31 11:42:45.077.056]  Info:    FSA start listening for broadcast...
[2024.10.31 11:42:45.077.088]  Info:    FSA start listening for broadcast...


[2024.10.31 11:42:45.078.506]  Info:    Received from ('192.168.137.101', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA-0","serial_number":"F0BE83CD31E8","driver_version":"0.2.9.1","firmware_version":"0.3.9.9","connect_mode":"ETH","mac_address":"E8:31:CD:83:BE:F3","ip_address":"192.168.137.101","IP":"192.168.137.101"}


found servers
['192.168.137.101']
lookup Finished! 

[2024.10.31 11:42:48.079.720]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/control_word", "property": "", "control_word": 15}
[2024.10.31 11:42:48.080.855]  Info:    Received from ('192.168.137.101', 2333):{"status":"OK","reqTarget":"/control_word","property":""}



```

**Common Issues:**

If you encounter any issues when running this script, consider the following:

1.  Make sure you use a compatible Python version as recommended in the Quick Start Guide.
    
2.  Verify that your network configuration is correct and the FSA actuator is accessible.
    
## demo\_disable\_set.py

**Code Description:**

This script is mainly used to demonstrate how to perform disable operation on the actuator.

This script performs the following operations: `demo_disable_set.py`

1.  Use the `broadcast_func_with_filter` function to discover FSA actuators on the network and filter by actuator type.
    
2.  Use the `set_disable` function to perform disable operation on each actuator.
    
3.  Print a message and wait for 1 second to allow time for enabling the Actuators.
        

**Usage:**

To run this script, follow these steps:`demo_disable_set.py`

1.  Make sure you have set up the Python environment and installed the FSA SDK as described in the Quick Start Guide.
    
2.  Open a terminal and navigate to the directory containing`demo_disable_set.py`
    
3.  Run the script using the following command:
    
    ```plaintext
    python demo_disable_set.py
    
    ```
    
4.  Running results (actual execution may differ from the demo, such as IP information):
    

```python
len3@len3-System-Product-Name:~/wiki-fsa/v2/example$ python3 ./demo_disable_set.py 
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v1
Log Already Existed ./log/2024/10/
[2024.10.31 11:42:55.084.026]  Info:    FSA start listening for broadcast...
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v2
Log Already Existed ./log/2024/10/
[2024.10.31 11:42:55.085.034]  Info:    FSA start listening for broadcast...
[2024.10.31 11:42:55.085.065]  Info:    FSA start listening for broadcast...


[2024.10.31 11:42:55.086.520]  Info:    Received from ('192.168.137.101', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA-0","serial_number":"F0BE83CD31E8","driver_version":"0.2.9.1","firmware_version":"0.3.9.9","connect_mode":"ETH","mac_address":"E8:31:CD:83:BE:F3","ip_address":"192.168.137.101","IP":"192.168.137.101"}


found servers
['192.168.137.101']
lookup Finished! 

[2024.10.31 11:42:58.087.818]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/control_word", "property": "", "control_word": 6}
[2024.10.31 11:42:58.088.929]  Info:    Received from ('192.168.137.101', 2333):{"status":"OK","reqTarget":"/control_word","property":""}

```

**Common Issues:**

If you encounter any issues when running this script, consider the following:

1.  Make sure you use a compatible Python version as recommended in the Quick Start Guide.
    
2.  Verify that your network configuration is correct and the FSA actuator is accessible.
    
## demo\_clear\_fault.py

**Code Description:**

This script is mainly used to demonstrate how to clear actuator faults.

This script performs the following operations: `demo_fault.py`

1.  Use the `broadcast_func_with_filter` function to discover FSA actuators on the network and filter by actuator type.
    
2.  Use the `get_error_code` function to get the error code of each actuator.
    
3.  Use the `clear_fault` function to clear the error code of each actuator.
        

**Usage:**

To run this script, follow these steps:`demo_clear_fault.py`

1.  Make sure you have set up the Python environment and installed the FSA SDK as described in the Quick Start Guide.
    
2.  Open a terminal and navigate to the directory containing`demo_clear_fault.py`
    
3.  Run the script using the following command:
    
    ```plaintext
    python demo_clear_fault.py
    ```
    
4.  Running results (actual execution may differ from the demo, such as IP information):
    

```python
(base) len3@len3-System-Product-Name:~/wiki-fsa/v2/example$ python3 ./demo_clear_fault.py 
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v1
Log Already Existed ./log/2024/11/
[2024.11.12 15:00:44.136.179]  Info:    FSA start listening for broadcast...
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v2
Log Already Existed ./log/2024/11/
[2024.11.12 15:00:44.137.512]  Info:    FSA start listening for broadcast...
[2024.11.12 15:00:44.137.543]  Info:    FSA start listening for broadcast...


[2024.11.12 15:00:44.138.830]  Info:    Received from ('192.168.137.70', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA","serial_number":"CC64AC8D3A08","driver_version":"0.2.9.1","firmware_version":"0.3.9.9","connect_mode":"ETH","mac_address":"08:3A:8D:AC:64:CF","ip_address":"192.168.137.70","IP":"192.168.137.70"}


found servers
['192.168.137.70']
lookup Finished! 

[2024.11.12 15:00:47.139.925]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/error_code", "property": ""}
[2024.11.12 15:00:47.140.904]  Info:    Received from ('192.168.137.70', 2333):{"status":"OK","reqTarget":"/error_code","property":"","error_code":16}
[2024.11.12 15:00:47.140.997]  Info:    Now Error Type =  ERROR_UNDER_VBUS
Error code = 16
[2024.11.12 15:00:47.141.107]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/control_word", "property": "", "control_word": 134, "reply_enable": true}
[2024.11.12 15:00:47.141.991]  Info:    Received from ('192.168.137.70', 2333):{"status":"OK","reqTarget":"/control_word","property":""}

```

**Common Issues:**

If you encounter any issues when running this script, consider the following:

1.  Make sure you use a compatible Python version as recommended in the Quick Start Guide.
    
2.  Verify that your network configuration is correct and the FSA actuator is accessible.
    
## demo\_set\_calibrate\_encoder.py

**Code Description:**

This script is mainly used to demonstrate how to calibrate the actuator (Note: During calibration, the actuator will rotate. It is recommended to secure the actuator before calibration).

This script performs the following operations: `demo_set_calibrate_encoder.py`

1.  Use the `broadcast_func_with_filter` function to discover FSA actuators on the network and filter by actuator type.
    
2.  Use the `set_calibrate_encoder` function to perform calibration operation on each actuator.
    
3.  Use the `get_state` function to get the current state of each actuator.
    
4.  Use the `set_disable` function to perform disable operation on the calibrated actuator.
    
5.  Finally, use the `set_disable` function to perform disable operation on each actuator.
        

**Usage:**

To run this script, follow these steps:`demo_set_calibrate_encoder.py`

1.  Make sure you have set up the Python environment and installed the FSA SDK as described in the Quick Start Guide.
    
2.  Open a terminal and navigate to the directory containing`demo_set_calibrate_encoder.py`
    
3.  Run the script using the following command:
    
    ```plaintext
    python demo_set_calibrate_encoder.py
    
    ```
    
4.  Running results (actual execution may differ from the demo, such as IP information):
    

```python
len3@len3-System-Product-Name:~/wiki-fsa/v2/example$ python3 ./demo_set_calibrate_encoder.py 
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v1
Log Already Existed ./log/2024/10/
[2024.10.31 15:14:29.483.510]  Info:    FSA start listening for broadcast...
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v2
Log Already Existed ./log/2024/10/
[2024.10.31 15:14:29.484.559]  Info:    FSA start listening for broadcast...
[2024.10.31 15:14:29.484.592]  Info:    FSA start listening for broadcast...


[2024.10.31 15:14:29.485.906]  Info:    Received from ('192.168.137.101', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA-0","serial_number":"F0BE83CD31E8","driver_version":"0.2.9.1","firmware_version":"0.3.9.9","connect_mode":"ETH","mac_address":"E8:31:CD:83:BE:F3","ip_address":"192.168.137.101","IP":"192.168.137.101"}


found servers
['192.168.137.101']
lookup Finished! 

[2024.10.31 15:14:32.487.312]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/control_word", "property": "", "control_word": 163}
[2024.10.31 15:14:32.488.180]  Info:    Received from ('192.168.137.101', 2333):{"status":"OK","reqTarget":"/control_word","property":""}
[2024.10.31 15:14:33.488.424]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/state", "property": ""}
[2024.10.31 15:14:33.489.222]  Info:    Received from ('192.168.137.101', 2333):{"status":"OK","reqTarget":"/state","property":"","state":0}
[2024.10.31 15:14:34.489.539]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/state", "property": ""}
[2024.10.31 15:14:34.490.436]  Info:    Received from ('192.168.137.101', 2333):{"status":"OK","reqTarget":"/state","property":"","state":0}
[2024.10.31 15:14:35.490.726]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/state", "property": ""}
[2024.10.31 15:14:35.491.509]  Info:    Received from ('192.168.137.101', 2333):{"status":"OK","reqTarget":"/state","property":"","state":0}
[2024.10.31 15:14:36.491.769]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/state", "property": ""}
[2024.10.31 15:14:36.492.663]  Info:    Received from ('192.168.137.101', 2333):{"status":"OK","reqTarget":"/state","property":"","state":0}
[2024.10.31 15:14:37.493.009]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/state", "property": ""}
[2024.10.31 15:14:37.493.833]  Info:    Received from ('192.168.137.101', 2333):{"status":"OK","reqTarget":"/state","property":"","state":0}
[2024.10.31 15:14:38.494.138]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/control_word", "property": "", "control_word": 6}
[2024.10.31 15:14:38.494.989]  Info:    Received from ('192.168.137.101', 2333):{"status":"OK","reqTarget":"/control_word","property":""}

```

**Common Issues:**

If you encounter any issues when running this script, consider the following:

1.  Make sure you use a compatible Python version as recommended in the Quick Start Guide.
    
2.  Verify that your network configuration is correct and the FSA actuator is accessible.
    
## demo\_pid\_param\_get.py

**Code Description:**

This script is mainly used to demonstrate how to get the actuator's PID configuration parameters.

This script performs the following operations: `demo_pid_param_get.py`

1.  Use the `broadcast_func_with_filter` function to discover FSA actuators on the network and filter by actuator type.
    
2.  Use the `get_pid_param` function to get the PID configuration parameters of each actuator.
        

**Usage:**

To run this script, follow these steps:`demo_pid_param_get.py`

1.  Make sure you have set up the Python environment and installed the FSA SDK as described in the Quick Start Guide.
    
2.  Open a terminal and navigate to the directory containing`demo_pid_param_get.py`
    
3.  Run the script using the following command:
    
    ```plaintext
    python demo_pid_param_get.py
    ```
    
4.  Running results (actual execution may differ from the demo, such as IP information):
    

```python
len3@len3-System-Product-Name:~/wiki-fsa/v2/example$ python3 ./demo_pid_param_get.py 
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v1
Log Already Existed ./log/2024/11/
[2024.11.02 11:27:36.661.864]  Info:    FSA start listening for broadcast...
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v2
Log Already Existed ./log/2024/11/
[2024.11.02 11:27:36.662.922]  Info:    FSA start listening for broadcast...
[2024.11.02 11:27:36.662.965]  Info:    FSA start listening for broadcast...


[2024.11.02 11:27:36.665.580]  Info:    Received from ('192.168.137.93', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA","serial_number":"8C506D144B8C","driver_version":"0.1.10.7","firmware_version":"0.2.15.5","connect_mode":"ETH","mac_address":"8C:4B:14:6D:50:8F","ip_address":"192.168.137.93","IP":"192.168.137.93"}


found servers
['192.168.137.93']
lookup Finished! 

[2024.11.02 11:27:39.666.649]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/pid_param", "property": ""}
[2024.11.02 11:27:39.668.296]  Info:    Received from ('192.168.137.93', 2333):{"status":"OK","reqTarget":"/pid_param","property":"","control_position_kp":0.050000001,"control_velocity_kp":0.01,"control_velocity_ki":0.0001,"control_current_kp":0.600044012,"control_current_ki":0.079842001}
```

**Common Issues:**

If you encounter any issues when running this script, consider the following:

1.  Make sure you use a compatible Python version as recommended in the Quick Start Guide.
    
2.  Verify that your network configuration is correct and the FSA actuator is accessible.
    
## demo\_pid\_param\_set.py

**Code Description:**

This script is mainly used to demonstrate how to set the actuator's PID configuration parameters (these parameters require a restart to take effect).

This script performs the following operations: `demo_pid_param_set.py`

1.  Use the `broadcast_func_with_filter` function to discover FSA actuators on the network and filter by actuator type.
    
2.  Use the `set_pid_param` function to set the PID configuration parameters of each actuator.
    
3.  Use the `get_pid_param` function to get the PID configuration parameters of each actuator.
    
4.  Use the `reboot` function to restart each actuator to use the PID configuration parameters after setting.
        

**Usage:**

To run this script, follow these steps:`demo_pid_param_set.py`

1.  Make sure you have set up the Python environment and installed the FSA SDK as described in the Quick Start Guide.
    
2.  Open a terminal and navigate to the directory containing`demo_pid_param_set.py`
    
3.  Run the script using the following command:
    
    ```plaintext
    python demo_pid_param_set.py
    ```
    
4.  Running results (actual execution may differ from the demo, such as IP information):
    

```python
len3@len3-System-Product-Name:~/wiki-fsa/v2/example$ python3 ./demo_pid_param_set.py 
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v1
Log Already Existed ./log/2024/11/
[2024.11.02 11:50:10.196.510]  Info:    FSA start listening for broadcast...
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v2
Log Already Existed ./log/2024/11/
[2024.11.02 11:50:10.197.515]  Info:    FSA start listening for broadcast...
[2024.11.02 11:50:10.197.553]  Info:    FSA start listening for broadcast...


[2024.11.02 11:50:10.200.202]  Info:    Received from ('192.168.137.93', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA","serial_number":"8C506D144B8C","driver_version":"0.1.10.7","firmware_version":"0.2.15.5","connect_mode":"ETH","mac_address":"8C:4B:14:6D:50:8F","ip_address":"192.168.137.93","IP":"192.168.137.93"}


found servers
['192.168.137.93']
lookup Finished! 

[2024.11.02 11:50:13.201.685]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/pid_param", "property": "", "control_position_kp": 0.5, "control_velocity_kp": 0.0025, "control_velocity_ki": 1e-05, "control_PD_kp": 1.0, "control_PD_kd": 1.0, "reply_enable": true}
[2024.11.02 11:50:13.273.576]  Info:    Received from ('192.168.137.93', 2333):{"status":"OK","reqTarget":"/pid_param","property":""}


[2024.11.02 11:50:14.273.918]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/pid_param", "property": ""}
[2024.11.02 11:50:14.275.480]  Info:    Received from ('192.168.137.93', 2333):{"status":"OK","reqTarget":"/pid_param","property":"","control_position_kp":0.5,"control_velocity_kp":0.0025,"control_velocity_ki":9.999999747e-6,"control_current_kp":0,"control_current_ki":0}


[2024.11.02 11:50:14.275.684]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/reboot", "property": "", "reply_enable": true}
[2024.11.02 11:50:14.277.134]  Info:    Received from ('192.168.137.93', 2333):{"status":"OK","reqTarget":"/reboot","property":""}

```

**Common Issues:**

If you encounter any issues when running this script, consider the following:

1.  Make sure you use a compatible Python version as recommended in the Quick Start Guide.
    
2.  Verify that your network configuration is correct and the FSA actuator is accessible.
    
## demo\_pid\_param\_imm\_get.py

**Code Description:**

This script is mainly used to demonstrate how to get the actuator's temporary PID configuration parameters.

This script performs the following operations:

1.  Use the `broadcast_func_with_filter` function to discover FSA actuators on the network and filter by actuator type.
    
2.  Use the `get_pid_param_imm` function to get the temporary PID configuration parameters of each actuator.
        

**Usage:**

To run this script, follow these steps:`demo_pid_param_imm_get.py`

1.  Make sure you have set up the Python environment and installed the FSA SDK as described in the Quick Start Guide.
    
2.  Open a terminal and navigate to the directory containing`demo_pid_param_imm_get.py`
    
3.  Run the script using the following command:
    
    ```plaintext
    python demo_pid_param_imm_get.py
    ```
    
4.  Running results (actual execution may differ from the demo, such as IP information):
    

```python
len3@len3-System-Product-Name:~/wiki-fsa/v2/example$ python3 ./demo_pid_param_imm_get.py 
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v1
Log Already Existed ./log/2024/11/
[2024.11.02 13:30:35.176.151]  Info:    FSA start listening for broadcast...
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v2
Log Already Existed ./log/2024/11/
[2024.11.02 13:30:35.177.175]  Info:    FSA start listening for broadcast...
[2024.11.02 13:30:35.177.206]  Info:    FSA start listening for broadcast...


[2024.11.02 13:30:35.179.804]  Info:    Received from ('192.168.137.93', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA","serial_number":"8C506D144B8C","driver_version":"0.1.10.7","firmware_version":"0.2.15.5","connect_mode":"ETH","mac_address":"8C:4B:14:6D:50:8F","ip_address":"192.168.137.93","IP":"192.168.137.93"}


found servers
['192.168.137.93']
lookup Finished! 

[2024.11.02 13:30:38.181.122]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/pid_param_imm", "property": ""}
[2024.11.02 13:30:38.182.743]  Info:    Received from ('192.168.137.93', 2333):{"status":"OK","reqTarget":"/pid_param_imm","property":"","control_position_kp_imm":0.050000001,"control_velocity_kp_imm":0.01,"control_velocity_ki_imm":0.0001,"control_current_kp_imm":0.600044012,"control_current_ki_imm":0.079842001}

```

**Common Issues:**

If you encounter any issues when running this script, consider the following:

1.  Make sure you use a compatible Python version as recommended in the Quick Start Guide.
    
2.  Verify that your network configuration is correct and the FSA actuator is accessible.
    
## demo\_pid\_param\_imm\_set.py

**Code Description:**

This script is mainly used to demonstrate how to set the actuator's temporary PID configuration parameters (these parameters take effect immediately, but will not be saved after power off).

This script performs the following operations: `demo_pid_param_imm_set.py`

1.  Use the `broadcast_func_with_filter` function to discover FSA actuators on the network and filter by actuator type.
    
2.  Use the `set_pid_param_imm` function to set the temporary PID configuration parameters of each actuator.
    
3.  Use the `get_pid_param_imm` function to get the temporary PID configuration parameters of each actuator.
        

**Usage:**

To run this script, follow these steps:`demo_pid_param_imm_set.py`

1.  Make sure you have set up the Python environment and installed the FSA SDK as described in the Quick Start Guide.
    
2.  Open a terminal and navigate to the directory containing`demo_pid_param_imm_set.py`
    
3.  Run the script using the following command:
    
    ```plaintext
    python demo_pid_param_imm_set.py
    ```
    
4.  Running results (actual execution may differ from the demo, such as IP information):
    

```python
len3@len3-System-Product-Name:~/wiki-fsa/v2/example$ python3 ./demo_pid_param_imm_set.py 
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v1
Log Already Existed ./log/2024/11/
[2024.11.02 13:35:14.138.717]  Info:    FSA start listening for broadcast...
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v2
Log Already Existed ./log/2024/11/
[2024.11.02 13:35:14.139.704]  Info:    FSA start listening for broadcast...
[2024.11.02 13:35:14.139.740]  Info:    FSA start listening for broadcast...


[2024.11.02 13:35:14.141.100]  Info:    Received from ('192.168.137.93', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA","serial_number":"8C506D144B8C","driver_version":"0.1.10.7","firmware_version":"0.2.15.5","connect_mode":"ETH","mac_address":"8C:4B:14:6D:50:8F","ip_address":"192.168.137.93","IP":"192.168.137.93"}


found servers
['192.168.137.93']
lookup Finished! 

[2024.11.02 13:35:17.142.496]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/pid_param_imm", "property": "", "control_position_kp_imm": 0.0, "control_velocity_kp_imm": 0.1, "control_velocity_ki_imm": 0.001, "control_PD_kp_imm": 1.0, "control_PD_kd_imm": 1.0, "reply_enable": true}
[2024.11.02 13:35:17.143.886]  Info:    Received from ('192.168.137.93', 2333):{"status":"OK","reqTarget":"/pid_param_imm","property":""}


[2024.11.02 13:35:18.144.121]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/pid_param_imm", "property": ""}
[2024.11.02 13:35:18.145.184]  Info:    Received from ('192.168.137.93', 2333):{"status":"OK","reqTarget":"/pid_param_imm","property":"","control_position_kp_imm":0,"control_velocity_kp_imm":0.100000001,"control_velocity_ki_imm":0.001,"control_current_kp_imm":0,"control_current_ki_imm":0}

```

**Common Issues:**

If you encounter any issues when running this script, consider the following:

1.  Make sure you use a compatible Python version as recommended in the Quick Start Guide.
    
2.  Verify that your network configuration is correct and the FSA actuator is accessible.
    
## demo\_control\_param\_get.py

**Code Description:**

This script is mainly used to demonstrate how to get the actuator's control parameters (these parameters require a restart to take effect).

This script performs the following operations: `demo_control_param_get.py`

1.  Use the `broadcast_func_with_filter` function to discover FSA actuators on the network and filter by actuator type.
    
2.  Use the `get_control_param` function to get the control parameters of each actuator.
    

**Usage:**

To run this script, follow these steps:`demo_control_param_get.py`

1.  Make sure you have set up the Python environment and installed the FSA SDK as described in the Quick Start Guide.
    
2.  Open a terminal and navigate to the directory containing`demo_control_param_get.py`
    
3.  Run the script using the following command:
    
    ```plaintext
    python demo_control_param_get.py
    ```
    
4.  Running results (actual execution may differ from the demo, such as IP information):
    

```python
len3@len3-System-Product-Name:~/wiki-fsa/v2/example$ python3 ./demo_control_param_get.py 
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v1
Log Already Existed ./log/2024/11/
[2024.11.02 14:01:02.649.769]  Info:    FSA start listening for broadcast...
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v2
Log Already Existed ./log/2024/11/
[2024.11.02 14:01:02.650.855]  Info:    FSA start listening for broadcast...
[2024.11.02 14:01:02.650.895]  Info:    FSA start listening for broadcast...


[2024.11.02 14:01:02.652.100]  Info:    Received from ('192.168.137.93', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA","serial_number":"8C506D144B8C","driver_version":"0.1.10.7","firmware_version":"0.2.15.5","connect_mode":"ETH","mac_address":"8C:4B:14:6D:50:8F","ip_address":"192.168.137.93","IP":"192.168.137.93"}


found servers
['192.168.137.93']
lookup Finished! 

[2024.11.02 14:01:05.653.424]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/control_param", "property": ""}
[2024.11.02 14:01:05.654.556]  Info:    Received from ('192.168.137.93', 2333):{"status":"OK","reqTarget":"/control_param","property":"","motor_max_speed":3000,"motor_max_acceleration":60000,"motor_max_current":100}

```

**Common Issues:**

If you encounter any issues when running this script, consider the following:

1.  Make sure you use a compatible Python version as recommended in the Quick Start Guide.
    
2.  Verify that your network configuration is correct and the FSA actuator is accessible.
    
## demo\_control\_param\_set.py This script is temporarily unavailable

**Code Description:**

This script is mainly used to demonstrate how to set the actuator's control parameters (these parameters require a restart to take effect).

This script performs the following operations: `demo_control_param_set.py`

1.  Use the `broadcast_func_with_filter` function to discover FSA actuators on the network and filter by actuator type.
    
2.  Use the `set_control_param` function to set the control parameters of each actuator.
    
3.  Use the `get_control_param` function to get the control parameters of each actuator.
    
4.  Use the `reboot` function to restart each actuator to use the control parameters after setting.
        

**Usage:**

To run this script, follow these steps:`demo_control_param_set.py`

1.  Make sure you have set up the Python environment and installed the FSA SDK as described in the Quick Start Guide.
    
2.  Open a terminal and navigate to the directory containing`demo_control_param_set.py`
    
3.  Run the script using the following command:
    
    ```plaintext
    python demo_control_param_set.py
    ```
    
4.  Running results (actual execution may differ from the demo, such as IP information):
    

**Common Issues:**

If you encounter any issues when running this script, consider the following:

1.  Make sure you use a compatible Python version as recommended in the Quick Start Guide.
    
2.  Verify that your network configuration is correct and the FSA actuator is accessible.
    
## demo\_flag\_of\_operation\_get.py

**Code Description:**

This script is mainly used to demonstrate how to get the actuator's operation flag.

This script performs the following operations: `demo_flag_of_operation_get.py`

1.  Use the `broadcast_func_with_filter` function to discover FSA actuators on the network and filter by actuator type.
    
2.  Use the `get_flag_of_operation` function to get the operation flag of each actuator.
        

**Usage:**

To run this script, follow these steps:`demo_flag_of_operation_get.py`

1.  Make sure you have set up the Python environment and installed the FSA SDK as described in the Quick Start Guide.
    
2.  Open a terminal and navigate to the directory containing`demo_flag_of_operation_get.py`
    
3.  Run the script using the following command:
    
    ```plaintext
    python demo_flag_of_operation_get.py
    ```
    
4.  Running results (actual execution may differ from the demo, such as IP information):
    

```python
len3@len3-System-Product-Name:~/wiki-fsa/v2/example$ python3 ./demo_flag_of_operation_get.py 
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v1
Log Already Existed ./log/2024/11/
[2024.11.02 15:33:25.309.503]  Info:    FSA start listening for broadcast...
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v2
Log Already Existed ./log/2024/11/
[2024.11.02 15:33:25.310.538]  Info:    FSA start listening for broadcast...
[2024.11.02 15:33:25.310.568]  Info:    FSA start listening for broadcast...


[2024.11.02 15:33:25.311.849]  Info:    Received from ('192.168.137.93', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA","serial_number":"8C506D144B8C","driver_version":"0.1.10.7","firmware_version":"0.2.15.5","connect_mode":"ETH","mac_address":"8C:4B:14:6D:50:8F","ip_address":"192.168.137.93","IP":"192.168.137.93"}


found servers
['192.168.137.93']
lookup Finished! 

[2024.11.02 15:33:28.313.160]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/flag_of_operation", "property": ""}
[2024.11.02 15:33:28.314.339]  Info:    Received from ('192.168.137.93', 2333):{"status":"OK","reqTarget":"/flag_of_operation","property":"","flag_do_use_store_motor_param":1,"flag_do_use_store_pid_param":0}

```

**Common Issues:**

If you encounter any issues when running this script, consider the following:

1.  Make sure you use a compatible Python version as recommended in the Quick Start Guide.
    
2.  Verify that your network configuration is correct and the FSA actuator is accessible.

## demo\_flag\_of\_operation\_set.py

**Code Description:**

This script is mainly used to demonstrate how to get the actuator's operation flag.

This script performs the following operations: `demo_flag_of_operation_set.py`

1.  Use the `broadcast_func_with_filter` function to discover FSA actuators on the network and filter by actuator type.
    
2.  Use the `set_flag_of_operation` function to set the operation flag of each actuator.
    
3.  Use the `get_flag_of_operation` function to get the operation flag of each actuator.
    
4.  Use the `reboot` function to restart each actuator to use the operation flag after setting.
        

**Usage:**

To run this script, follow these steps:`demo_flag_of_operation_set.py`

1.  Make sure you have set up the Python environment and installed the FSA SDK as described in the Quick Start Guide.
    
2.  Open a terminal and navigate to the directory containing`demo_flag_of_operation_set.py`
    
3.  Run the script using the following command:
    
    ```plaintext
    python demo_flag_of_operation_set.py
    ```
    
4.  Running results (actual execution may differ from the demo, such as IP information):
    

```python
len3@len3-System-Product-Name:~/wiki-fsa/v2/example$ python3 ./demo_flag_of_operation_set.py 
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v1
Log Already Existed ./log/2024/11/
[2024.11.02 15:43:42.958.014]  Info:    FSA start listening for broadcast...
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v2
Log Already Existed ./log/2024/11/
[2024.11.02 15:43:42.959.018]  Info:    FSA start listening for broadcast...
[2024.11.02 15:43:42.959.051]  Info:    FSA start listening for broadcast...


[2024.11.02 15:43:42.960.393]  Info:    Received from ('192.168.137.93', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA","serial_number":"8C506D144B8C","driver_version":"0.1.10.7","firmware_version":"0.2.15.5","connect_mode":"ETH","mac_address":"8C:4B:14:6D:50:8F","ip_address":"192.168.137.93","IP":"192.168.137.93"}


found servers
['192.168.137.93']
lookup Finished! 

[2024.11.02 15:43:45.961.738]  Info:    Send JSON Obj: {"flag_do_use_store_actuator_param": 0, "flag_do_use_store_motor_param": 1, "flag_do_use_store_encoder_param": 0, "flag_do_use_store_pid_param": 0, "actuator_double_encoder_enable": 1, "method": "SET", "reqTarget": "/flag_of_operation", "property": "", "reply_enable": true}
[2024.11.02 15:43:46.035.195]  Info:    Received from ('192.168.137.93', 2333):{"status":"OK","reqTarget":"/flag_of_operation","property":""}


[2024.11.02 15:43:47.035.466]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/flag_of_operation", "property": ""}
[2024.11.02 15:43:47.036.733]  Info:    Received from ('192.168.137.93', 2333):{"status":"OK","reqTarget":"/flag_of_operation","property":"","flag_do_use_store_motor_param":1,"flag_do_use_store_pid_param":0}


[2024.11.02 15:43:47.036.855]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/reboot", "property": "", "reply_enable": true}
[2024.11.02 15:43:47.038.095]  Info:    Received from ('192.168.137.93', 2333):{"status":"OK","reqTarget":"/reboot","property":""}

```

**Common Issues:**

If you encounter any issues when running this script, consider the following:

1.  Make sure you use a compatible Python version as recommended in the Quick Start Guide.
    
2.  Verify that your network configuration is correct and the FSA actuator is accessible.
    
## demo\_ctrl\_config\_get.py

**Code Description:**

This script is mainly used to demonstrate how to get the actuator's configuration information.

This script performs the following operations: `demo_ctrl_config_get.py`

1.  Use the `broadcast_func_with_filter` function to discover FSA actuators on the network and filter by actuator type.
    
2.  Use the `get_config` function to get the configuration information of each actuator.
        

**Usage:**

To run this script, follow these steps:`demo_ctrl_config_get.py`

1.  Make sure you have set up the Python environment and installed the FSA SDK as described in the Quick Start Guide.
    
2.  Open a terminal and navigate to the directory containing`demo_ctrl_config_get.py`
    
3.  Run the script using the following command:
    
    ```plaintext
    python demo_ctrl_config_get.py
    ```
    
4.  Running results (actual execution may differ from the demo, such as IP information):
    

```python
len3@len3-System-Product-Name:~/wiki-fsa/v2/example$ python3 ./demo_ctrl_config_get.py 
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v1
Log Already Existed ./log/2024/11/
[2024.11.04 10:02:26.890.860]  Info:    FSA start listening for broadcast...
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v2
Log Already Existed ./log/2024/11/
[2024.11.04 10:02:26.892.567]  Info:    FSA start listening for broadcast...
[2024.11.04 10:02:26.892.598]  Info:    FSA start listening for broadcast...


[2024.11.04 10:02:26.893.788]  Info:    Received from ('192.168.137.93', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA","serial_number":"8C506D144B8C","driver_version":"0.1.10.7","firmware_version":"0.2.15.5","connect_mode":"ETH","mac_address":"8C:4B:14:6D:50:8F","ip_address":"192.168.137.93","IP":"192.168.137.93"}


found servers
['192.168.137.93']
lookup Finished! 

[2024.11.04 10:02:29.895.150]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/config", "property": ""}
[2024.11.04 10:02:29.896.550]  Info:    Received from ('192.168.137.93', 2333):{"status":"OK","reqTarget":"/config","property":"","actuator_type":1,"actuator_direction":1,"actuator_reduction_ratio":31,"motor_type":4,"motor_hardware_type":3,"motor_vbus":48,"motor_direction":1,"motor_max_speed":3000,"motor_max_acceleration":60000,"motor_max_current":100}

```

**Common Issues:**

If you encounter any issues when running this script, consider the following:

1.  Make sure you use a compatible Python version as recommended in the Quick Start Guide.
    
2.  Verify that your network configuration is correct and the FSA actuator is accessible.
    
## demo\_ctrl\_config\_set.py

**Code Description:**

This script is mainly used to demonstrate how to get the actuator's configuration information.

This script performs the following operations: `demo_ctrl_config_set.py`

1.  Use the `broadcast_func_with_filter` function to discover FSA actuators on the network and filter by actuator type.
    
2.  Use the `set_config` function to set the configuration information of each actuator.
    
3.  Use the `get_config` function to get the configuration information of each actuator.
    
4.  Use the `reboot` function to restart each actuator to use the actuator configuration information after setting.
        

**Usage:**

To run this script, follow these steps:`demo_ctrl_config_set.py`

1.  Make sure you have set up the Python environment and installed the FSA SDK as described in the Quick Start Guide.
    
2.  Open a terminal and navigate to the directory containing`demo_ctrl_config_set.py`
    
3.  Run the script using the following command:
    
    ```plaintext
    python demo_ctrl_config_set.py
    ```
    
4.  Running results (actual execution may differ from the demo, such as IP information):
    

```python
len3@len3-System-Product-Name:~/wiki-fsa/v2/example$ python3 ./demo_ctrl_config_set.py 
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v1
Log Already Existed ./log/2024/11/
[2024.11.04 10:09:37.179.770]  Info:    FSA start listening for broadcast...
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v2
Log Already Existed ./log/2024/11/
[2024.11.04 10:09:37.180.775]  Info:    FSA start listening for broadcast...
[2024.11.04 10:09:37.180.812]  Info:    FSA start listening for broadcast...


[2024.11.04 10:09:37.182.082]  Info:    Received from ('192.168.137.93', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA","serial_number":"8C506D144B8C","driver_version":"0.1.10.7","firmware_version":"0.2.15.5","connect_mode":"ETH","mac_address":"8C:4B:14:6D:50:8F","ip_address":"192.168.137.93","IP":"192.168.137.93"}


found servers
['192.168.137.93']
lookup Finished! 

[2024.11.04 10:09:40.183.584]  Info:    Send JSON Obj: {"actuator_type": 1, "actuator_direction": 1, "actuator_reduction_ratio": 81, "motor_type": 6, "motor_hardware_type": 4, "motor_vbus": 48, "motor_direction": 1, "motor_max_speed": 3000, "motor_max_acceleration": 60000, "motor_max_current": 3.3, "actuator_comm_hardware_type": 2, "method": "SET", "reqTarget": "/config", "property": "", "reply_enable": true}
[2024.11.04 10:09:40.258.475]  Info:    Received from ('192.168.137.93', 2333):{"status":"OK","reqTarget":"/config","property":""}


[2024.11.04 10:09:41.258.890]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/config", "property": ""}
[2024.11.04 10:09:41.260.547]  Info:    Received from ('192.168.137.93', 2333):{"status":"OK","reqTarget":"/config","property":"","actuator_type":1,"actuator_direction":1,"actuator_reduction_ratio":81,"motor_type":6,"motor_hardware_type":4,"motor_vbus":48,"motor_direction":1,"motor_max_speed":3000,"motor_max_acceleration":60000,"motor_max_current":3.299999952}


[2024.11.04 10:09:41.260.759]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/reboot", "property": "", "reply_enable": true}
[2024.11.04 10:09:41.262.103]  Info:    Received from ('192.168.137.93', 2333):{"status":"OK","reqTarget":"/reboot","property":""}

```

**Common Issues:**

If you encounter any issues when running this script, consider the following:

1.  Make sure you use a compatible Python version as recommended in the Quick Start Guide.
    
2.  Verify that your network configuration is correct and the FSA actuator is accessible.
    
## demo\_reboot.py

**Code Description:**

This script is mainly used to demonstrate how to reboot the actuator.

This script performs the following operations: `demo_reboot.py`

1.  Use the `broadcast_func` function to discover all Fourier self-developed devices on the network.

2.  Use the `reboot` function to restart each actuator.
        

**Usage:**

To run this script, follow these steps:`demo_reboot.py`

1.  Make sure you have set up the Python environment and installed the FSA SDK as described in the Quick Start Guide.
    
2.  Open a terminal and navigate to the directory containing`demo_reboot.py`
    
3.  Run the script using the following command:
    
    ```plaintext
    python demo_reboot.py
    ```
    
4.  Running results (actual execution may differ from the demo, such as IP information):
    

```python
len3@len3-System-Product-Name:~/wiki-fsa/v2/example$ python3 ./demo_reboot.py 
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v1
Log Already Existed ./log/2024/11/
[2024.11.04 10:23:01.025.692]  Info:    FSA start listening for broadcast...
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v2
Log Already Existed ./log/2024/11/
[2024.11.04 10:23:01.026.763]  Info:    FSA start listening for broadcast...
[2024.11.04 10:23:01.026.793]  Info:    FSA start listening for broadcast...


[2024.11.04 10:23:01.029.494]  Info:    Received from ('192.168.137.93', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA","serial_number":"8C506D144B8C","driver_version":"0.1.10.7","firmware_version":"0.2.15.5","connect_mode":"ETH","mac_address":"8C:4B:14:6D:50:8F","ip_address":"192.168.137.93","IP":"192.168.137.93"}


found servers
['192.168.137.93']
lookup Finished! 

[2024.11.04 10:23:04.030.842]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/reboot", "property": "", "reply_enable": true}
[2024.11.04 10:23:04.032.520]  Info:    Received from ('192.168.137.93', 2333):{"status":"OK","reqTarget":"/reboot","property":""}

```

**Common Issues:**

If you encounter any issues when running this script, consider the following:

1.  Make sure you use a compatible Python version as recommended in the Quick Start Guide.
    
2.  Verify that your network configuration is correct and the FSA actuator is accessible.
    
## demo\_get\_error.py

**Code Description:**

This script is mainly used to demonstrate how to get the actuator's error code.

This script performs the following operations: `demo_get_error.py`

1.  Use the `broadcast_func_with_filter` function to discover FSA actuators on the network and filter by actuator type.
    
2.  Use the `get_error_code` function to get the error code of the actuator.
    
3.  Display it in the terminal.
        

**Usage:**

To run this script, follow these steps:`demo_get_error.py`

1.  Make sure you have set up the Python environment and installed the FSA SDK as described in the Quick Start Guide.
    
2.  Open a terminal and navigate to the directory containing`demo_get_error.py`
    
3.  Run the script using the following command:
    
    ```plaintext
    python demo_get_error.py
    ```
    
4.  Running results (actual execution may differ from the demo, such as IP information):
    

```python
len3@len3-System-Product-Name:~/wiki-fsa/v2/example$ python3 ./demo_get_error.py 
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v1
Log Already Existed ./log/2024/11/
[2024.11.04 10:40:03.841.246]  Info:    FSA start listening for broadcast...
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v2
Log Already Existed ./log/2024/11/
[2024.11.04 10:40:03.842.325]  Info:    FSA start listening for broadcast...
[2024.11.04 10:40:03.842.359]  Info:    FSA start listening for broadcast...


[2024.11.04 10:40:03.843.536]  Info:    Received from ('192.168.137.93', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA","serial_number":"8C506D144B8C","driver_version":"0.1.10.7","firmware_version":"0.2.15.5","connect_mode":"ETH","mac_address":"8C:4B:14:6D:50:8F","ip_address":"192.168.137.93","IP":"192.168.137.93"}


found servers
['192.168.137.93']
lookup Finished! 

[2024.11.04 10:40:06.844.401]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/error_code", "property": ""}
[2024.11.04 10:40:06.845.354]  Info:    Received from ('192.168.137.93', 2333):{"status":"OK","reqTarget":"/error_code","property":"","error_code":0}
Error = 0
[2024.11.04 10:40:07.045.631]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/error_code", "property": ""}
[2024.11.04 10:40:07.046.425]  Info:    Received from ('192.168.137.93', 2333):{"status":"OK","reqTarget":"/error_code","property":"","error_code":0}
Error = 0

```

**Common Issues:**

If you encounter any issues when running this script, consider the following:

1.  Make sure you use a compatible Python version as recommended in the Quick Start Guide.
    
2.  Verify that your network configuration is correct and the FSA actuator is accessible.
    
## demo\_get\_pvc.py

**Code Description:**

This script is mainly used to demonstrate how to get the actuator's current position, velocity, and current information.

This script performs the following operations: `demo_get_pvc.py`

1.  Use the `broadcast_func_with_filter` function to discover FSA actuators on the network and filter by actuator type.
    
2.  Use the `get_pvc` function to get the actuator's current position, velocity, and current information.
    
3.  Display it in the terminal.
        

**Usage:**

To run this script, follow these steps:`demo_get_pvc.py`

1.  Make sure you have set up the Python environment and installed the FSA SDK as described in the Quick Start Guide.
    
2.  Open a terminal and navigate to the directory containing`demo_get_pvc.py`
    
3.  Run the script using the following command:
    
    ```plaintext
    python demo_get_pvc.py
    ```
    
4.  Running results (actual execution may differ from the demo, such as IP information):
    

```python
len3@len3-System-Product-Name:~/wiki-fsa/v2/example$ python3 ./demo_get_pvc.py 
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v1
Log Already Existed ./log/2024/11/
[2024.11.04 10:58:39.952.803]  Info:    FSA start listening for broadcast...
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v2
Log Already Existed ./log/2024/11/
[2024.11.04 10:58:39.953.854]  Info:    FSA start listening for broadcast...
[2024.11.04 10:58:39.953.884]  Info:    FSA start listening for broadcast...


[2024.11.04 10:58:39.955.101]  Info:    Received from ('192.168.137.93', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA","serial_number":"8C506D144B8C","driver_version":"0.1.10.7","firmware_version":"0.2.15.5","connect_mode":"ETH","mac_address":"8C:4B:14:6D:50:8F","ip_address":"192.168.137.93","IP":"192.168.137.93"}


found servers
['192.168.137.93']
lookup Finished! 

[2024.11.04 10:58:42.956.583]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/measured", "position": true, "velocity": true, "current": true}
[2024.11.04 10:58:42.957.822]  Info:    Received from ('192.168.137.93', 2333):{"status":"OK","reqTarget":"/measured","property":null,"position":0.000542568,"velocity":-0.129396752,"current":0}
Position = 0.000543, Velocity = -0.129397, Current = 0.0000
[2024.11.04 10:58:43.158.203]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/measured", "position": true, "velocity": true, "current": true}
[2024.11.04 10:58:43.159.197]  Info:    Received from ('192.168.137.93', 2333):{"status":"OK","reqTarget":"/measured","property":null,"position":0.000813852,"velocity":0.032842342,"current":0}
Position = 0.000814, Velocity = 0.032842, Current = 0.0000

```

**Common Issues:**

If you encounter any issues when running this script, consider the following:

1.  Make sure you use a compatible Python version as recommended in the Quick Start Guide.
    
2.  Verify that your network configuration is correct and the FSA actuator is accessible.
    
## demo\_get\_foc\_target\_PVC.py

**Code Description:**

This script is mainly used to demonstrate how to get the target position, target velocity, and target current information of the actuator's FOC execution.

This script performs the following operations: `demo_get_foc_target_PVC.py`

1.  Use the `broadcast_func_with_filter` function to discover FSA actuators on the network and filter by actuator type.
    
2.  Use the `get_foc_target_PVC` function to get the target position, target velocity, and target current information of the actuator's FOC execution.
    
3.  Display it in the terminal.
        

**Usage:**

To run this script, follow these steps:`demo_get_foc_target_PVC.py`

1.  Make sure you have set up the Python environment and installed the FSA SDK as described in the Quick Start Guide.
    
2.  Open a terminal and navigate to the directory containing`demo_get_foc_target_PVC.py`
    
3.  Run the script using the following command:
    
    ```plaintext
    python demo_get_foc_target_PVC.py
    ```
    
4.  Running results (actual execution may differ from the demo, such as IP information):
    

```python
len3@len3-System-Product-Name:~/wiki-fsa/v2/example$ python3 ./demo_get_foc_target_PVC.py 
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v1
Log Already Existed ./log/2024/11/
[2024.11.04 11:24:28.202.320]  Info:    FSA start listening for broadcast...
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v2
Log Already Existed ./log/2024/11/
[2024.11.04 11:24:28.203.338]  Info:    FSA start listening for broadcast...
[2024.11.04 11:24:28.203.368]  Info:    FSA start listening for broadcast...


[2024.11.04 11:24:28.204.748]  Info:    Received from ('192.168.137.10', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA","serial_number":"4861061C0610","driver_version":"0.2.9.1","firmware_version":"0.3.9.9","connect_mode":"ETH","mac_address":"10:06:1C:06:61:4B","ip_address":"192.168.137.10","IP":"192.168.137.10"}


found servers
['192.168.137.10']
lookup Finished! 

[2024.11.04 11:24:31.206.141]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/foc_target_PVC"}
[2024.11.04 11:24:31.207.431]  Info:    Received from ('192.168.137.10', 2333):{"status":"OK","reqTarget":"/foc_target_PVC","property":null,"position":-91.6812973,"velocity":0,"current":0}
Position = -91.681297, Velocity = 0.000000, Current = 0.0000
[2024.11.04 11:24:31.407.767]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/foc_target_PVC"}
[2024.11.04 11:24:31.408.842]  Info:    Received from ('192.168.137.10', 2333):{"status":"OK","reqTarget":"/foc_target_PVC","property":null,"position":-91.6812973,"velocity":0,"current":0}
Position = -91.681297, Velocity = 0.000000, Current = 0.0000
[2024.11.04 11:24:31.609.187]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/foc_target_PVC"}
[2024.11.04 11:24:31.610.334]  Info:    Received from ('192.168.137.10', 2333):{"status":"OK","reqTarget":"/foc_target_PVC","property":null,"position":-91.6812973,"velocity":0,"current":0}
Position = -91.681297, Velocity = 0.000000, Current = 0.0000

```

**Common Issues:**

If you encounter any issues when running this script, consider the following:

1.  Make sure you use a compatible Python version as recommended in the Quick Start Guide.
    
2.  Verify that your network configuration is correct and the FSA actuator is accessible.
    
## demo\_get\_pvct.py

**Code Description:**

This script is mainly used to demonstrate how to get the actuator's current position, velocity, current, and torque information.

This script performs the following operations: `demo_get_pvct.py`

1.  Use the `broadcast_func_with_filter` function to discover FSA actuators on the network and filter by actuator type.
    
2.  Use the `get_pvct` function to get the actuator's current position, velocity, current, and torque information.
    
3.  Display it in the terminal.
        

**Usage:**

To run this script, follow these steps:`demo_get_pvct.py`

1.  Make sure you have set up the Python environment and installed the FSA SDK as described in the Quick Start Guide.
    
2.  Open a terminal and navigate to the directory containing`demo_get_pvct.py`
    
3.  Run the script using the following command:
    
    ```plaintext
    python demo_get_pvct.py
    ```
    
4.  Running results (actual execution may differ from the demo, such as IP information):
    

```python
len3@len3-System-Product-Name:~/wiki-fsa/v2/example$ python3 ./demo_get_pvct.py 
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v1
Log Already Existed ./log/2024/11/
[2024.11.04 11:34:58.507.450]  Info:    FSA start listening for broadcast...
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v2
Log Already Existed ./log/2024/11/
[2024.11.04 11:34:58.508.468]  Info:    FSA start listening for broadcast...
[2024.11.04 11:34:58.508.503]  Info:    FSA start listening for broadcast...


[2024.11.04 11:34:58.509.863]  Info:    Received from ('192.168.137.10', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA","serial_number":"4861061C0610","driver_version":"0.2.9.1","firmware_version":"0.3.9.9","connect_mode":"ETH","mac_address":"10:06:1C:06:61:4B","ip_address":"192.168.137.10","IP":"192.168.137.10"}


found servers
['192.168.137.10']
lookup Finished! 

[2024.11.04 11:35:01.511.120]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/PVCT"}
[2024.11.04 11:35:01.512.277]  Info:    Received from ('192.168.137.10', 2333):{"status":"OK","reqTarget":"/PVCT","property":null,"position":89.58617401,"velocity":0.03555651,"current":0,"torque":-0.03296325}
Position = 89.586174, Velocity = 0.035557, Current = 0.0000, Torque =   -0
[2024.11.04 11:35:01.712.625]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/PVCT"}
[2024.11.04 11:35:01.713.676]  Info:    Received from ('192.168.137.10', 2333):{"status":"OK","reqTarget":"/PVCT","property":null,"position":89.58609772,"velocity":-0.108989172,"current":0,"torque":0.015949339}
Position = 89.586098, Velocity = -0.108989, Current = 0.0000, Torque =    0
[2024.11.04 11:35:01.914.034]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/PVCT"}
[2024.11.04 11:35:01.915.123]  Info:    Received from ('192.168.137.10', 2333):{"status":"OK","reqTarget":"/PVCT","property":null,"position":89.58616638,"velocity":-0.02177074,"current":0,"torque":-0.021388493}
Position = 89.586166, Velocity = -0.021771, Current = 0.0000, Torque =   -0
[2024.11.04 11:35:02.115.460]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/PVCT"}
[2024.11.04 11:35:02.116.494]  Info:    Received from ('192.168.137.10', 2333):{"status":"OK","reqTarget":"/PVCT","property":null,"position":89.58615875,"velocity":-0.072669469,"current":0,"torque":-0.010420063}
Position = 89.586159, Velocity = -0.072669, Current = 0.0000, Torque =   -0

```

**Common Issues:**

If you encounter any issues when running this script, consider the following:

1.  Make sure you use a compatible Python version as recommended in the Quick Start Guide.
    
2.  Verify that your network configuration is correct and the FSA actuator is accessible.
    
## demo\_get\_fsa\_abs\_position.py

**Code Description:**

This script is mainly used to demonstrate how to get the absolute encoder position information of the actuator.

This script performs the following operations: `demo_get_fsa_abs_position.py`

1.  Use the `broadcast_func_with_filter` function to discover FSA actuators on the network and filter by actuator type.
    
2.  Use the `get_fsa_abs_position` function to get the absolute encoder position information of the actuator.
    
3.  Display it in the terminal.
        

**Usage:**

To run this script, follow these steps:`demo_get_fsa_abs_position.py`

1.  Make sure you have set up the Python environment and installed the FSA SDK as described in the Quick Start Guide.
    
2.  Open a terminal and navigate to the directory containing`demo_get_fsa_abs_position.py`
    
3.  Run the script using the following command:
    
    ```plaintext
    python demo_get_fsa_abs_position.py
    ```
    
4.  Running results (actual execution may differ from the demo, such as IP information):
    

```python
len3@len3-System-Product-Name:~/wiki-fsa/v2/example$ python3 ./demo_get_fsa_abs_position.py 
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v1
Log Already Existed ./log/2024/11/
[2024.11.04 13:22:27.628.713]  Info:    FSA start listening for broadcast...
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v2
Log Already Existed ./log/2024/11/
[2024.11.04 13:22:27.630.404]  Info:    FSA start listening for broadcast...
[2024.11.04 13:22:27.630.435]  Info:    FSA start listening for broadcast...


[2024.11.04 13:22:27.633.344]  Info:    Received from ('192.168.137.10', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA","serial_number":"4861061C0610","driver_version":"0.2.9.1","firmware_version":"0.3.9.9","connect_mode":"ETH","mac_address":"10:06:1C:06:61:4B","ip_address":"192.168.137.10","IP":"192.168.137.10"}


found servers
['192.168.137.10']
lookup Finished! 

[2024.11.04 13:22:30.634.706]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/get_abs_position"}
[2024.11.04 13:22:30.638.086]  Info:    Received from ('192.168.137.10', 2333):{"status":"OK","reqTarget":"/get_abs_position","property":null,"abs_position":94.93286133}
Position = 94.932861

```

**Common Issues:**

If you encounter any issues when running this script, consider the following:

1.  Make sure you use a compatible Python version as recommended in the Quick Start Guide.
    
2.  Verify that your network configuration is correct and the FSA actuator is accessible.
    
## demo\_set\_fsa\_abs\_zero.py

**Code Description:**

This script is mainly used to demonstrate how to set the zero point of the actuator's absolute encoder.

This script performs the following operations: `demo_set_fsa_abs_zero.py`

1.  Use the `broadcast_func_with_filter` function to discover FSA actuators on the network and filter by actuator type.
    
2.  Use the `set_fsa_abs_zero` function to set the zero point of the actuator's absolute encoder, using the current position as the zero point.
    
3.  Use the `reboot` function to restart each actuator to use the absolute encoder zero point after setting.
        

**Usage:**

To run this script, follow these steps:`demo_set_fsa_abs_zero.py`

1.  Make sure you have set up the Python environment and installed the FSA SDK as described in the Quick Start Guide.
    
2.  Open a terminal and navigate to the directory containing`demo_set_fsa_abs_zero.py`
    
3.  Run the script using the following command:
    
    ```plaintext
    python demo_set_fsa_abs_zero.py
    ```
    
4.  Running results (actual execution may differ from the demo, such as IP information):
    

```python
len3@len3-System-Product-Name:~/wiki-fsa/v2/example$ python3 ./demo_set_fsa_abs_zero.py 
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v1
Log Already Existed ./log/2024/11/
[2024.11.04 13:34:37.314.672]  Info:    FSA start listening for broadcast...
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v2
Log Already Existed ./log/2024/11/
[2024.11.04 13:34:37.315.687]  Info:    FSA start listening for broadcast...
[2024.11.04 13:34:37.315.717]  Info:    FSA start listening for broadcast...


[2024.11.04 13:34:37.317.110]  Info:    Received from ('192.168.137.10', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA","serial_number":"4861061C0610","driver_version":"0.2.9.1","firmware_version":"0.3.9.9","connect_mode":"ETH","mac_address":"10:06:1C:06:61:4B","ip_address":"192.168.137.10","IP":"192.168.137.10"}


found servers
['192.168.137.10']
lookup Finished! 

now is setting: 192.168.137.10
[2024.11.04 13:34:40.318.626]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/set_abs_zero", "reply_enable": true}
[2024.11.04 13:34:40.320.024]  Info:    Received from ('192.168.137.10', 2333):{"status":"OK","reqTarget":"/set_abs_zero","property":null}
True
[2024.11.04 13:34:44.320.446]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/reboot", "property": "", "reply_enable": true}
[2024.11.04 13:34:44.322.374]  Info:    Received from ('192.168.137.10', 2333):{"status":"OK","reqTarget":"/reboot","property":""}

```

**Common Issues:**

If you encounter any issues when running this script, consider the following:

1.  Make sure you use a compatible Python version as recommended in the Quick Start Guide.
    
2.  Verify that your network configuration is correct and the FSA actuator is accessible.
    
## demo\_set\_eth\_recovery.py

**Code Description:**

This script is mainly used to demonstrate how to set the actuator's network recovery.

This script performs the following operations: `demo_set_eth_recovery.py`

1.  Use the `broadcast_func_with_filter` function to discover FSA actuators on the network and filter by actuator type.
    
2.  Use the `set_eth_recovery` function to set the actuator's network recovery.
        

**Usage:**

To run this script, follow these steps:`demo_set_eth_recovery.py`

1.  Make sure you have set up the Python environment and installed the FSA SDK as described in the Quick Start Guide.
    
2.  Open a terminal and navigate to the directory containing`demo_set_eth_recovery.py`
    
3.  Run the script using the following command:
    
    ```plaintext
    python demo_set_eth_recovery.py
    ```
    
4.  Running results (actual execution may differ from the demo, such as IP information):
    

```python
len3@len3-System-Product-Name:~/wiki-fsa/v2/example$ python3 ./demo_set_eth_recovery.py 
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v1
Log Already Existed ./log/2024/11/
[2024.11.04 13:46:51.055.208]  Info:    FSA start listening for broadcast...
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v2
Log Already Existed ./log/2024/11/
[2024.11.04 13:46:51.056.247]  Info:    FSA start listening for broadcast...
[2024.11.04 13:46:51.056.278]  Info:    FSA start listening for broadcast...


[2024.11.04 13:46:51.059.472]  Info:    Received from ('192.168.137.10', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA","serial_number":"4861061C0610","driver_version":"0.2.9.1","firmware_version":"0.3.9.9","connect_mode":"ETH","mac_address":"10:06:1C:06:61:4B","ip_address":"192.168.137.10","IP":"192.168.137.10"}


found servers
['192.168.137.10']
lookup Finished! 

[2024.11.04 13:46:54.060.707]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/set_eth_recovery", "reply_enable": true}
[2024.11.04 13:46:54.062.374]  Info:    Received from ('192.168.137.10', 2333):{"status":"OK","reqTarget":"/set_eth_recovery","property":null}
True

```

**Common Issues:**

If you encounter any issues when running this script, consider the following:

1.  Make sure you use a compatible Python version as recommended in the Quick Start Guide.
    
2.  Verify that your network configuration is correct and the FSA actuator is accessible.
    
## demo\_set\_eth\_timeout\_protect.py

**Code Description:**

This script is mainly used to demonstrate how to set the network timeout protection of the actuator.

This script performs the following operations: `demo_set_eth_timeout_protect.py`

1.  Use the `broadcast_func_with_filter` function to discover FSA actuators on the network and filter by actuator type.
    
2.  Use the `set_eth_timeout_protect` function to enable network timeout protection and set the timeout time to 1000ms.
        

**Usage:**

To run this script, follow these steps:`demo_set_eth_timeout_protect.py`

1.  Make sure you have set up the Python environment and installed the FSA SDK as described in the Quick Start Guide.
    
2.  Open a terminal and navigate to the directory containing`demo_set_eth_timeout_protect.py`
    
3.  Run the script using the following command:
    
    ```plaintext
    python demo_set_eth_timeout_protect.py
    ```
    
4.  Running results (actual execution may differ from the demo, such as IP information):
    

```python
len3@len3-System-Product-Name:~/wiki-fsa/v2/example$ python3 ./demo_set_eth_timeout_protect.py 
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v1
Log Already Existed ./log/2024/11/
[2024.11.04 17:30:34.142.725]  Info:    FSA start listening for broadcast...
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v2
Log Already Existed ./log/2024/11/
[2024.11.04 17:30:34.143.765]  Info:    FSA start listening for broadcast...
[2024.11.04 17:30:34.143.796]  Info:    FSA start listening for broadcast...


[2024.11.04 17:30:34.145.178]  Info:    Received from ('192.168.137.10', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA","serial_number":"4861061C0610","driver_version":"0.2.9.1","firmware_version":"0.3.10.5","connect_mode":"ETH","mac_address":"10:06:1C:06:61:4B","ip_address":"192.168.137.10","IP":"192.168.137.10"}


found servers
['192.168.137.10']
lookup Finished! 

[2024.11.04 17:30:37.146.500]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/set_eth_timeout_protect", "protect_enable": 0, "timeout_interval": 1000, "reply_enable": true}
[2024.11.04 17:30:37.147.705]  Info:    Received from ('192.168.137.10', 2333):{"status":"OK","reqTarget":"/set_eth_timeout_protect","property":null}
True

```

**Common Issues:**

If you encounter any issues when running this script, consider the following:

1.  Make sure you use a compatible Python version as recommended in the Quick Start Guide.
    
2.  Verify that your network configuration is correct and the FSA actuator is accessible.
    
## demo\_set\_control\_loop\_freq\_div.py

**Code Description:**

This script is mainly used to demonstrate how to modify the actuator's control frequency.

This script performs the following operations: `demo_set_control_loop_freq_div.py`

1.  Use the `broadcast_func_with_filter` function to discover FSA actuators on the network and filter by actuator type.
    
2.  Use the `set_control_loop_freq_div` function to modify the actuator's control frequency. The meanings of the function inputs `position_loop_freq_div`, `velocity_loop_freq_div`, and `PD_loop_freq_div` are to divide the control frequency of the corresponding control mode by this value to modify the control frequency.
        

**Usage:**

To run this script, follow these steps:`demo_set_control_loop_freq_div.py`

1.  Make sure you have set up the Python environment and installed the FSA SDK as described in the Quick Start Guide.
    
2.  Open a terminal and navigate to the directory containing`demo_set_control_loop_freq_div.py`
    
3.  Run the script using the following command:
    
    ```plaintext
    python demo_set_control_loop_freq_div.py
    ```
    
4.  Running results (actual execution may differ from the demo, such as IP information):
    

```python
len3@len3-System-Product-Name:~/wiki-fsa/v2/example$ python3 ./demo_set_control_loop_freq_div.py 
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v1
Log Already Existed ./log/2024/11/
[2024.11.06 10:41:28.723.825]  Info:    FSA start listening for broadcast...
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v2
Log Already Existed ./log/2024/11/
[2024.11.06 10:41:28.724.844]  Info:    FSA start listening for broadcast...
[2024.11.06 10:41:28.724.880]  Info:    FSA start listening for broadcast...


[2024.11.06 10:41:28.727.973]  Info:    Received from ('192.168.137.52', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA-0","serial_number":"A4D32BE0F908","driver_version":"0.2.8.35","firmware_version":"0.3.11.4","connect_mode":"ETH","mac_address":"08:F9:E0:2B:D3:A7","ip_address":"192.168.137.52","IP":"192.168.137.52"}


found servers
['192.168.137.52']
lookup Finished! 

[2024.11.06 10:41:31.728.735]  Info:    Send JSON Obj: {"method": "SET", "reply_enable": true, "reqTarget": "/set_control_loop_freq_div", "position_loop_freq_div": 1, "velocity_loop_freq_div": 1, "PD_loop_freq_div": 1}
[2024.11.06 10:41:31.730.439]  Info:    Received from ('192.168.137.52', 2333):{"status":"OK","reqTarget":"/set_control_loop_freq_div","property":null}
True

```

**Common Issues:**

If you encounter any issues when running this script, consider the following:

1.  Make sure you use a compatible Python version as recommended in the Quick Start Guide.
    
2.  Verify that your network configuration is correct and the FSA actuator is accessible.
    
## demo\_set\_torque\_limit\_max.py

**Code Description:**

This script is mainly used to demonstrate how to set the maximum torque of the actuator.

This script performs the following operations: `demo_set_torque_limit_max.py`

1.  Use the `broadcast_func_with_filter` function to discover FSA actuators on the network and filter by actuator type.
    
2.  Use the `set_torque_limit_max` function to set the maximum torque of the actuator.
        

**Usage:**

To run this script, follow these steps:`demo_set_torque_limit_max.py`

1.  Make sure you have set up the Python environment and installed the FSA SDK as described in the Quick Start Guide.
    
2.  Open a terminal and navigate to the directory containing`demo_set_torque_limit_max.py`
    
3.  Run the script using the following command:
    
    ```plaintext
    python demo_set_torque_limit_max.py
    ```
    
4.  Running results (actual execution may differ from the demo, such as IP information):
    

```python
len3@len3-System-Product-Name:~/wiki-fsa/v2/example$ python3 ./demo_set_torque_limit_max.py 
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v1
Log Already Existed ./log/2024/11/
[2024.11.06 10:45:28.214.635]  Info:    FSA start listening for broadcast...
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v2
Log Already Existed ./log/2024/11/
[2024.11.06 10:45:28.215.689]  Info:    FSA start listening for broadcast...
[2024.11.06 10:45:28.215.721]  Info:    FSA start listening for broadcast...


[2024.11.06 10:45:28.217.193]  Info:    Received from ('192.168.137.52', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA-0","serial_number":"A4D32BE0F908","driver_version":"0.2.8.35","firmware_version":"0.3.11.4","connect_mode":"ETH","mac_address":"08:F9:E0:2B:D3:A7","ip_address":"192.168.137.52","IP":"192.168.137.52"}


found servers
['192.168.137.52']
lookup Finished! 

[2024.11.06 10:45:31.218.649]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/torque_limit_max", "torque_limit_max": 30, "reply_enable": true}
[2024.11.06 10:45:31.219.960]  Info:    Received from ('192.168.137.52', 2333):{"status":"OK","reqTarget":"/torque_limit_max","property":null}
True

```

**Common Issues:**

If you encounter any issues when running this script, consider the following:

1.  Make sure you use a compatible Python version as recommended in the Quick Start Guide.
    
2.  Verify that your network configuration is correct and the FSA actuator is accessible.
    
## demo\_set\_inertia\_ff.py

**Code Description:**

This script is mainly used to demonstrate how to set the inertia compensation of the actuator.

This script performs the following operations: `demo_set_inertia_ff.py`

1.  Use the `broadcast_func_with_filter` function to discover FSA actuators on the network and filter by actuator type.
    
2.  Use the `set_inertia_ff` function to set the inertia compensation of the actuator.
        

**Usage:**

To run this script, follow these steps:`demo_set_inertia_ff.py`

1.  Make sure you have set up the Python environment and installed the FSA SDK as described in the Quick Start Guide.
    
2.  Open a terminal and navigate to the directory containing`demo_set_inertia_ff.py`
    
3.  Run the script using the following command:
    
    ```plaintext
    python demo_set_inertia_ff.py
    ```
    
4.  Running results (actual execution may differ from the demo, such as IP information):
    

```python
len3@len3-System-Product-Name:~/wiki-fsa/v2/example$ python3 ./demo_set_inertia_ff.py 
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v1
Log Already Existed ./log/2024/11/
[2024.11.06 10:54:03.575.090]  Info:    FSA start listening for broadcast...
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v2
Log Already Existed ./log/2024/11/
[2024.11.06 10:54:03.576.146]  Info:    FSA start listening for broadcast...
[2024.11.06 10:54:03.576.177]  Info:    FSA start listening for broadcast...


[2024.11.06 10:54:03.577.478]  Info:    Received from ('192.168.137.52', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA-0","serial_number":"A4D32BE0F908","driver_version":"0.2.8.35","firmware_version":"0.3.11.4","connect_mode":"ETH","mac_address":"08:F9:E0:2B:D3:A7","ip_address":"192.168.137.52","IP":"192.168.137.52"}


found servers
['192.168.137.52']
lookup Finished! 

[2024.11.06 10:54:06.578.890]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/inertia_ff", "inertia_ff": 0.5, "reply_enable": true}
[2024.11.06 10:54:06.580.401]  Info:    Received from ('192.168.137.52', 2333):{"status":"OK","reqTarget":"/inertia_ff","property":null}
True

```

**Common Issues:**

If you encounter any issues when running this script, consider the following:

1.  Make sure you use a compatible Python version as recommended in the Quick Start Guide.
    
2.  Verify that your network configuration is correct and the FSA actuator is accessible.
    
## demo\_get\_ntc\_temperature.py

**Code Description:**

This script is mainly used to demonstrate how to get the winding temperature and MOS temperature of the actuator.

This script performs the following operations: `demo_get_ntc_temperature.py`

1.  Use the `broadcast_func_with_filter` function to discover FSA actuators on the network and filter by actuator type.
    
2.  Use the `get_ntc_temperature` function to get the winding temperature and MOS temperature of the actuator.
        

**Usage:**

To run this script, follow these steps:`demo_get_ntc_temperature.py`

1.  Make sure you have set up the Python environment and installed the FSA SDK as described in the Quick Start Guide.
    
2.  Open a terminal and navigate to the directory containing`demo_get_ntc_temperature.py`
    
3.  Run the script using the following command:
    
    ```plaintext
    python demo_get_ntc_temperature.py
    ```
    
4.  Running results (actual execution may differ from the demo, such as IP information):
    

```python
len3@len3-System-Product-Name:~/wiki-fsa/v2/example$ python3 ./demo_get_ntc_temperature.py 
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v1
Log Already Existed ./log/2024/11/
[2024.11.05 14:16:45.269.404]  Info:    FSA start listening for broadcast...
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v2
Log Already Existed ./log/2024/11/
[2024.11.05 14:16:45.270.412]  Info:    FSA start listening for broadcast...
[2024.11.05 14:16:45.270.442]  Info:    FSA start listening for broadcast...


[2024.11.05 14:16:45.271.868]  Info:    Received from ('192.168.137.53', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA-0","serial_number":"A4D32BE0F908","driver_version":"0.2.8.35","firmware_version":"0.3.11.4","connect_mode":"ETH","mac_address":"08:F9:E0:2B:D3:A7","ip_address":"192.168.137.53","IP":"192.168.137.53"}


found servers
['192.168.137.53']
lookup Finished! 

[2024.11.05 14:16:48.273.155]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/get_ntc_temperature"}
[2024.11.05 14:16:48.276.090]  Info:    Received from ('192.168.137.53', 2333):{"status":"OK","reqTarget":"/get_ntc_temperature","property":null,"mos_temperature":36.29999924,"armature_temperature":-49.90000153}
mos_temperature = 36.299999, armature_temperature = -49.900002

```

**Common Issues:**

If you encounter any issues when running this script, consider the following:

1.  Make sure you use a compatible Python version as recommended in the Quick Start Guide.
    
2.  Verify that your network configuration is correct and the FSA actuator is accessible.
    
## demo\_control\_position\_mode.py

**Code Description:**

This script is mainly used to demonstrate how to perform position control operation on the actuator (Note: During control, the actuator will rotate. It is recommended to secure the actuator before calibration. If the current position is far from the zero point, the actuator will quickly return to the zero point during script execution).

This script performs the following operations: `demo_control_position_mode.py`

1.  Use the `broadcast_func_with_filter` function to discover FSA actuators on the network and filter by actuator type.
    
2.  Use the `get_state` function to retrieve the state of each detected actuator and display it in the terminal.
    
3.  Use the `get_config` function to retrieve the configuration of each detected actuator and display it in the terminal.
    
4.  Use the `get_pvc` function to retrieve the current position, velocity, and current (PVC) values of each detected actuator.
    
5.  Use the `set_position_control` function to set the current control position of each detected actuator to 0.0.
    
6.  Use the `set_enable` function to perform enable operation on each detected actuator, i.e., start the actuator.
    
7.  Use the `set_mode_of_operation` function to switch the operation mode of each detected actuator to position control.
    
8.  Use the `set_position_control` function to set the current control position of each detected actuator to 0.0 again.
    
9.  Use the `set_position_control` function to perform sin control on each detected actuator.
    
10.  Use the `set_disable` function to perform disable operation on each detected actuator.
    
11.  Finally, use the `set_mode_of_operation` function to switch the operation mode of each detected actuator to position control.
        

**Usage:**

To run this script, follow these steps:`demo_control_position_mode.py`

1.  Make sure you have set up the Python environment and installed the FSA SDK as described in the Quick Start Guide.
    
2.  Open a terminal and navigate to the directory containing`demo_control_position_mode.py`
    
3.  Run the script using the following command:
    
    ```plaintext
    python demo_control_position_mode.py
    
    ```
    
4.  Running results (actual execution may differ from the demo, such as IP information):
    

```python
len3@len3-System-Product-Name:~/wiki-fsa/v2/example$ python3 ./demo_control_position_mode.py 
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v1
Log Already Existed ./log/2024/10/
[2024.10.31 17:35:59.281.834]  Info:    FSA start listening for broadcast...
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v2
Log Already Existed ./log/2024/10/
[2024.10.31 17:35:59.282.815]  Info:    FSA start listening for broadcast...
[2024.10.31 17:35:59.282.845]  Info:    FSA start listening for broadcast...


[2024.10.31 17:35:59.285.325]  Info:    Received from ('192.168.137.101', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA","serial_number":"8C506D144B8C","driver_version":"0.1.10.7","firmware_version":"0.2.15.5","connect_mode":"ETH","mac_address":"8C:4B:14:6D:50:8F","ip_address":"192.168.137.101","IP":"192.168.137.101"}


found servers
['192.168.137.101']
lookup Finished! 

[2024.10.31 17:36:02.286.731]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/state", "property": ""}
[2024.10.31 17:36:02.287.973]  Info:    Received from ('192.168.137.101', 2333):{"status":"OK","reqTarget":"/state","property":"","state":0}
State = 0


[2024.10.31 17:36:03.288.232]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/config", "property": ""}
[2024.10.31 17:36:03.289.532]  Info:    Received from ('192.168.137.101', 2333):{"status":"OK","reqTarget":"/config","property":"","actuator_type":1,"actuator_direction":1,"actuator_reduction_ratio":31,"motor_type":4,"motor_hardware_type":3,"motor_vbus":48,"motor_direction":1,"motor_max_speed":3000,"motor_max_acceleration":60000,"motor_max_current":100}


[2024.10.31 17:36:04.289.931]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/measured", "position": true, "velocity": true, "current": true}
[2024.10.31 17:36:04.291.055]  Info:    Received from ('192.168.137.101', 2333):{"status":"OK","reqTarget":"/measured","property":null,"position":-0.019138644,"velocity":0.056626827,"current":0}
Position = -0.02, Velocity = 0.057, Current = 0.0000


[2024.10.31 17:36:05.301.525]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/position_control", "reply_enable": true, "position": 0.0, "velocity_ff": 0.0, "current_ff": 0.0}
[2024.10.31 17:36:05.302.895]  Info:    192.168.137.101 : Position = -0.02, Velocity = 0.080, Current = 0.0000 

```

**Common Issues:**

If you encounter any issues when running this script, consider the following:

1.  Make sure you use a compatible Python version as recommended in the Quick Start Guide.
    
2.  Verify that your network configuration is correct and the FSA actuator is accessible.
    
## demo\_control\_velocity\_mode.py

**Code Description:**

This script is mainly used to demonstrate how to perform velocity control operation on the actuator (Note: During control, the actuator will rotate. It is recommended to secure the actuator before calibration).

This script performs the following operations: `demo_control_velocity_mode.py`

1.  Use the `broadcast_func_with_filter` function to discover FSA actuators on the network and filter by actuator type.
    
2.  Use the `get_state` function to retrieve the state of each detected actuator and display it in the terminal.
    
3.  Use the `get_config` function to retrieve the configuration of each detected actuator and display it in the terminal.
    
4.  Use the `get_pvc` function to retrieve the current position, velocity, and current (PVC) values of each detected actuator.
    
5.  Use the `set_velocity_control` function to set the current control velocity of each detected actuator to 0.0.
    
6.  Use the `set_enable` function to perform enable operation on each detected actuator, i.e., start the actuator.
    
7.  Use the `set_mode_of_operation` function to switch the operation mode of each detected actuator to velocity control.
    
8.  Use the `set_velocity_control` function to perform sin control on each detected actuator.
    
9.  Use the `set_velocity_control` function to set the current control velocity of each detected actuator to 0.0 again.
    
10.  Use the `set_disable` function to perform disable operation on each detected actuator.
    
11.  Finally, use the `set_mode_of_operation` function to switch the operation mode of each detected actuator to velocity control.
        

**Usage:**

To run this script, follow these steps:`demo_control_velocity_mode.py`

1.  Make sure you have set up the Python environment and installed the FSA SDK as described in the Quick Start Guide.
    
2.  Open a terminal and navigate to the directory containing`demo_control_velocity_mode.py`
    
3.  Run the script using the following command:
    
    ```plaintext
    python demo_control_velocity_mode.py
    
    ```
    
4.  Running results (actual execution may differ from the demo, such as IP information):
    

```python
len3@len3-System-Product-Name:~/wiki-fsa/v2/example$ python3 ./demo_control_velocity_mode.py 
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v1
Log Already Existed ./log/2024/11/
[2024.11.01 15:22:45.519.533]  Info:    FSA start listening for broadcast...
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v2
Log Already Existed ./log/2024/11/
[2024.11.01 15:22:45.520.550]  Info:    FSA start listening for broadcast...
[2024.11.01 15:22:45.520.588]  Info:    FSA start listening for broadcast...


[2024.11.01 15:22:45.523.057]  Info:    Received from ('192.168.137.93', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA","serial_number":"8C506D144B8C","driver_version":"0.1.10.7","firmware_version":"0.2.15.5","connect_mode":"ETH","mac_address":"8C:4B:14:6D:50:8F","ip_address":"192.168.137.93","IP":"192.168.137.93"}


found servers
['192.168.137.93']
lookup Finished! 

[2024.11.01 15:22:48.523.836]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/state", "property": ""}
[2024.11.01 15:22:48.525.035]  Info:    Received from ('192.168.137.93', 2333):{"status":"OK","reqTarget":"/state","property":"","state":0}
State = 0


[2024.11.01 15:22:49.525.306]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/config", "property": ""}
[2024.11.01 15:22:49.526.559]  Info:    Received from ('192.168.137.93', 2333):{"status":"OK","reqTarget":"/config","property":"","actuator_type":1,"actuator_direction":1,"actuator_reduction_ratio":31,"motor_type":4,"motor_hardware_type":3,"motor_vbus":48,"motor_direction":1,"motor_max_speed":3000,"motor_max_acceleration":60000,"motor_max_current":100}


[2024.11.01 15:22:50.526.846]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/measured", "position": true, "velocity": true, "current": true}
[2024.11.01 15:22:50.527.956]  Info:    Received from ('192.168.137.93', 2333):{"status":"OK","reqTarget":"/measured","property":null,"position":0,"velocity":0.125966877,"current":0}
Position = 0.00, Velocity = 0.126, Current = 0.0000


[2024.11.01 15:22:51.538.301]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/velocity_control", "reply_enable": true, "velocity": 0.0, "current_ff": 0.0}
[2024.11.01 15:22:51.539.865]  Info:    192.168.137.93 : Position = 0.00, Velocity = -0.275, Current = 0.0000 



[2024.11.01 15:22:52.540.111]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/control_word", "property": "", "control_word": 15}
[2024.11.01 15:22:52.541.083]  Info:    Received from ('192.168.137.93', 2333):{"status":"OK","reqTarget":"/control_word","property":""}

```

**Common Issues:**

If you encounter any issues when running this script, consider the following:

1.  Make sure you use a compatible Python version as recommended in the Quick Start Guide.
    
2.  Verify that your network configuration is correct and the FSA actuator is accessible.
    
## demo\_control\_current\_mode.py

**Code Description:**

This script is mainly used to demonstrate how to perform current control operation on the actuator (Note: During control, the actuator will rotate. It is recommended to secure the actuator before calibration).

This script performs the following operations: `demo_control_current_mode.py`

1.  Use the `broadcast_func_with_filter` function to discover FSA actuators on the network and filter by actuator type.
    
2.  Use the `get_state` function to retrieve the state of each detected actuator and display it in the terminal.
    
3.  Use the `get_config` function to retrieve the configuration of each detected actuator and display it in the terminal.
    
4.  Use the `get_pvc` function to retrieve the current position, velocity, and current (PVC) values of each detected actuator.
    
5.  Use the `set_current_control` function to set the current control current of each detected actuator to 0.0.
    
6.  Use the `set_mode_of_operation` function to switch the operation mode of each detected actuator to current control.
    
7.  Use the `set_enable` function to perform enable operation on each detected actuator, i.e., start the actuator.
    
8.  Use the `set_current_control` function to set the current control current of each detected actuator to 0.0.
    
9.  Use the `set_velocity_control` function to run the current control loop for a specified duration, commanding a constant current value, which is 0.0 in the script.
    
10.  Use the `set_current_control` function to set the current control current of each detected actuator to 0.0 again.
    
11.  Use the `set_disable` function to perform disable operation on each detected actuator.
    
12.  Finally, use the `set_mode_of_operation` function to switch the operation mode of each detected actuator to velocity control.
        

**Usage:**

To run this script, follow these steps:`demo_control_current_mode.py`

1.  Make sure you have set up the Python environment and installed the FSA SDK as described in the Quick Start Guide.
    
2.  Open a terminal and navigate to the directory containing`demo_control_current_mode.py`
    
3.  Run the script using the following command:
    
    ```plaintext
    python demo_control_current_mode.py
    
    ```
    
4.  Running results (actual execution may differ from the demo, such as IP information):
    

```python
len3@len3-System-Product-Name:~/wiki-fsa/v2/example$ python3 ./demo_control_current_mode.py 
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v1
Log Already Existed ./log/2024/11/
[2024.11.01 15:36:31.719.880]  Info:    FSA start listening for broadcast...
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v2
Log Already Existed ./log/2024/11/
[2024.11.01 15:36:31.720.913]  Info:    FSA start listening for broadcast...
[2024.11.01 15:36:31.720.942]  Info:    FSA start listening for broadcast...


[2024.11.01 15:36:31.722.233]  Info:    Received from ('192.168.137.93', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA","serial_number":"8C506D144B8C","driver_version":"0.1.10.7","firmware_version":"0.2.15.5","connect_mode":"ETH","mac_address":"8C:4B:14:6D:50:8F","ip_address":"192.168.137.93","IP":"192.168.137.93"}


found servers
['192.168.137.93']
lookup Finished! 

[2024.11.01 15:36:34.723.014]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/state", "property": ""}
[2024.11.01 15:36:34.723.904]  Info:    Received from ('192.168.137.93', 2333):{"status":"OK","reqTarget":"/state","property":"","state":2}
State = 2
[2024.11.01 15:36:35.724.152]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/config", "property": ""}
[2024.11.01 15:36:35.725.317]  Info:    Received from ('192.168.137.93', 2333):{"status":"OK","reqTarget":"/config","property":"","actuator_type":1,"actuator_direction":1,"actuator_reduction_ratio":31,"motor_type":4,"motor_hardware_type":3,"motor_vbus":48,"motor_direction":1,"motor_max_speed":3000,"motor_max_acceleration":60000,"motor_max_current":100}
[2024.11.01 15:36:36.725.599]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/measured", "position": true, "velocity": true, "current": true}
[2024.11.01 15:36:36.726.725]  Info:    Received from ('192.168.137.93', 2333):{"status":"OK","reqTarget":"/measured","property":null,"position":-0.000708839,"velocity":-0.029984923,"current":0.020255003}
Position = -0.00, Velocity = -0.030, Current = 0.0203
[2024.11.01 15:36:37.737.073]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/current_control", "reply_enable": true, "current": 0.0}
[2024.11.01 15:36:37.738.249]  Info:    192.168.137.93 : Position = -0.00, Velocity = 0.009, Current = 0.0027 

[2024.11.01 15:36:38.738.493]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/mode_of_operation", "mode_of_operation": 4}
[2024.11.01 15:36:38.739.432]  Info:    Received from ('192.168.137.93', 2333):{"status":"OK","reqTarget":"/mode_of_operation","property":null}
[2024.11.01 15:36:39.739.686]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/control_word", "property": "", "control_word": 15}
[2024.11.01 15:36:39.740.656]  Info:    Received from ('192.168.137.93', 2333):{"status":"OK","reqTarget":"/control_word","property":""}
[2024.11.01 15:36:40.740.882]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/current_control", "reply_enable": true, "current": 0.0}
[2024.11.01 15:36:40.741.835]  Info:    192.168.137.93 : Position = 0.00, Velocity = -0.016, Current = 0.0510 

[2024.11.01 15:36:41.742.110]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/current_control", "reply_enable": true, "current": 0.0}
[2024.11.01 15:36:41.743.343]  Info:    192.168.137.93 : Position = 0.00, Velocity = -0.117, Current = 0.0179 

[2024.11.01 15:36:41.743.535]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/current_control", "reply_enable": true, "current": 0.0}
[2024.11.01 15:36:41.744.499]  Info:    192.168.137.93 : Position = 0.00, Velocity = -0.117, Current = 0.0179 

[2024.11.01 15:36:41.744.679]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/current_control", "reply_enable": true, "current": 0.0}
[2024.11.01 15:36:41.745.588]  Info:    192.168.137.93 : Position = 0.00, Velocity = 0.058, Current = -0.0019 

[2024.11.01 15:36:41.745.777]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/current_control", "reply_enable": true, "current": 0.0}
[2024.11.01 15:36:41.746.755]  Info:    192.168.137.93 : Position = 0.00, Velocity = 0.075, Current = -0.0326 

[2024.11.01 15:36:41.746.954]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/current_control", "reply_enable": true, "current": 0.0}
[2024.11.01 15:36:41.747.851]  Info:    192.168.137.93 : Position = 0.00, Velocity = 0.075, Current = -0.0326 

[2024.11.01 15:36:41.748.039]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/current_control", "reply_enable": true, "current": 0.0}
[2024.11.01 15:36:41.748.881]  Info:    192.168.137.93 : Position = 0.00, Velocity = -0.061, Current = 0.0377 

[2024.11.01 15:36:41.748.987]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/current_control", "reply_enable": true, "current": 0.0}
[2024.11.01 15:36:41.749.717]  Info:    192.168.137.93 : Position = 0.00, Velocity = -0.061, Current = 0.0377 

[2024.11.01 15:36:41.749.811]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/current_control", "reply_enable": true, "current": 0.0}
[2024.11.01 15:36:41.750.579]  Info:    192.168.137.93 : Position = 0.00, Velocity = -0.167, Current = -0.0105 

[2024.11.01 15:36:41.750.670]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/current_control", "reply_enable": true, "current": 0.0}
[2024.11.01 15:36:41.751.403]  Info:    192.168.137.93 : Position = 0.00, Velocity = -0.167, Current = -0.0105 

[2024.11.01 15:36:41.751.492]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/current_control", "reply_enable": true, "current": 0.0}
[2024.11.01 15:36:41.752.254]  Info:    192.168.137.93 : Position = 0.00, Velocity = -0.167, Current = -0.0105 

[2024.11.01 15:36:41.752.349]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/current_control", "reply_enable": true, "current": 0.0}
[2024.11.01 15:36:41.753.183]  Info:    192.168.137.93 : Position = 0.00, Velocity = -0.107, Current = 0.0116 

[2024.11.01 15:36:41.753.365]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/current_control", "reply_enable": true, "current": 0.0}
[2024.11.01 15:36:41.754.139]  Info:    192.168.137.93 : Position = 0.00, Velocity = -0.107, Current = 0.0116 

[2024.11.01 15:36:41.754.244]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/current_control", "reply_enable": true, "current": 0.0}
[2024.11.01 15:36:41.755.118]  Info:    192.168.137.93 : Position = -0.00, Velocity = 0.076, Current = 0.0004 

[2024.11.01 15:36:41.755.212]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/current_control", "reply_enable": true, "current": 0.0}
[2024.11.01 15:36:41.755.979]  Info:    192.168.137.93 : Position = -0.00, Velocity = 0.076, Current = 0.0004 

[2024.11.01 15:36:41.756.069]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/current_control", "reply_enable": true, "current": 0.0}
[2024.11.01 15:36:41.756.844]  Info:    192.168.137.93 : Position = -0.00, Velocity = -0.064, Current = 0.0620 

[2024.11.01 15:36:41.756.937]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/current_control", "reply_enable": true, "current": 0.0}
[2024.11.01 15:36:41.757.659]  Info:    192.168.137.93 : Position = -0.00, Velocity = -0.064, Current = 0.0620 

[2024.11.01 15:36:41.757.746]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/current_control", "reply_enable": true, "current": 0.0}
[2024.11.01 15:36:41.758.518]  Info:    192.168.137.93 : Position = -0.00, Velocity = -0.064, Current = 0.0620 

[2024.11.01 15:36:41.758.603]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/current_control", "reply_enable": true, "current": 0.0}
[2024.11.01 15:36:41.759.346]  Info:    192.168.137.93 : Position = 0.00, Velocity = -0.144, Current = -0.0105 

[2024.11.01 15:36:41.759.432]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/current_control", "reply_enable": true, "current": 0.0}
[2024.11.01 15:36:41.760.159]  Info:    192.168.137.93 : Position = 0.00, Velocity = -0.144, Current = -0.0105 

[2024.11.01 15:36:41.760.243]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/current_control", "reply_enable": true, "current": 0.0}
[2024.11.01 15:36:41.761.002]  Info:    192.168.137.93 : Position = 0.00, Velocity = 0.127, Current = 0.0289 

[2024.11.01 15:36:41.761.093]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/current_control", "reply_enable": true, "current": 0.0}
[2024.11.01 15:36:41.761.814]  Info:    192.168.137.93 : Position = 0.00, Velocity = 0.127, Current = 0.0289 

[2024.11.01 15:36:42.761.997]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/control_word", "property": "", "control_word": 6}
[2024.11.01 15:36:42.762.874]  Info:    Received from ('192.168.137.93', 2333):{"status":"OK","reqTarget":"/control_word","property":""}
[2024.11.01 15:36:43.763.089]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/mode_of_operation", "mode_of_operation": 4}
[2024.11.01 15:36:43.763.922]  Info:    Received from ('192.168.137.93', 2333):{"status":"OK","reqTarget":"/mode_of_operation","property":null}

```

**Common Issues:**

If you encounter any issues when running this script, consider the following:

1.  Make sure you use a compatible Python version as recommended in the Quick Start Guide.

2.  Verify that your network configuration is correct and the FSA actuator is accessible.

## demo\_control\_position\_ff\_mode.py

**Code Description:**

This script is mainly used to demonstrate how to operate FSA actuators using feedforward values in position control mode (Note: During control, the actuator will rotate. It is recommended to secure the actuator before calibration).

This script performs the following operations: `demo_control_position_ff_mode.py`

1.  Use the `broadcast_func_with_filter` function to discover FSA actuators on the network and filter by actuator type.
    
2.  Use the `get_state` function to retrieve the state of each detected actuator and display it in the terminal.
    
3.  Use the `get_config` function to retrieve the configuration of each detected actuator and display it in the terminal.
    
4.  Use the `get_pvc` function to retrieve the current position, velocity, and current (PVC) values of each detected actuator.
    
5.  Use the `set_position_control` function to set the current control position of each detected actuator to 0.0.
    
6.  Use the `set_enable` function to perform enable operation on each detected actuator, i.e., start the actuator.
    
7.  Use the `set_mode_of_operation` function to switch the operation mode of each detected actuator to position control.
    
8.  Use the `set_position_control` function to set the current control position of each detected actuator to 0.0.
    
9.  Use the `set_pid_param_imm` function to set the PID-related parameters of each detected actuator (the script's original parameters may be missing, causing script errors).
    
10.  Use the `set_position_control` function to control the actuator to move to a fixed position using feedforward values in position control mode for a specified duration.
    
11.  Use the `set_disable` function to perform disable operation on each detected actuator.
    
12.  Finally, use the `set_mode_of_operation` function to switch the operation mode of each detected actuator to position control.
    

**Usage:**

To run this script, follow these steps:`demo_control_position_ff_mode.py`

1.  Make sure you have set up the Python environment and installed the FSA SDK as described in the Quick Start Guide.

2.  Open a terminal and navigate to the directory containing`demo_control_position_ff_mode.py`

3.  Run the script using the following command:

```plaintext
python demo_control_position_ff_mode.py

```

4.  Running results (actual execution may differ from the demo, such as IP information):


```python
len3@len3-System-Product-Name:~/wiki-fsa/v2/example$ python3 ./demo_control_position_ff_mode.py 
current_workspace_path = 
/home/len3/wiki-fsa/v2/example
config_yaml_path = 
/home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v1
Log Already Existed ./log/2024/11/
[2024.11.02 10:21:05.132.593]  Info:    FSA start listening for broadcast...
current_workspace_path = 
/home/len3/wiki-fsa/v2/example
config_yaml_path = 
/home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v2
Log Already Existed ./log/2024/11/
[2024.11.02 10:21:05.133.605]  Info:    FSA start listening for broadcast...
[2024.11.02 10:21:05.133.636]  Info:    FSA start listening for broadcast...


[2024.11.02 10:21:05.135.189]  Info:    Received from ('192.168.137.93', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA","serial_number":"8C506D144B8C","driver_version":"0.1.10.7","firmware_version":"0.2.15.5","connect_mode":"ETH","mac_address":"8C:4B:14:6D:50:8F","ip_address":"192.168.137.93","IP":"192.168.137.93"}


found servers
['192.168.137.93']
lookup Finished! 

[2024.11.02 10:21:08.136.629]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/state", "property": ""}
[2024.11.02 10:21:08.137.728]  Info:    Received from ('192.168.137.93', 2333):{"status":"OK","reqTarget":"/state","property":"","state":2}
State = 2


[2024.11.02 10:21:09.138.033]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/config", "property": ""}
[2024.11.02 10:21:09.139.294]  Info:    Received from ('192.168.137.93', 2333):{"status":"OK","reqTarget":"/config","property":"","actuator_type":1,"actuator_direction":1,"actuator_reduction_ratio":31,"motor_type":4,"motor_hardware_type":3,"motor_vbus":48,"motor_direction":1,"motor_max_speed":3000,"motor_max_acceleration":60000,"motor_max_current":100}


[2024.11.02 10:21:10.139.573]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/measured", "position": true, "velocity": true, "current": true}
[2024.11.02 10:21:10.140.701]  Info:    Received from ('192.168.137.93', 2333):{"status":"OK","reqTarget":"/measured","property":null,"position":38.13693619,"velocity":0.070324488,"current":0.361414254}
Position = 38.14, Velocity = 0.070, Current = 0.3614


[2024.11.02 10:21:11.151.098]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/position_control", "reply_enable": true, "position": 0.0, "velocity_ff": 0.0, "current_ff": 0.0}
[2024.11.02 10:21:11.152.463]  Info:    192.168.137.93 : Position = 38.14, Velocity = 0.045, Current = 0.3907 



[2024.11.02 10:21:12.152.767]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/control_word", "property": "", "control_word": 15, "reply_enable": true}
[2024.11.02 10:21:12.153.852]  Info:    Received from ('192.168.137.93', 2333):{"status":"OK","reqTarget":"/control_word","property":""}

```

**Common Issues:**

If you encounter any issues when running this script, consider the following:

1.  Make sure you use a compatible Python version as recommended in the Quick Start Guide.

2.  Verify that your network configuration is correct and the FSA actuator is accessible.

## demo\_fast\_set\_enable.py

**Code Description:**

该脚本主要用于演示如何对执行器执行使能操作，即启动执行器。

This script performs the following operations:

1.  Use the `broadcast_func_with_filter` function to discover FSA actuators on the network and filter by actuator type.
    
2.  Use the `fast_set_enable` function to perform enable operation on each actuator.
    

**Usage:**

To run this script, follow these steps:

1.  Make sure you have set up the Python environment and installed fi\_fsa as described in the Quick Start Guide.

2.  Open a terminal and navigate to the directory containing this script.

3.  Run the script using the following command:

```plaintext
python demo_fast_set_enable.py
```

4.  Running results (actual execution may differ from the demo, such as IP information):


```python
current_workspace_path = 
D:\1_work\4_fsa\wiki-fsa\v2\example
config_yaml_path = 
D:\1_work\4_fsa\wiki-fsa\v2\example/config.yaml
#################################
config.yaml is: 
null
...

#################################
C:\Users\whl\AppData\Local\Programs\Python\Python312\Lib\site-packages\fi_fsa\v1
Log Already Existed C:\Users\whl\AppData\Local\Programs\Python\Python312\Lib\site-packages\fi_fsa\v1\log\2024\11\
[2024.11.02 15:26:23.014.914]  Info:    FSA start listening for broadcast...
current_workspace_path =
D:\1_work\4_fsa\wiki-fsa\v2\example
config_yaml_path =
D:\1_work\4_fsa\wiki-fsa\v2\example/config.yaml
#################################
config.yaml is:
null
...

#################################
C:\Users\whl\AppData\Local\Programs\Python\Python312\Lib\site-packages\fi_fsa\v2
Log Already Existed C:\Users\whl\AppData\Local\Programs\Python\Python312\Lib\site-packages\fi_fsa\v2\log\2024\11\
[2024.11.02 15:26:23.021.752]  Info:    FSA start listening for broadcast...
[2024.11.02 15:26:23.021.752]  Info:    FSA start listening for broadcast...


[2024.11.02 15:26:23.023.751]  Info:    Received from ('192.168.137.101', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA-0","serial_number":"F0BE83CD31E8","driver_version":"0.2.9.1","firmware_version":"0.3.9.9","connect_mode":"ETH","mac_address":"E8:31:CD:83:BE:F3","ip_address":"192.168.137.101","IP":"192.168.137.101"}


found servers
['192.168.137.101']
lookup Finished!

[2024.11.02 15:26:26.034.276]  Info:    192.168.137.101 : Send Data: b'\x01'
PS D:\1_work\4_fsa\wiki-fsa\v2\example> 
```

**Common Issues:**

If you encounter any issues when running this script, consider the following:

1.  Make sure you use a compatible Python version as recommended in the Quick Start Guide.

2.  Verify that your network configuration is correct and the FSA actuator is accessible.

## demo\_fast\_set\_ack\_enable.py

**Code Description:**

This script is mainly used to demonstrate how to perform enable operation on the actuator, i.e., start the actuator.

This script performs the following operations:

1.  Use the `broadcast_func_with_filter` function to discover FSA actuators on the network and filter by actuator type.
    
2.  Use the `fast_set_ack_enable` function to perform enable operation on each actuator.
    

**Usage:**

To run this script, follow these steps:

1.  Make sure you have set up the Python environment and installed fi\_fsa as described in the Quick Start Guide.

2.  Open a terminal and navigate to the directory containing this script.

3.  Run the script using the following command:

```plaintext
python demo_fast_set_ack_enable.py
```

4.  Running results (actual execution may differ from the demo, such as IP information):


```python
[2024.12.07 18:58:32.576.429]  Info:    FSA start listening for broadcast...
[2024.12.07 18:58:32.576.429]  Info:    FSA start listening for broadcast...


[2024.12.07 18:58:32.578.420]  Info:    Received from ('192.168.137.90', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA-0","serial_number":"F0BE83CD31E8","driver_version":"0.2.9.1","firmware_version":"0.3.12.16","connect_mode":"ETH","mac_address":"E8:31:CD:83:BE:F3","ip_address":"192.168.137.90","IP":"192.168.137.90"}


found servers
['192.168.137.90']
lookup Finished! 

[2024.12.07 18:58:35.584.321]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/", "property": ""}
[2024.12.07 18:58:35.586.593]  Info:    192.168.137.90 : Send Data: b'Q\x00\x00\x00\x01'
[2024.12.07 18:58:35.587.593]  Info:    192.168.137.90: Server received from ('192.168.137.90', 2335):b'Q\x00\x00\x00\x01\x00\x00\x00\x00'
cnt = 1, res = 0
```

**Common Issues:**

If you encounter any issues when running this script, consider the following:

1.  Make sure you use a compatible Python version as recommended in the Quick Start Guide.

2.  Verify that your network configuration is correct and the FSA actuator is accessible.

## demo\_fast\_set\_disable.py

**Code Description:**

This script is mainly used to demonstrate how to perform disable operation on the actuator.

This script performs the following operations:

1.  Use the `broadcast_func_with_filter` function to discover FSA actuators on the network and filter by actuator type.
    
2.  Use the `fast_set_disable` function to perform disable operation on each actuator.
    

**Usage:**

To run this script, follow these steps:

1.  Make sure you have set up the Python environment and installed fi\_fsa as described in the Quick Start Guide.

2.  Open a terminal and navigate to the directory containing this script.

3.  Run the script using the following command:

```plaintext
python demo_fast_set_disable.py
```

4.  Running results (actual execution may differ from the demo, such as IP information):


```python
current_workspace_path = 
D:\1_work\4_fsa\wiki-fsa\v2\example
config_yaml_path = 
D:\1_work\4_fsa\wiki-fsa\v2\example/config.yaml
#################################
config.yaml is: 
null
...

#################################
C:\Users\whl\AppData\Local\Programs\Python\Python312\Lib\site-packages\fi_fsa\v1
Log Already Existed C:\Users\whl\AppData\Local\Programs\Python\Python312\Lib\site-packages\fi_fsa\v1\log\2024\11\
[2024.11.02 16:02:52.974.325]  Info:    FSA start listening for broadcast...
current_workspace_path =
D:\1_work\4_fsa\wiki-fsa\v2\example
config_yaml_path =
D:\1_work\4_fsa\wiki-fsa\v2\example/config.yaml
#################################
config.yaml is:
null
...

#################################
C:\Users\whl\AppData\Local\Programs\Python\Python312\Lib\site-packages\fi_fsa\v2
Log Already Existed C:\Users\whl\AppData\Local\Programs\Python\Python312\Lib\site-packages\fi_fsa\v2\log\2024\11\
[2024.11.02 16:02:52.980.326]  Info:    FSA start listening for broadcast...
[2024.11.02 16:02:52.980.326]  Info:    FSA start listening for broadcast...


[2024.11.02 16:02:52.983.342]  Info:    Received from ('192.168.137.101', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA-0","serial_number":"F0BE83CD31E8","driver_version":"0.2.9.1","firmware_version":"0.3.9.9","connect_mode":"ETH","mac_address":"E8:31:CD:83:BE:F3","ip_address":"192.168.137.101","IP":"192.168.137.101"}


found servers
['192.168.137.101']
lookup Finished!

[2024.11.02 16:02:55.996.504]  Info:    192.168.137.101 : Send Data: b'\x02'
[2024.11.02 16:02:56.196.948]  Info:    192.168.137.101 : Send Data: b'\x02'
```

**Common Issues:**

If you encounter any issues when running this script, consider the following:

1.  Make sure you use a compatible Python version as recommended in the Quick Start Guide.

2.  Verify that your network configuration is correct and the FSA actuator is accessible.

## demo\_fast\_set\_ack\_disable.py

**Code Description:**

This script is mainly used to demonstrate how to perform disable operation on the actuator.

This script performs the following operations:

1.  Use the `broadcast_func_with_filter` function to discover FSA actuators on the network and filter by actuator type.
    
2.  Use the `fast_set_ack_disable` function to perform disable operation on each actuator.
    

**Usage:**

To run this script, follow these steps:

1.  Make sure you have set up the Python environment and installed fi\_fsa as described in the Quick Start Guide.

2.  Open a terminal and navigate to the directory containing this script.

3.  Run the script using the following command:

```plaintext
python demo_fast_set_ack_disable.py
```

4.  Running results (actual execution may differ from the demo, such as IP information):


```python
[2024.12.07 19:01:04.581.537]  Info:    FSA start listening for broadcast...
[2024.12.07 19:01:04.581.537]  Info:    FSA start listening for broadcast...


[2024.12.07 19:01:04.583.543]  Info:    Received from ('192.168.137.90', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA-0","serial_number":"F0BE83CD31E8","driver_version":"0.2.9.1","firmware_version":"0.3.12.16","connect_mode":"ETH","mac_address":"E8:31:CD:83:BE:F3","ip_address":"192.168.137.90","IP":"192.168.137.90"}


found servers
['192.168.137.90']
lookup Finished! 

[2024.12.07 19:01:07.590.611]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/", "property": ""}
[2024.12.07 19:01:07.592.850]  Info:    192.168.137.90 : Send Data: b'R\x00\x00\x00\x00'
[2024.12.07 19:01:07.593.850]  Info:    192.168.137.90: Server received from ('192.168.137.90', 2335):b'R\x00\x00\x00\x00\x00\x00\x00\x00'
cnt = 0, res = 0
[2024.12.07 19:01:07.794.760]  Info:    192.168.137.90 : Send Data: b'R\x00\x00\x00\x01'
[2024.12.07 19:01:07.794.760]  Info:    192.168.137.90: Server received from ('192.168.137.90', 2335):b'R\x00\x00\x00\x01\x00\x00\x00\x00'
cnt = 1, res = 0
```

**Common Issues:**

If you encounter any issues when running this script, consider the following:

1.  Make sure you use a compatible Python version as recommended in the Quick Start Guide.

2.  Verify that your network configuration is correct and the FSA actuator is accessible.

## demo\_fast\_set\_clear\_fault.py

**Code Description:**

This script is mainly used to demonstrate how to clear the actuator's error code.

This script performs the following operations:

1.  Use the `broadcast_func_with_filter` function to discover FSA actuators on the network and filter by actuator type.
    
2.  Use the `fast_set_clear_fault` function to clear the error code of each actuator.
    

**Usage:**

To run this script, follow these steps:

1.  Make sure you have set up the Python environment and installed fi\_fsa as described in the Quick Start Guide.

2.  Open a terminal and navigate to the directory containing this script.

3.  Run the script using the following command:

```plaintext
python demo_fast_set_clear_fault.py
```

4.  Running results (actual execution may differ from the demo, such as IP information):


**Common Issues:**

If you encounter any issues when running this script, consider the following:

1.  Make sure you use a compatible Python version as recommended in the Quick Start Guide.

2.  Verify that your network configuration is correct and the FSA actuator is accessible.

## demo\_fast\_set\_ack\_clear\_fault.py

**Code Description:**

This script is mainly used to demonstrate how to clear the actuator's error code.

This script performs the following operations:

1.  Use the `broadcast_func_with_filter` function to discover FSA actuators on the network and filter by actuator type.
    
2.  Use the `fast_set_ack_clear_fault` function to clear the error code of each actuator.
    

**Usage:**

To run this script, follow these steps:

1.  Make sure you have set up the Python environment and installed fi\_fsa as described in the Quick Start Guide.

2.  Open a terminal and navigate to the directory containing this script.

3.  Run the script using the following command:

```plaintext
python demo_fast_set_ack_clear_fault.py
```

4.  Running results (actual execution may differ from the demo, such as IP information):


```python
[2024.12.07 19:02:37.874.117]  Info:    FSA start listening for broadcast...
[2024.12.07 19:02:37.874.117]  Info:    FSA start listening for broadcast...


[2024.12.07 19:02:37.875.117]  Info:    Received from ('192.168.137.90', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA-0","serial_number":"F0BE83CD31E8","driver_version":"0.2.9.1","firmware_version":"0.3.12.16","connect_mode":"ETH","mac_address":"E8:31:CD:83:BE:F3","ip_address":"192.168.137.90","IP":"192.168.137.90"}


found servers
['192.168.137.90']
lookup Finished! 

[2024.12.07 19:02:40.878.294]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/", "property": ""}
[2024.12.07 19:02:40.880.801]  Info:    192.168.137.90 : Send Data: b'S\x00\x00\x00\x00'
[2024.12.07 19:02:40.880.801]  Info:    192.168.137.90: Server received from ('192.168.137.90', 2335):b'S\x00\x00\x00\x00\x00\x00\x00\x00'
cnt = 0, res = 0
[2024.12.07 19:02:41.082.033]  Info:    192.168.137.90 : Send Data: b'S\x00\x00\x00\x01'
[2024.12.07 19:02:41.082.537]  Info:    192.168.137.90: Server received from ('192.168.137.90', 2335):b'S\x00\x00\x00\x01\x00\x00\x00\x00'
cnt = 1, res = 0
[2024.12.07 19:02:41.283.158]  Info:    192.168.137.90 : Send Data: b'S\x00\x00\x00\x02'
[2024.12.07 19:02:41.283.158]  Info:    192.168.137.90: Server received from ('192.168.137.90', 2335):b'S\x00\x00\x00\x02\x00\x00\x00\x00'
cnt = 2, res = 0
```

**Common Issues:**

If you encounter any issues when running this script, consider the following:

1.  Make sure you use a compatible Python version as recommended in the Quick Start Guide.

2.  Verify that your network configuration is correct and the FSA actuator is accessible.

## demo\_fast\_set\_pd\_position.py 

**Code Description:**

This script is mainly used to demonstrate how to set the position, feedforward velocity, and feedforward current of the actuator in PD mode.

This script performs the following operations:

1.  Use the `broadcast_func_with_filter` function to discover FSA actuators on the network and filter by actuator type.
    
2.  Use the `fast_set_pd_control` function to set the target position for each actuator.
    

**Usage:**

To run this script, follow these steps:

1.  Make sure you have set up the Python environment and installed fi\_fsa as described in the Quick Start Guide.

2.  Open a terminal and navigate to the directory containing this script.

3.  Run the script using the following command:

```plaintext
python demo_fast_set_pd_position.py
```

4.  Running results (actual execution may differ from the demo, such as IP information):


```python
C:\Users\whl\AppData\Local\Programs\Python\Python312\Lib\site-packages\fi_fsa\v2
Log Already Existed C:\Users\whl\AppData\Local\Programs\Python\Python312\Lib\site-packages\fi_fsa\v2\log\2024\11\
[2024.11.16 20:16:32.148.634]  Info:    FSA start listening for broadcast...
[2024.11.16 20:16:32.148.634]  Info:    FSA start listening for broadcast...


[2024.11.16 20:16:32.150.634]  Info:    Received from ('192.168.137.54', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA-0","serial_number":"F0BE83CD31E8","driver_version":"0.2.9.1","firmware_version":"0.3.12.3","connect_mode":"ETH","mac_address":"E8:31:CD:83:BE:F3","ip_address":"192.168.137.54","IP":"192.168.137.54"}


found servers
['192.168.137.54']
lookup Finished! 

[2024.11.16 20:16:35.152.065]  Info:    192.168.137.54 : Send Data: b'\x0e\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'

```

**Common Issues:**

If you encounter any issues when running this script, consider the following:

1.  Make sure you use a compatible Python version as recommended in the Quick Start Guide.

2.  Verify that your network configuration is correct and the FSA actuator is accessible.

## demo\_fast\_set\_ack\_pd\_position.py

**Code Description:**

This script is mainly used to demonstrate how to set the position, feedforward velocity, and feedforward current of the actuator in PD mode.

This script performs the following operations:

1.  Use the `broadcast_func_with_filter` function to discover FSA actuators on the network and filter by actuator type.
    
2.  Use the `fast_set_ack_pd_control` function to set the target position for each actuator.
    

**Usage:**

To run this script, follow these steps:

1.  Make sure you have set up the Python environment and installed fi\_fsa as described in the Quick Start Guide.

2.  Open a terminal and navigate to the directory containing this script.

3.  Run the script using the following command:

```plaintext
python demo_fast_set_ack_pd_position.py
```

4.  Running results (actual execution may differ from the demo, such as IP information):


```python
[2024.12.28 19:19:03.716.108]  Info:    FSA start listening for broadcast...
[2024.12.28 19:19:03.716.108]  Info:    FSA start listening for broadcast...


[2024.12.28 19:19:03.720.105]  Info:    Received from ('192.168.137.101', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA","serial_number":"F0BE83CD31E8","driver_version":"0.2.10.11","firmware_version":"0.3.12.17","connect_mode":"ETH","mac_address":"E8:31:CD:83:BE:F3","ip_address":"192.168.137.101","IP":"192.168.137.101"}


found servers
['192.168.137.101']
lookup Finished! 

[2024.12.28 19:19:06.723.440]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/", "property": ""}
[2024.12.28 19:19:06.726.460]  Info:    192.168.137.101 : Send Data: b'^\x00\x00\x00\x01\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
[2024.12.28 19:19:06.727.465]  Info:    192.168.137.101: Server received from ('192.168.137.101', 2335):b'^\x00\x00\x00\x01\x00\x00\x00\x00'
cnt = 1, res = 0
```

**Common Issues:**

If you encounter any issues when running this script, consider the following:

1.  Make sure you use a compatible Python version as recommended in the Quick Start Guide.

2.  Verify that your network configuration is correct and the FSA actuator is accessible.

## demo\_fast\_set\_pid\_imm.py 

**Code Description:**

This script is mainly used to demonstrate how to set temporary PID parameters for the actuator.

This script performs the following operations:

1.  Use the `broadcast_func_with_filter` function to discover FSA actuators on the network and filter by actuator type.
    
2.  Use the `fast_set_pid_imm` function to set temporary PID parameters for each actuator.
    

**Usage:**

To run this script, follow these steps:

1.  Make sure you have set up the Python environment and installed fi\_fsa as described in the Quick Start Guide.

2.  Open a terminal and navigate to the directory containing this script.

3.  Run the script using the following command:

```plaintext
python demo_fast_set_pid_imm.py
```

4.  Running results (actual execution may differ from the demo, such as IP information):


```python
C:\Users\whl\AppData\Local\Programs\Python\Python312\Lib\site-packages\fi_fsa\v2
Log Already Existed C:\Users\whl\AppData\Local\Programs\Python\Python312\Lib\site-packages\fi_fsa\v2\log\2024\11\
[2024.11.16 20:55:45.824.959]  Info:    FSA start listening for broadcast...
[2024.11.16 20:55:45.824.959]  Info:    FSA start listening for broadcast...


[2024.11.16 20:55:45.826.937]  Info:    Received from ('192.168.137.54', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA-0","serial_number":"F0BE83CD31E8","driver_version":"0.2.9.1","firmware_version":"0.3.12.3","connect_mode":"ETH","mac_address":"E8:31:CD:83:BE:F3","ip_address":"192.168.137.54","IP":"192.168.137.54"}


found servers
['192.168.137.54']
lookup Finished! 

[2024.11.16 20:55:48.828.571]  Info:    192.168.137.54 : Send Data: b'\xa0\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
```

**Common Issues:**

If you encounter any issues when running this script, consider the following:

1.  Make sure you use a compatible Python version as recommended in the Quick Start Guide.

2.  Verify that your network configuration is correct and the FSA actuator is accessible.

## demo\_fast\_set\_ack\_pid\_imm.py

**Code Description:**

This script is mainly used to demonstrate how to set temporary PID parameters for the actuator.

This script performs the following operations:

1.  Use the `broadcast_func_with_filter` function to discover FSA actuators on the network and filter by actuator type.
    
2.  Use the `fast_set_ack_pid_imm` function to set temporary PID parameters for each actuator.
    

**Usage:**

To run this script, follow these steps:

1.  Make sure you have set up the Python environment and installed fi\_fsa as described in the Quick Start Guide.

2.  Open a terminal and navigate to the directory containing this script.

3.  Run the script using the following command:

```plaintext
python demo_fast_set_ack_pid_imm.py
```

4.  Running results (actual execution may differ from the demo, such as IP information):


```python
[2024.12.28 19:32:48.238.072]  Info:    FSA start listening for broadcast...
[2024.12.28 19:32:48.238.072]  Info:    FSA start listening for broadcast...


[2024.12.28 19:32:48.239.072]  Info:    Received from ('192.168.137.101', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA","serial_number":"F0BE83CD31E8","driver_version":"0.2.10.11","firmware_version":"0.3.12.17","connect_mode":"ETH","mac_address":"E8:31:CD:83:BE:F3","ip_address":"192.168.137.101","IP":"192.168.137.101"}


found servers
['192.168.137.101']
lookup Finished! 

[2024.12.28 19:32:51.248.922]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/", "property": ""}
[2024.12.28 19:32:51.251.647]  Info:    192.168.137.101 : Send Data: b'`\x00\x00\x00\x01\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
[2024.12.28 19:32:51.252.518]  Info:    192.168.137.101: Server received from ('192.168.137.101', 2335):b'`\x00\x00\x00\x01\x00\x00\x00\x00'
cnt = 1, res = 0
```

**Common Issues:**

If you encounter any issues when running this script, consider the following:

1.  Make sure you use a compatible Python version as recommended in the Quick Start Guide.

2.  Verify that your network configuration is correct and the FSA actuator is accessible.

## demo\_fast\_set\_pd\_imm.py 

**Code Description:**

This script is mainly used to demonstrate how to set temporary PD parameters for the actuator.

This script performs the following operations:

1.  Use the `broadcast_func_with_filter` function to discover FSA actuators on the network and filter by actuator type.
    
2.  Use the `fast_set_pd_imm` function to set temporary PD parameters for each actuator.
    

**Usage:**

To run this script, follow these steps:

1.  Make sure you have set up the Python environment and installed fi\_fsa as described in the Quick Start Guide.

2.  Open a terminal and navigate to the directory containing this script.

3.  Run the script using the following command:

```plaintext
python demo_fast_set_pd_imm.py
```

4.  Running results (actual execution may differ from the demo, such as IP information):


```python
C:\Users\whl\AppData\Local\Programs\Python\Python312\Lib\site-packages\fi_fsa\v2
Log Already Existed C:\Users\whl\AppData\Local\Programs\Python\Python312\Lib\site-packages\fi_fsa\v2\log\2024\11\
[2024.11.16 21:22:10.542.682]  Info:    FSA start listening for broadcast...
[2024.11.16 21:22:10.542.682]  Info:    FSA start listening for broadcast...


[2024.11.16 21:22:10.544.719]  Info:    Received from ('192.168.137.54', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA-0","serial_number":"F0BE83CD31E8","driver_version":"0.2.9.1","firmware_version":"0.3.12.3","connect_mode":"ETH","mac_address":"E8:31:CD:83:BE:F3","ip_address":"192.168.137.54","IP":"192.168.137.54"}


found servers
['192.168.137.54']
lookup Finished! 

[2024.11.16 21:22:13.548.673]  Info:    192.168.137.54 : Send Data: b'\xa1\x00\x00\x00\x00\x00\x00\x00\x00'
```

**Common Issues:**

If you encounter any issues when running this script, consider the following:

1.  Make sure you use a compatible Python version as recommended in the Quick Start Guide.

2.  Verify that your network configuration is correct and the FSA actuator is accessible.

## demo\_fast\_set\_ack\_pd\_imm.py

**Code Description:**

This script is mainly used to demonstrate how to set temporary PD parameters for the actuator.

This script performs the following operations:

1.  Use the `broadcast_func_with_filter` function to discover FSA actuators on the network and filter by actuator type.
    
2.  Use the `fast_set_ack_pd_imm` function to set temporary PD parameters for each actuator.
    

**Usage:**

To run this script, follow these steps:

1.  Make sure you have set up the Python environment and installed fi\_fsa as described in the Quick Start Guide.

2.  Open a terminal and navigate to the directory containing this script.

3.  Run the script using the following command:

```plaintext
python demo_fast_set_ack_pd_imm.py
```

4.  Running results (actual execution may differ from the demo, such as IP information):


```python
[2024.12.28 20:03:49.607.938]  Info:    FSA start listening for broadcast...
[2024.12.28 20:03:49.607.938]  Info:    FSA start listening for broadcast...


[2024.12.28 20:03:49.609.939]  Info:    Received from ('192.168.137.101', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA","serial_number":"F0BE83CD31E8","driver_version":"0.2.10.11","firmware_version":"0.3.12.17","connect_mode":"ETH","mac_address":"E8:31:CD:83:BE:F3","ip_address":"192.168.137.101","IP":"192.168.137.101"}


found servers
['192.168.137.101']
lookup Finished! 

[2024.12.28 20:03:52.625.572]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/", "property": ""}
[2024.12.28 20:03:52.627.924]  Info:    192.168.137.101 : Send Data: b'a\x00\x00\x00\x01\x00\x00\x00\x00\x00\x00\x00\x00'
[2024.12.28 20:03:52.628.906]  Info:    192.168.137.101: Server received from ('192.168.137.101', 2335):b'a\x00\x00\x00\x01\x00\x00\x00\x00'
cnt = 1, res = 0
```

**Common Issues:**

If you encounter any issues when running this script, consider the following:

1.  Make sure you use a compatible Python version as recommended in the Quick Start Guide.

2.  Verify that your network configuration is correct and the FSA actuator is accessible.

## demo\_fast\_set\_control\_loop\_freq\_div.py 

**Code Description:**

This script is mainly used to demonstrate how to set the control frequency division coefficient of the actuator.

This script performs the following operations:

1.  Use the `broadcast_func_with_filter` function to discover FSA actuators on the network and filter by actuator type.
    
2.  Use the `fast_set_control_loop_freq_div` function to set the control frequency division coefficient for each actuator.
    

**Usage:**

To run this script, follow these steps:

1.  Make sure you have set up the Python environment and installed fi\_fsa as described in the Quick Start Guide.

2.  Open a terminal and navigate to the directory containing this script.

3.  Run the script using the following command:

```plaintext
python demo_fast_set_control_loop_freq_div.py 
```

4.  Running results (actual execution may differ from the demo, such as IP information):


```python
[2024.12.30 11:42:41.285.564]  Info:    FSA start listening for broadcast...
[2024.12.30 11:42:41.285.564]  Info:    FSA start listening for broadcast...


[2024.12.30 11:42:41.288.548]  Info:    Received from ('192.168.137.101', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA","serial_number":"F0BE83CD31E8","driver_version":"0.2.10.11","firmware_version":"0.3.12.17","connect_mode":"ETH","mac_address":"E8:31:CD:83:BE:F3","ip_address":"192.168.137.101","IP":"192.168.137.101"}


found servers
['192.168.137.101']
lookup Finished! 

[2024.12.30 11:42:44.299.396]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/", "property": ""}
[2024.12.30 11:42:44.301.675]  Info:    192.168.137.101 : Send Data: b'f\x00\x00\x00\x01F\x1c@\x00F\x1c@\x00F\x1c@\x00'
[2024.12.30 11:42:44.302.658]  Info:    192.168.137.101: Server received from ('192.168.137.101', 2335):b'f\x00\x00\x00\x01\x00\x00\x00\x00'
cnt = 1, res = 0
```

**Common Issues:**

If you encounter any issues when running this script, consider the following:

1.  Make sure you use a compatible Python version as recommended in the Quick Start Guide.

2.  Verify that your network configuration is correct and the FSA actuator is accessible.

## demo\_fast\_set\_ack\_control\_loop\_freq\_div.py

**Code Description:**

This script is mainly used to demonstrate how to set the control frequency division coefficient of the actuator.

This script performs the following operations:

1.  Use the `broadcast_func_with_filter` function to discover FSA actuators on the network and filter by actuator type.
    
2.  Use the `fast_set_ack_control_loop_freq_div` function to set the control frequency division coefficient for each actuator.
    

**Usage:**

To run this script, follow these steps:

1.  Make sure you have set up the Python environment and installed fi\_fsa as described in the Quick Start Guide.

2.  Open a terminal and navigate to the directory containing this script.

3.  Run the script using the following command:

```plaintext
python demo_fast_set_ack_control_loop_freq_div.py
```

4.  Running results (actual execution may differ from the demo, such as IP information):


```python
[2024.12.28 20:09:53.279.328]  Info:    FSA start listening for broadcast...
[2024.12.28 20:09:53.279.328]  Info:    FSA start listening for broadcast...


[2024.12.28 20:09:53.281.961]  Info:    Received from ('192.168.137.101', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA","serial_number":"F0BE83CD31E8","driver_version":"0.2.10.11","firmware_version":"0.3.12.17","connect_mode":"ETH","mac_address":"E8:31:CD:83:BE:F3","ip_address":"192.168.137.101","IP":"192.168.137.101"}


found servers
['192.168.137.101']
lookup Finished! 

[2024.12.28 20:09:56.292.176]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/", "property": ""}
[2024.12.28 20:09:56.294.479]  Info:    192.168.137.101 : Send Data: b'b\x00\x00\x00\x01?\x80\x00\x00?\x80\x00\x00?\x80\x00\x00'
[2024.12.28 20:09:56.295.477]  Info:    192.168.137.101: Server received from ('192.168.137.101', 2335):b'b\x00\x00\x00\x01\x00\x00\x00\x00'
cnt = 1, res = 0
```

**Common Issues:**

If you encounter any issues when running this script, consider the following:

1.  Make sure you use a compatible Python version as recommended in the Quick Start Guide.

2.  Verify that your network configuration is correct and the FSA actuator is accessible.

## demo\_fast\_set\_friction\_FFD.py 

**Code Description:**

This script is mainly used to demonstrate how to configure actuator friction compensation.

This script performs the following operations:

1.  Use the `broadcast_func_with_filter` function to discover FSA actuators on the network and filter by actuator type.
    
2.  Use the `fast_set_friction_FFD` function to configure friction compensation for each actuator.
    

**Usage:**

To run this script, follow these steps:

1.  Make sure you have set up the Python environment and installed fi\_fsa as described in the Quick Start Guide.

2.  Open a terminal and navigate to the directory containing this script.

3.  Run the script using the following command:

```plaintext
python demo_fast_set_friction_FFD.py
```

4.  Running results (actual execution may differ from the demo, such as IP information):


```python
C:\Users\whl\AppData\Local\Programs\Python\Python312\Lib\site-packages\fi_fsa\v2
Log Already Existed C:\Users\whl\AppData\Local\Programs\Python\Python312\Lib\site-packages\fi_fsa\v2\log\2024\11\
[2024.11.16 21:57:14.094.351]  Info:    FSA start listening for broadcast...
[2024.11.16 21:57:14.094.351]  Info:    FSA start listening for broadcast...


[2024.11.16 21:57:14.097.036]  Info:    Received from ('192.168.137.54', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA-0","serial_number":"F0BE83CD31E8","driver_version":"0.2.9.1","firmware_version":"0.3.12.3","connect_mode":"ETH","mac_address":"E8:31:CD:83:BE:F3","ip_address":"192.168.137.54","IP":"192.168.137.54"}


found servers
['192.168.137.54']
lookup Finished! 

[2024.11.16 21:57:17.100.794]  Info:    192.168.137.54 : Send Data: b'\xa3\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
[2024.11.16 21:57:17.101.654]  Info:    192.168.137.54: Server received from ('192.168.137.54', 2335):b'\xa3'
b'\xa3'
```

**Common Issues:**

If you encounter any issues when running this script, consider the following:

1.  Make sure you use a compatible Python version as recommended in the Quick Start Guide.

2.  Verify that your network configuration is correct and the FSA actuator is accessible.

## demo\_fast\_set\_ack\_friction\_FFD.py

**Code Description:**

This script is mainly used to demonstrate how to configure actuator friction compensation.

This script performs the following operations:

1.  Use the `broadcast_func_with_filter` function to discover FSA actuators on the network and filter by actuator type.
    
2.  Use the `fast_set_ack_friction_FFD` function to configure friction compensation for each actuator.
    

**Usage:**

To run this script, follow these steps:

1.  Make sure you have set up the Python environment and installed fi\_fsa as described in the Quick Start Guide.

2.  Open a terminal and navigate to the directory containing this script.

3.  Run the script using the following command:

```plaintext
python demo_fast_set_ack_friction_FFD.py
```

4.  Running results (actual execution may differ from the demo, such as IP information):


```python
[2024.12.28 20:21:45.749.986]  Info:    FSA start listening for broadcast...
[2024.12.28 20:21:45.749.986]  Info:    FSA start listening for broadcast...


[2024.12.28 20:21:45.753.017]  Info:    Received from ('192.168.137.101', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA","serial_number":"F0BE83CD31E8","driver_version":"0.2.10.11","firmware_version":"0.3.12.17","connect_mode":"ETH","mac_address":"E8:31:CD:83:BE:F3","ip_address":"192.168.137.101","IP":"192.168.137.101"}


found servers
['192.168.137.101']
lookup Finished! 

[2024.12.28 20:21:48.755.818]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/", "property": ""}
[2024.12.28 20:21:48.758.848]  Info:    192.168.137.101 : Send Data: b'c\x00\x00\x00\x01\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00?\x80\x00\x00'
[2024.12.28 20:21:48.759.832]  Info:    192.168.137.101: Server received from ('192.168.137.101', 2335):b'c\x00\x00\x00\x01\x00\x00\x00\x00'
cnt = 1, res = 0
```

**Common Issues:**

If you encounter any issues when running this script, consider the following:

1.  Make sure you use a compatible Python version as recommended in the Quick Start Guide.

2.  Verify that your network configuration is correct and the FSA actuator is accessible.

## demo\_fast\_set\_ack\_setpvc\_timeout\_protect.py

**Code Description:**

This script is mainly used to demonstrate how to configure actuator setpvc timeout protection.

This script performs the following operations:

1.  Use the `broadcast_func_with_filter` function to discover FSA actuators on the network and filter by actuator type.
    
2.  Use the `fast_set_ack_setpvc_timeout_protect` function to set setpvc timeout protection for each actuator.
    

**Usage:**

To run this script, follow these steps:

1.  Make sure you have set up the Python environment and installed fi\_fsa as described in the Quick Start Guide.

2.  Open a terminal and navigate to the directory containing this script.

3.  Run the script using the following command:

```plaintext
python demo_fast_set_ack_setpvc_timeout_protect.py
```

4.  Running results (actual execution may differ from the demo, such as IP information):


```python
[2024.12.30 09:54:12.954.932]  Info:    FSA start listening for broadcast...
[2024.12.30 09:54:12.954.932]  Info:    FSA start listening for broadcast...


[2024.12.30 09:54:12.957.931]  Info:    Received from ('192.168.137.101', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA","serial_number":"F0BE83CD31E8","driver_version":"0.2.10.11","firmware_version":"0.3.12.17","connect_mode":"ETH","mac_address":"E8:31:CD:83:BE:F3","ip_address":"192.168.137.101","IP":"192.168.137.101"}


found servers
['192.168.137.101']
lookup Finished! 

[2024.12.30 09:54:15.974.027]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/", "property": ""}
1
[2024.12.30 09:54:15.976.050]  Info:    192.168.137.101 : Send Data: b'd\x00\x00\x00\x01\x00\x00\x00\x01\x00\x00\x00d\x00\x00\x00\x01\x00\x00\x00\x00\x00\x00\x00\x01'
[2024.12.30 09:54:15.977.031]  Info:    192.168.137.101: Server received from ('192.168.137.101', 2335):b'd\x00\x00\x00\x01\x00\x00\x00\x00'
cnt = 1, res = 0
```

**Common Issues:**

If you encounter any issues when running this script, consider the following:

1.  Make sure you use a compatible Python version as recommended in the Quick Start Guide.

2.  Verify that your network configuration is correct and the FSA actuator is accessible.

## demo\_fast\_set\_ack\_interface\_filter\_fc.py

**Code Description:**

This script is mainly used to demonstrate how to configure the filter cutoff frequency of the actuator feedback PVC.

This script performs the following operations:

1.  Use the `broadcast_func_with_filter` function to discover FSA actuators on the network and filter by actuator type.
    
2.  Use the `fast_set_ack_interface_filter_fc` function to configure the filter cutoff frequency of the feedback PVC for each actuator.
    

**Usage:**

To run this script, follow these steps:

1.  Make sure you have set up the Python environment and installed fi\_fsa as described in the Quick Start Guide.

2.  Open a terminal and navigate to the directory containing this script.

3.  Run the script using the following command:

```plaintext
python demo_fast_set_ack_setpvc_timeout_protect.py
```

4.  Running results (actual execution may differ from the demo, such as IP information):


```python
[2024.12.30 09:54:12.954.932]  Info:    FSA start listening for broadcast...
[2024.12.30 09:54:12.954.932]  Info:    FSA start listening for broadcast...


[2024.12.30 09:54:12.957.931]  Info:    Received from ('192.168.137.101', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA","serial_number":"F0BE83CD31E8","driver_version":"0.2.10.11","firmware_version":"0.3.12.17","connect_mode":"ETH","mac_address":"E8:31:CD:83:BE:F3","ip_address":"192.168.137.101","IP":"192.168.137.101"}


found servers
['192.168.137.101']
lookup Finished! 

[2024.12.30 09:54:15.974.027]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/", "property": ""}
1
[2024.12.30 09:54:15.976.050]  Info:    192.168.137.101 : Send Data: b'd\x00\x00\x00\x01\x00\x00\x00\x01\x00\x00\x00d\x00\x00\x00\x01\x00\x00\x00\x00\x00\x00\x00\x01'
[2024.12.30 09:54:15.977.031]  Info:    192.168.137.101: Server received from ('192.168.137.101', 2335):b'd\x00\x00\x00\x01\x00\x00\x00\x00'
cnt = 1, res = 0
```

**Common Issues:**

If you encounter any issues when running this script, consider the following:

1.  Make sure you use a compatible Python version as recommended in the Quick Start Guide.

2.  Verify that your network configuration is correct and the FSA actuator is accessible.

## demo\_fast\_set\_ack\_setpvc\_protect\_clear.py

**Code Description:**

This script is mainly used to demonstrate how to configure actuator setpvc protection status clearing.

This script performs the following operations:

1.  Use the `broadcast_func_with_filter` function to discover FSA actuators on the network and filter by actuator type.
    
2.  Use the `fast_set_ack_setpvc_protect_clear` function to configure setpvc protection status clearing for each actuator.
    

**Usage:**

To run this script, follow these steps:

1.  Make sure you have set up the Python environment and installed fi\_fsa as described in the Quick Start Guide.

2.  Open a terminal and navigate to the directory containing this script.

3.  Run the script using the following command:

```plaintext
python demo_fast_set_ack_setpvc_protect_clear.py
```

4.  Running results (actual execution may differ from the demo, such as IP information):


```python
[2024.12.30 13:28:16.443.834]  Info:    FSA start listening for broadcast...
[2024.12.30 13:28:16.443.834]  Info:    FSA start listening for broadcast...


[2024.12.30 13:28:16.446.812]  Info:    Received from ('192.168.137.101', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA","serial_number":"F0BE83CD31E8","driver_version":"0.2.10.11","firmware_version":"0.3.12.17","connect_mode":"ETH","mac_address":"E8:31:CD:83:BE:F3","ip_address":"192.168.137.101","IP":"192.168.137.101"}


found servers
['192.168.137.101']
lookup Finished! 

[2024.12.30 13:28:19.454.411]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/", "property": ""}
1
[2024.12.30 13:28:19.457.445]  Info:    192.168.137.101 : Send Data: b'e\x00\x00\x00\x01\x00\x00\x00\x00'
[2024.12.30 13:28:19.458.425]  Info:    192.168.137.101: Server received from ('192.168.137.101', 2335):b'e\x00\x00\x00\x01\x00\x00\x00\x00'
cnt = 1, res = 0
```

**Common Issues:**

If you encounter any issues when running this script, consider the following:

1.  Make sure you use a compatible Python version as recommended in the Quick Start Guide.

2.  Verify that your network configuration is correct and the FSA actuator is accessible.

## demo\_fast\_get\_pvc.py 

**Code Description:**

This script is mainly used to demonstrate how to get the actuator's current position, velocity, and current.

This script performs the following operations:

1.  Use the `broadcast_func_with_filter` function to discover FSA actuators on the network and filter by actuator type.
    
2.  Use the `fast_get_pvc` function to get the actuator's current position, velocity, and current.
    

**Usage:**

To run this script, follow these steps:

1.  Make sure you have set up the Python environment and installed fi\_fsa as described in the Quick Start Guide.

2.  Open a terminal and navigate to the directory containing this script.

3.  Run the script using the following command:

```plaintext
python demo_fast_get_pvc.py 
```

4.  Running results (actual execution may differ from the demo, such as IP information):


```python
C:\Users\whl\AppData\Local\Programs\Python\Python312\Lib\site-packages\fi_fsa\v2
Log Already Existed C:\Users\whl\AppData\Local\Programs\Python\Python312\Lib\site-packages\fi_fsa\v2\log\2024\11\
[2024.11.18 14:21:43.399.693]  Info:    FSA start listening for broadcast...
[2024.11.18 14:21:43.399.693]  Info:    FSA start listening for broadcast...


[2024.11.18 14:21:43.402.695]  Info:    Received from ('192.168.137.54', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA-0","serial_number":"F0BE83CD31E8","driver_version":"0.2.9.1","firmware_version":"0.3.12.3","connect_mode":"ETH","mac_address":"E8:31:CD:83:BE:F3","ip_address":"192.168.137.54","IP":"192.168.137.54"}


found servers
['192.168.137.54']
lookup Finished! 

[2024.11.18 14:21:46.404.556]  Info:    192.168.137.54 : Send Data: b'\x1a'
[2024.11.18 14:21:46.405.062]  Info:    192.168.137.54: Server received from ('192.168.137.54', 2335):b'\x1a@\x16\x04l=\xb5\xdf\x98\x00\x00\x00\x00'
Position = 2.344020, Velocity = 0.088805, Current = 0.0000
[2024.11.18 14:21:46.407.569]  Info:    192.168.137.54 : Send Data: b'\x1a'
[2024.11.18 14:21:46.407.569]  Info:    192.168.137.54: Server received from ('192.168.137.54', 2335):b'\x1a@\x15\xff\xfe\xbd9;\x1d\x00\x00\x00\x00'
Position = 2.343750, Velocity = -0.045222, Current = 0.0000
[2024.11.18 14:21:46.410.396]  Info:    192.168.137.54 : Send Data: b'\x1a'
[2024.11.18 14:21:46.410.396]  Info:    192.168.137.54: Server received from ('192.168.137.54', 2335):b'\x1a@\x16\x03\xdb\xbe\x10\x96\x1e\x00\x00\x00\x00'
Position = 2.343985, Velocity = -0.141198, Current = 0.0000
[2024.11.18 14:21:46.413.121]  Info:    192.168.137.54 : Send Data: b'\x1a'
[2024.11.18 14:21:46.413.121]  Info:    192.168.137.54: Server received from ('192.168.137.54', 2335):b'\x1a@\x16\x00\xef\xbd\xa4\xaa|\x00\x00\x00\x00'
Position = 2.343807, Velocity = -0.080403, Current = 0.0000
```

**Common Issues:**

If you encounter any issues when running this script, consider the following:

1.  Make sure you use a compatible Python version as recommended in the Quick Start Guide.

2.  Verify that your network configuration is correct and the FSA actuator is accessible.

## demo\_fast\_get\_foc\_target\_pvc.py 

**Code Description:**

This script is mainly used to demonstrate how to get the target position, velocity, and current information of the actuator's underlying FOC.

This script performs the following operations:

1.  Use the `broadcast_func_with_filter` function to discover FSA actuators on the network and filter by actuator type.
    
2.  Use the `fast_get_foc_target_pvc` function to get the target position, velocity, and current information of the actuator's underlying FOC.
    

**Usage:**

To run this script, follow these steps:

1.  Make sure you have set up the Python environment and installed fi\_fsa as described in the Quick Start Guide.

2.  Open a terminal and navigate to the directory containing this script.

3.  Run the script using the following command:

```plaintext
python demo_fast_get_foc_target_pvc.py
```

4.  Running results (actual execution may differ from the demo, such as IP information):


```python
C:\Users\whl\AppData\Local\Programs\Python\Python312\Lib\site-packages\fi_fsa\v2
Log Already Existed C:\Users\whl\AppData\Local\Programs\Python\Python312\Lib\site-packages\fi_fsa\v2\log\2024\11\
[2024.11.18 14:36:08.385.112]  Info:    FSA start listening for broadcast...
[2024.11.18 14:36:08.385.112]  Info:    FSA start listening for broadcast...


[2024.11.18 14:36:08.387.111]  Info:    Received from ('192.168.137.54', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA-0","serial_number":"F0BE83CD31E8","driver_version":"0.2.9.1","firmware_version":"0.3.12.3","connect_mode":"ETH","mac_address":"E8:31:CD:83:BE:F3","ip_address":"192.168.137.54","IP":"192.168.137.54"}


found servers
['192.168.137.54']
lookup Finished! 

[2024.11.18 14:36:11.394.328]  Info:    192.168.137.54 : Send Data: b'\x1f'
[2024.11.18 14:36:11.394.328]  Info:    192.168.137.54: Server received from ('192.168.137.54', 2335):b'\x1f\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
Position = 0.000000, Velocity = 0.000000, Current = 0.0000
[2024.11.18 14:36:11.595.690]  Info:    192.168.137.54 : Send Data: b'\x1f'
[2024.11.18 14:36:11.595.690]  Info:    192.168.137.54: Server received from ('192.168.137.54', 2335):b'\x1f\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
Position = 0.000000, Velocity = 0.000000, Current = 0.0000
[2024.11.18 14:36:11.796.942]  Info:    192.168.137.54 : Send Data: b'\x1f'
[2024.11.18 14:36:11.796.942]  Info:    192.168.137.54: Server received from ('192.168.137.54', 2335):b'\x1f\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
Position = 0.000000, Velocity = 0.000000, Current = 0.0000
[2024.11.18 14:36:11.997.908]  Info:    192.168.137.54 : Send Data: b'\x1f'
[2024.11.18 14:36:11.997.908]  Info:    192.168.137.54: Server received from ('192.168.137.54', 2335):b'\x1f\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
Position = 0.000000, Velocity = 0.000000, Current = 0.0000

```

**Common Issues:**

If you encounter any issues when running this script, consider the following:

1.  Make sure you use a compatible Python version as recommended in the Quick Start Guide.

2.  Verify that your network configuration is correct and the FSA actuator is accessible.

## demo\_fast\_get\_pvct.py

**Code Description:**

This script is mainly used to demonstrate how to get the actuator's current position, velocity, current, and torque.

This script performs the following operations:

1.  Use the `broadcast_func_with_filter` function to discover FSA actuators on the network and filter by actuator type.
    
2.  Use the `fast_get_pvct` function to get the actuator's current position, velocity, current, and torque.
    

**Usage:**

To run this script, follow these steps:

1.  Make sure you have set up the Python environment and installed fi\_fsa as described in the Quick Start Guide.

2.  Open a terminal and navigate to the directory containing this script.

3.  Run the script using the following command:

```plaintext
python demo_fast_get_pvct.py
```

4.  Running results (actual execution may differ from the demo, such as IP information):


```python
C:\Users\whl\AppData\Local\Programs\Python\Python312\Lib\site-packages\fi_fsa\v2
Log Already Existed C:\Users\whl\AppData\Local\Programs\Python\Python312\Lib\site-packages\fi_fsa\v2\log\2024\11\
[2024.11.18 14:43:15.402.617]  Info:    FSA start listening for broadcast...
[2024.11.18 14:43:15.402.617]  Info:    FSA start listening for broadcast...


[2024.11.18 14:43:15.405.755]  Info:    Received from ('192.168.137.54', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA-0","serial_number":"F0BE83CD31E8","driver_version":"0.2.9.1","firmware_version":"0.3.12.3","connect_mode":"ETH","mac_address":"E8:31:CD:83:BE:F3","ip_address":"192.168.137.54","IP":"192.168.137.54"}


found servers
['192.168.137.54']
lookup Finished! 

[2024.11.18 14:43:18.412.669]  Info:    192.168.137.54 : Send Data: b'\x1d'
[2024.11.18 14:43:18.412.669]  Info:    192.168.137.54: Server received from ('192.168.137.54', 2335):b'\x1d@\x16\x04s>\x8a\xc5\xc3\x00\x00\x00\x00\xbd\xfd\xa6\xa0'
Position = 2.344022, Velocity = 0.271040, Current = 0.000000, Torque = -0.123853
[2024.11.18 14:43:18.614.096]  Info:    192.168.137.54 : Send Data: b'\x1d'
[2024.11.18 14:43:18.614.606]  Info:    192.168.137.54: Server received from ('192.168.137.54', 2335):b'\x1d@\x16\x01\x92\xbd4\x8a:\x00\x00\x00\x00\xb9%d)'
Position = 2.343846, Velocity = -0.044077, Current = 0.000000, Torque = -0.000158
[2024.11.18 14:43:18.815.447]  Info:    192.168.137.54 : Send Data: b'\x1d'
[2024.11.18 14:43:18.815.447]  Info:    192.168.137.54: Server received from ('192.168.137.54', 2335):b'\x1d@\x15\xfei>\x02;\x8d\x00\x00\x00\x00=\xe1\xedk'
Position = 2.343653, Velocity = 0.127180, Current = 0.000000, Torque = 0.110316
[2024.11.18 14:43:19.016.410]  Info:    192.168.137.54 : Send Data: b'\x1d'
[2024.11.18 14:43:19.016.410]  Info:    192.168.137.54: Server received from ('192.168.137.54', 2335):b'\x1d@\x16\x05\xbb\xbe\x808(\x00\x00\x00\x00=i\xca\xd4'
Position = 2.344100, Velocity = -0.250428, Current = 0.000000, Torque = 0.057078
[2024.11.18 14:43:19.217.864]  Info:    192.168.137.54 : Send Data: b'\x1d'
```

**Common Issues:**

If you encounter any issues when running this script, consider the following:

1.  Make sure you use a compatible Python version as recommended in the Quick Start Guide.

2.  Verify that your network configuration is correct and the FSA actuator is accessible.

## demo\_fast\_get\_error.py

**Code Description:**

This script is mainly used to demonstrate how to get the actuator's error code.

This script performs the following operations:

1.  Use the `broadcast_func_with_filter` function to discover FSA actuators on the network and filter by actuator type.
    
2.  Use the `fast_get_error` function to get the actuator's error code.
    

**Usage:**

To run this script, follow these steps:

1.  Make sure you have set up the Python environment and installed fi\_fsa as described in the Quick Start Guide.

2.  Open a terminal and navigate to the directory containing this script.

3.  Run the script using the following command:

```plaintext
python demo_fast_get_error.py
```

4.  Running results (actual execution may differ from the demo, such as IP information):


```python
C:\Users\whl\AppData\Local\Programs\Python\Python312\Lib\site-packages\fi_fsa\v2
Log Already Existed C:\Users\whl\AppData\Local\Programs\Python\Python312\Lib\site-packages\fi_fsa\v2\log\2024\11\
[2024.11.18 14:48:32.067.444]  Info:    FSA start listening for broadcast...
[2024.11.18 14:48:32.067.444]  Info:    FSA start listening for broadcast...


[2024.11.18 14:48:32.069.443]  Info:    Received from ('192.168.137.54', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA-0","serial_number":"F0BE83CD31E8","driver_version":"0.2.9.1","firmware_version":"0.3.12.3","connect_mode":"ETH","mac_address":"E8:31:CD:83:BE:F3","ip_address":"192.168.137.54","IP":"192.168.137.54"}


found servers
['192.168.137.54']
lookup Finished! 

[2024.11.18 14:48:35.080.749]  Info:    192.168.137.54 : Send Data: b'\x1b'
[2024.11.18 14:48:35.081.520]  Info:    192.168.137.54: Server received from ('192.168.137.54', 2335):b'\x1b\x00\x00\x00\x10\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
Error =[16, 0, 0, 0, 0, 0, 0, 0]
[2024.11.18 14:48:35.282.117]  Info:    192.168.137.54 : Send Data: b'\x1b'
[2024.11.18 14:48:35.282.117]  Info:    192.168.137.54: Server received from ('192.168.137.54', 2335):b'\x1b\x00\x00\x00\x10\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
Error =[16, 0, 0, 0, 0, 0, 0, 0]
[2024.11.18 14:48:35.483.065]  Info:    192.168.137.54 : Send Data: b'\x1b'
[2024.11.18 14:48:35.483.065]  Info:    192.168.137.54: Server received from ('192.168.137.54', 2335):b'\x1b\x00\x00\x00\x10\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
Error =[16, 0, 0, 0, 0, 0, 0, 0]
[2024.11.18 14:48:35.683.977]  Info:    192.168.137.54 : Send Data: b'\x1b'
[2024.11.18 14:48:35.683.977]  Info:    192.168.137.54: Server received from ('192.168.137.54', 2335):b'\x1b\x00\x00\x00\x10\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
Error =[16, 0, 0, 0, 0, 0, 0, 0]
```

**Common Issues:**

If you encounter any issues when running this script, consider the following:

1.  Make sure you use a compatible Python version as recommended in the Quick Start Guide.

2.  Verify that your network configuration is correct and the FSA actuator is accessible.

## demo\_fast\_get\_pvct\_error.py

**Code Description:**

This script is mainly used to demonstrate how to get actuator position, velocity, current, torque, and error code.

This script performs the following operations:

1.  Use the `broadcast_func_with_filter` function to discover FSA actuators on the network and filter by actuator type.
    
2.  Use the `fast_get_pvct_error` function to get actuator position, velocity, current, torque, and error code.
    

**Usage:**

To run this script, follow these steps:

1.  Make sure you have set up the Python environment and installed fi\_fsa as described in the Quick Start Guide.

2.  Open a terminal and navigate to the directory containing this script.

3.  Run the script using the following command:

```plaintext
python demo_fast_get_pvct_error.py
```

4.  Running results (actual execution may differ from the demo, such as IP information):


```python
[2024.12.30 14:03:31.306.617]  Info:    FSA start listening for broadcast...
[2024.12.30 14:03:31.306.617]  Info:    FSA start listening for broadcast...


[2024.12.30 14:03:31.309.616]  Info:    Received from ('192.168.137.101', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA","serial_number":"F0BE83CD31E8","driver_version":"0.2.10.11","firmware_version":"0.3.12.17","connect_mode":"ETH","mac_address":"E8:31:CD:83:BE:F3","ip_address":"192.168.137.101","IP":"192.168.137.101"}


found servers
['192.168.137.101']
lookup Finished! 

[2024.12.30 14:03:34.321.228]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/", "property": ""}
[2024.12.30 14:03:34.323.525]  Info:    192.168.137.101 : Send Data: b'!'
[2024.12.30 14:03:34.324.506]  Info:    192.168.137.101: Server received from ('192.168.137.101', 2335):b'!\xbc\xa9[\xe6\xc2\x83\xe0\x90\x80\x00\x00\x00:\x05.<\x00\x00\x00\x10\x00\x00\x00\x01\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x01'
Position = -0.020674, Velocity = -65.938599, Current = -0.000000, Torque = 0.000508
Error =[16, 1, 0, 0, 0, 0, 0, 1]
[2024.12.30 14:03:34.525.921]  Info:    192.168.137.101 : Send Data: b'!'
[2024.12.30 14:03:34.525.921]  Info:    192.168.137.101: Server received from ('192.168.137.101', 2335):b'!\xbcDH\xdd\xc1\xe1\xd2c\x80\x00\x00\x00\xb9\x85H\x97\x00\x00\x00\x10\x00\x00\x00\x01\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x01'
Position = -0.011980, Velocity = -28.227728, Current = -0.000000, Torque = -0.000254
Error =[16, 1, 0, 0, 0, 0, 0, 1]
[2024.12.30 14:03:34.727.323]  Info:    192.168.137.101 : Send Data: b'!'
[2024.12.30 14:03:34.727.323]  Info:    192.168.137.101: Server received from ('192.168.137.101', 2335):b'!\xbc?O\xa8\xc2\xa6gY\x80\x00\x00\x00\xba\x18\xceN\x00\x00\x00\x10\x00\x00\x00\x01\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x01'
Position = -0.011677, Velocity = -83.201851, Current = -0.000000, Torque = -0.000583
Error =[16, 1, 0, 0, 0, 0, 0, 1]
[2024.12.30 14:03:34.928.815]  Info:    192.168.137.101 : Send Data: b'!'
[2024.12.30 14:03:34.928.815]  Info:    192.168.137.101: Server received from ('192.168.137.101', 2335):b'!<\xb4IU@\xf9\x05\x06\x80\x00\x00\x00\xba\xbb3)\x00\x00\x00\x10\x00\x00\x00\x01\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x01'
Position = 0.022008, Velocity = 7.781863, Current = -0.000000, Torque = -0.001428
Error =[16, 1, 0, 0, 0, 0, 0, 1]
[2024.12.30 14:03:35.130.164]  Info:    192.168.137.101 : Send Data: b'!'
[2024.12.30 14:03:35.131.181]  Info:    192.168.137.101: Server received from ('192.168.137.101', 2335):b'!=04%C\x066l\x80\x00\x00\x00\xba<\t6\x00\x00\x00\x10\x00\x00\x00\x01\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x01'
Position = 0.043018, Velocity = 134.212585, Current = -0.000000, Torque = -0.000717
Error =[16, 1, 0, 0, 0, 0, 0, 1]
[2024.12.30 14:03:35.331.343]  Info:    192.168.137.101 : Send Data: b'!'
[2024.12.30 14:03:35.331.343]  Info:    192.168.137.101: Server received from ('192.168.137.101', 2335):b'!=\x1f\x7f\xd3C\x056F\x80\x00\x00\x008\xbfH}\x00\x00\x00\x10\x00\x00\x00\x01\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x01'
Position = 0.038940, Velocity = 133.212006, Current = -0.000000, Torque = 0.000091
Error =[16, 1, 0, 0, 0, 0, 0, 1]
[2024.12.30 14:03:35.532.835]  Info:    192.168.137.101 : Send Data: b'!'
[2024.12.30 14:03:35.532.835]  Info:    192.168.137.101: Server received from ('192.168.137.101', 2335):b'!\xbd,N&\xc2\xdb\xe2\x8c\x80\x00\x00\x00:\x07\xd8H\x00\x00\x00\x10\x00\x00\x00\x01\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x01'
Position = -0.042067, Velocity = -109.942474, Current = -0.000000, Torque = 0.000518
Error =[16, 1, 0, 0, 0, 0, 0, 1]
```

**Common Issues:**

If you encounter any issues when running this script, consider the following:

1.  Make sure you use a compatible Python version as recommended in the Quick Start Guide.

2.  Verify that your network configuration is correct and the FSA actuator is accessible.

## demo\_fast\_get\_friction\_FFD.py

**Code Description:**

This script is mainly used to demonstrate how to get actuator friction compensation parameters.

This script performs the following operations:

1.  Use the `broadcast_func_with_filter` function to discover FSA actuators on the network and filter by actuator type.
    
2.  Use the `fast_get_friction_FFD` function to get actuator friction compensation parameters.
    

**Usage:**

To run this script, follow these steps:

1.  Make sure you have set up the Python environment and installed fi\_fsa as described in the Quick Start Guide.

2.  Open a terminal and navigate to the directory containing this script.

3.  Run the script using the following command:

```plaintext
python demo_fast_get_friction_FFD.py
```

4.  Running results (actual execution may differ from the demo, such as IP information):


```python
[2024.12.30 14:11:39.890.762]  Info:    FSA start listening for broadcast...
[2024.12.30 14:11:39.890.762]  Info:    FSA start listening for broadcast...


[2024.12.30 14:11:39.892.818]  Info:    Received from ('192.168.137.101', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA","serial_number":"F0BE83CD31E8","driver_version":"0.2.10.11","firmware_version":"0.3.12.17","connect_mode":"ETH","mac_address":"E8:31:CD:83:BE:F3","ip_address":"192.168.137.101","IP":"192.168.137.101"}


found servers
['192.168.137.101']
lookup Finished! 

[2024.12.30 14:11:42.904.089]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/", "property": ""}
[2024.12.30 14:11:42.906.294]  Info:    192.168.137.101 : Send Data: b' '
[2024.12.30 14:11:42.910.311]  Info:    192.168.137.101: Server received from ('192.168.137.101', 2335):b' \x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
friction_FFD_SET=0, friction_FFD_DeadSpeedK=0.000000, friction_FFD_DeadSpeed=0.000000, friction_FFD_Fs=0.000000,friction_FFD_Fc=0.000000, friction_FFD_B=0.000000, friction_FFD_percent=0.000000

```

**Common Issues:**

If you encounter any issues when running this script, consider the following:

1.  Make sure you use a compatible Python version as recommended in the Quick Start Guide.

2.  Verify that your network configuration is correct and the FSA actuator is accessible.

## demo\_fast\_get\_ntc\_temp.py

**Code Description:**

This script is mainly used to demonstrate how to get actuator MOS and winding temperature.

This script performs the following operations:

1.  Use the `broadcast_func_with_filter` function to discover FSA actuators on the network and filter by actuator type.
    
2.  Use the `fast_get_ntc_temp` function to get actuator MOS and winding temperature.
    

**Usage:**

To run this script, follow these steps:

1.  Make sure you have set up the Python environment and installed fi\_fsa as described in the Quick Start Guide.

2.  Open a terminal and navigate to the directory containing this script.

3.  Run the script using the following command:

```plaintext
python demo_fast_get_ntc_temp.py
```

4.  Running results (actual execution may differ from the demo, such as IP information):


```python
Log Already Existed C:\Users\whl\AppData\Local\Programs\Python\Python312\Lib\site-packages\fi_fsa\v2\log\2024\12\
[2024.12.30 14:15:54.654.751]  Info:    FSA start listening for broadcast...
[2024.12.30 14:15:54.654.751]  Info:    FSA start listening for broadcast...


[2024.12.30 14:15:54.656.755]  Info:    Received from ('192.168.137.101', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA","serial_number":"F0BE83CD31E8","driver_version":"0.2.10.11","firmware_version":"0.3.12.17","connect_mode":"ETH","mac_address":"E8:31:CD:83:BE:F3","ip_address":"192.168.137.101","IP":"192.168.137.101"}


found servers
['192.168.137.101']
lookup Finished! 

[2024.12.30 14:15:57.658.234]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/", "property": ""}
[2024.12.30 14:15:57.660.566]  Info:    192.168.137.101 : Send Data: b'"'
[2024.12.30 14:15:57.661.547]  Info:    192.168.137.101: Server received from ('192.168.137.101', 2335):b'"A\xf5\x99\x9a\xc2G\x99\x9a'
mos_temperature = 30.700001, armature_temperature = -49.900002
[2024.12.30 14:15:57.862.809]  Info:    192.168.137.101 : Send Data: b'"'
[2024.12.30 14:15:57.863.813]  Info:    192.168.137.101: Server received from ('192.168.137.101', 2335):b'"A\xf5\x99\x9a\xc2G\x99\x9a'
mos_temperature = 30.700001, armature_temperature = -49.900002
[2024.12.30 14:15:58.064.968]  Info:    192.168.137.101 : Send Data: b'"'
[2024.12.30 14:15:58.064.968]  Info:    192.168.137.101: Server received from ('192.168.137.101', 2335):b'"A\xf5\x99\x9a\xc2G\x99\x9a'
mos_temperature = 30.700001, armature_temperature = -49.900002
[2024.12.30 14:15:58.266.119]  Info:    192.168.137.101 : Send Data: b'"'
[2024.12.30 14:15:58.266.119]  Info:    192.168.137.101: Server received from ('192.168.137.101', 2335):b'"A\xf6ff\xc2G\x99\x9a'
mos_temperature = 30.799999, armature_temperature = -49.900002
[2024.12.30 14:15:58.467.551]  Info:    192.168.137.101 : Send Data: b'"'
[2024.12.30 14:15:58.467.551]  Info:    192.168.137.101: Server received from ('192.168.137.101', 2335):b'"A\xf6ff\xc2G\x99\x9a'
mos_temperature = 30.799999, armature_temperature = -49.900002
[2024.12.30 14:15:58.668.558]  Info:    192.168.137.101 : Send Data: b'"'
[2024.12.30 14:15:58.668.558]  Info:    192.168.137.101: Server received from ('192.168.137.101', 2335):b'"A\xf5\x99\x9a\xc2G\x99\x9a'
mos_temperature = 30.700001, armature_temperature = -49.900002
[2024.12.30 14:15:58.869.813]  Info:    192.168.137.101 : Send Data: b'"'
[2024.12.30 14:15:58.869.813]  Info:    192.168.137.101: Server received from ('192.168.137.101', 2335):b'"A\xf5\x99\x9a\xc2G\x99\x9a'
mos_temperature = 30.700001, armature_temperature = -49.900002
```

**Common Issues:**

If you encounter any issues when running this script, consider the following:

1.  Make sure you use a compatible Python version as recommended in the Quick Start Guide.

2.  Verify that your network configuration is correct and the FSA actuator is accessible.

## demo\_fast\_get\_vbus.py

**Code Description:**

This script is mainly used to demonstrate how to get actuator bus voltage.

This script performs the following operations:

1.  Use the `broadcast_func_with_filter` function to discover FSA actuators on the network and filter by actuator type.
    
2.  Use the `fast_get_vbus` function to get actuator bus voltage.
    

**Usage:**

To run this script, follow these steps:

1.  Make sure you have set up the Python environment and installed fi\_fsa as described in the Quick Start Guide.

2.  Open a terminal and navigate to the directory containing this script.

3.  Run the script using the following command:

```plaintext
python demo_fast_get_vbus.py
```

4.  Running results (actual execution may differ from the demo, such as IP information):


```python
[2024.12.30 14:18:38.501.453]  Info:    FSA start listening for broadcast...
[2024.12.30 14:18:38.501.453]  Info:    FSA start listening for broadcast...


[2024.12.30 14:18:38.503.451]  Info:    Received from ('192.168.137.101', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA","serial_number":"F0BE83CD31E8","driver_version":"0.2.10.11","firmware_version":"0.3.12.17","connect_mode":"ETH","mac_address":"E8:31:CD:83:BE:F3","ip_address":"192.168.137.101","IP":"192.168.137.101"}


found servers
['192.168.137.101']
lookup Finished! 

[2024.12.30 14:18:41.513.599]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/", "property": ""}
[2024.12.30 14:18:41.515.612]  Info:    192.168.137.101 : Send Data: b'#'
[2024.12.30 14:18:41.516.611]  Info:    192.168.137.101: Server received from ('192.168.137.101', 2335):b'#@\x84f\x00'
vbus = 4.137451
[2024.12.30 14:18:41.717.842]  Info:    192.168.137.101 : Send Data: b'#'
[2024.12.30 14:18:41.717.842]  Info:    192.168.137.101: Server received from ('192.168.137.101', 2335):b'#@\x86^\x00'
vbus = 4.198975
[2024.12.30 14:18:41.918.814]  Info:    192.168.137.101 : Send Data: b'#'
[2024.12.30 14:18:41.918.814]  Info:    192.168.137.101: Server received from ('192.168.137.101', 2335):b'#@\x84\xe4\x00'
vbus = 4.152832
[2024.12.30 14:18:42.120.281]  Info:    192.168.137.101 : Send Data: b'#'
[2024.12.30 14:18:42.120.905]  Info:    192.168.137.101: Server received from ('192.168.137.101', 2335):b'#@\x84f\x00'
vbus = 4.137451
[2024.12.30 14:18:42.321.550]  Info:    192.168.137.101 : Send Data: b'#'
[2024.12.30 14:18:42.321.550]  Info:    192.168.137.101: Server received from ('192.168.137.101', 2335):b'#@\x86^\x00'
vbus = 4.198975
```

**Common Issues:**

If you encounter any issues when running this script, consider the following:

1.  Make sure you use a compatible Python version as recommended in the Quick Start Guide.

2.  Verify that your network configuration is correct and the FSA actuator is accessible.
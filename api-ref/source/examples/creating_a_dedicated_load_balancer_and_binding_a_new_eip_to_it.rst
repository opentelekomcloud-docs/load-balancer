:original_name: en-us_topic_0000001127879251.html

.. _en-us_topic_0000001127879251:

Creating a Dedicated Load Balancer and Binding a New EIP to It
==============================================================

Scenarios
---------

Call APIs to create a dedicated load balancer and bind a new EIP to it.

Prerequisites
-------------

You have created a VPC and a subnet.

Procedure
---------

#. Query the subnet you have created.

   a. Send **GET https://**\ *{vpc_endpoint}*\ **/v1/**\ *{project_id}*\ **/subnets**. *project_id* indicates the project ID.
   b. Add **X-Auth-Token** to the request header.
   c. Check the response.

      -  The request is successful if the following response is displayed:

         .. code-block::

            {
                "subnets": [
                {
                        "id": "0535759e-8104-49d9-902c-a05185a94bdf", // Subnet ID
                        "name": "subnet-001", // Subnet name
                        "description": "",
                        "cidr": "172.16.66.0/24", //IPv4 address range
                        "dnsList": [
                            "100.125.4.6"
                        ],
                        "status": "ACTIVE",
                        "vpc_id": "44789a9f-3e80-451a-ac03-0818f99b6cdd", // VPC ID
                        "ipv6_enable": true,
                        "gateway_ip_v6": "2001:db8:a583:37c::1",
                        "cidr_v6": "2001:db8:a583:37c::/64",
                        "gateway_ip": "172.16.66.1",
                        "dhcp_enable": true,
                        "primary_dns": "100.125.4.6",
                        "availability_zone": "eu-de-01", //AZ of the subnet
                        "neutron_network_id": "0535759e-8104-49d9-902c-a05185a94bdf", // Network ID
                        "neutron_subnet_id": "1492f0ba-cfce-4e2c-86f7-561d757dfeee", // IPv4 subnet ID
                        "neutron_subnet_id_v6": "3c052475-b50b-49b9-abb1-558bad45e592",
                        "extra_dhcp_opts": [
                            {
                                "opt_value": "8760h",
                                "opt_name": "addresstime"
                            }
                        ]
                    }
                ]
            }

      -  If the request is abnormal, locate the fault by referring to :ref:`HTTP Status Codes for Dedicated Load Balancers <elb_gc_0003>`.

#. Create a dedicated load balancer and bind a new EIP to it.

   a. Send **POST https://**\ *{elb_endpoint}*\ **/v3/**\ *{project_id}*\ **/elb/loadbalancers**. *project_id* indicates the project ID.

   b. Add **X-Auth-Token** to the request header.

   c. Ensure that the following parameters, including **publicip**, are passed in the request body:

      .. code-block::

         {
             "loadbalancer": {
                     "vpc_id": "e5a892ff-3c33-44ef-ada5-b713eb1f7a8b",
                     "availability_zone_list": [
                         "br-iaas-odin1a"
                     ],
                     "admin_state_up": true,
                     "vip_subnet_cidr_id": "1800b6b8-a69f-4719-813d-24d62aaf32bd",
                     "name": "elb-ipv4",
                     "publicip": {
                        "network_type": "5_bgp",
                        "bandwidth": {
                            "size": 2,
                            "share_type": "PER",
                            "charge_mode": "bandwidth",
                            "name": "elb_eip_bandwidth"
                        }
                   }
             }
         }

   d. Check the response.

      -  The request is successful if the following response is displayed:

         .. code-block::

            {
                "request_id": "21177eb184c52c5a4540c78dc7fdaee4",
                "loadbalancer": {
                    "id": "a2556f92-3310-4173-a6d1-0b2d0bb68478",
                    "project_id": "060576782980d5762f9ec014dd2f1148",
                    "name": "elb-ipv4",
                    "description": "",
                    "vip_port_id": "fff961a9-4514-4469-84d4-a2bc4fbdfbeb",
                    "vip_address": "192.168.0.162",
                    "admin_state_up": true,
                    "provisioning_status": "ACTIVE",
                    "operating_status": "ONLINE",
                    "listeners": [],
                    "pools": [],
                    "tags": [],
                    "provider": "vlb",
                    "created_at": "2021-02-23T08:50:19Z",
                    "updated_at": "2021-02-23T08:50:19Z",
                    "vpc_id": "e5a892ff-3c33-44ef-ada5-b713eb1f7a8b",
                    "enterprise_project_id": "0",
                    "availability_zone_list": [
                        "br-iaas-odin1a"
                    ],
                    "ipv6_vip_address": null,
                    "ipv6_vip_virsubnet_id": null,
                    "ipv6_vip_port_id": null,
                    "ipv6_bandwidth": null,
                    "publicips": [
                        {
                            "publicip_id": "12cba100-764e-476c-bf3f-8aba98782cf5",
                            "publicip_address": "10.246.173.188",
                            "ip_version": 4
                        }
                    ],
                    "elb_virsubnet_ids": [
                        "4df3e391-5ebf-4300-b614-cf5a4e793666"
                    ],
                    "elb_virsubnet_type": "dualstack",
                    "ip_target_enable": false,
                    "frozen_scene": null,
                    "eips": [
                        {
                            "eip_id": "12cba100-764e-476c-bf3f-8aba98782cf5",
                            "eip_address": "10.246.173.188",
                            "ip_version": 4
                        }
                    ],
                    "guaranteed": true,
                    "billing_info": null,
                    "l4_flavor_id": null,
                    "l4_scale_flavor_id": null,
                    "l7_flavor_id": null,
                    "l7_scale_flavor_id": null,
                    "vip_subnet_cidr_id": "1800b6b8-a69f-4719-813d-24d62aaf32bd"
                }
            }

      -  If the request is abnormal, locate the fault by referring to :ref:`HTTP Status Codes for Dedicated Load Balancers <elb_gc_0003>`.

:original_name: elb_eg_v3_0002.html

.. _elb_eg_v3_0002:

Adding a Listener to a Dedicated Load Balancer
==============================================

Scenarios
---------

Call the API to add a listener to a dedicated load balancer.

Prerequisites
-------------

-  You have created a dedicated load balancer.
-  You have obtained the ID of the dedicated load balancer.

Procedure
---------

#. Add a listener.

   a. Send **POST https://**\ *{elb_endpoint}*\ **/v3/**\ *{project_id}*\ **/elb/listeners**. *project_id* indicates the project ID.

   b. Add **X-Auth-Token** to the request header.

   c. Ensure that the following parameters are passed in the request body:

      .. code-block::

         {
             "listener": {
                 "protocol_port": 80, // Frontend port. The listener will use this port to receive requests.
                 "protocol": "HTTP", // Frontend protocol. The listener will use this protocol to receive requests.
                 "loadbalancer_id": "f77281cb-9f58-4347-8f82-2180d8bea789", // Load balancer that the listener is added to
                 "name": "my_listener" // Listener name
             }
         }

   d. Check the response.

      -  The request is successful if the following response is displayed:

         .. code-block::

            {
                "listener": {
                    "id": "90ad2705-4ffd-43d3-8f75-af8086bde841",
                    "name": "my_listener",
                    "protocol_port": 80,
                    "protocol": "HTTP",
                    "description": "",
                    "default_tls_container_ref": null,
                    "admin_state_up": true,
                    "loadbalancers": [
                        {
                            "id": "f77281cb-9f58-4347-8f82-2180d8bea789"
                        }
                    ],
                    "client_ca_tls_container_ref": null,
                    "project_id": "057ef081eb00d2732fd1c01a9be75e6f",
                    "sni_container_refs": [],
                    "connection_limit": -1,
                    "default_pool_id": null,
                    "tls_ciphers_policy": null,
                    "tags": [],
                    "created_at": "2020-11-21T03:09:13Z",
                    "updated_at": "2020-11-21T03:09:13Z",
                    "http2_enable": false,
                    "insert_headers": {
                        "X-Forwarded-ELB-IP": false,
                        "X-Forwarded-Host": true,
                        "X-Forwarded-For-Port": false,
                        "X-Forwarded-Port": false
                    },
                    "member_timeout": 60,
                    "client_timeout": 60,
                    "keepalive_timeout": 60,
                    "ipgroup": null,
                    "enable_member_retry": true,
                    "transparent_client_ip_enable": true
                },
                "request_id": "fcd61ee6a6a6c673c65fa0df0577fed9"
            }

      -  If the request is abnormal, locate the fault by referring to :ref:`HTTP Status Codes for Dedicated Load Balancers <elb_gc_0003>`.

:original_name: elb_zq_jt_0001.html

.. _elb_zq_jt_0001:

Adding a Listener
=================

Function
--------

This API is used to add a listener to a load balancer.

Constraints
-----------

When **protocol** is set to **TCP** and **protocol_port** to **0**, the listener works in IP mode (DR mode).

URI
---

POST /v2.0/lbaas/listeners

Request
-------

.. table:: **Table 1** Parameter description

   +-----------+-----------+--------+----------------------------------------------------------------------------------------------------------------------+
   | Parameter | Mandatory | Type   | Description                                                                                                          |
   +===========+===========+========+======================================================================================================================+
   | listener  | Yes       | Object | Specifies the listener. For details, see :ref:`Table 2 <elb_zq_jt_0001__en-us_topic_0096561542_table3499100135410>`. |
   +-----------+-----------+--------+----------------------------------------------------------------------------------------------------------------------+

.. _elb_zq_jt_0001__en-us_topic_0096561542_table3499100135410:

.. table:: **Table 2** **listener** parameter description

   +-----------------------------+-----------------+-----------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter                   | Mandatory       | Type            | Description                                                                                                                                                                                                                                                                      |
   +=============================+=================+=================+==================================================================================================================================================================================================================================================================================+
   | tenant_id                   | No              | String          | Specifies the ID of the project where the listener is used.                                                                                                                                                                                                                      |
   |                             |                 |                 |                                                                                                                                                                                                                                                                                  |
   |                             |                 |                 | The value must be the same as the value of **project_id** in the token.                                                                                                                                                                                                          |
   |                             |                 |                 |                                                                                                                                                                                                                                                                                  |
   |                             |                 |                 | The value contains a maximum of 255 characters.                                                                                                                                                                                                                                  |
   +-----------------------------+-----------------+-----------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | name                        | No              | String          | Specifies the listener name.                                                                                                                                                                                                                                                     |
   |                             |                 |                 |                                                                                                                                                                                                                                                                                  |
   |                             |                 |                 | The value contains a maximum of 255 characters.                                                                                                                                                                                                                                  |
   +-----------------------------+-----------------+-----------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | description                 | No              | String          | Provides supplementary information about the listener.                                                                                                                                                                                                                           |
   |                             |                 |                 |                                                                                                                                                                                                                                                                                  |
   |                             |                 |                 | The value contains a maximum of 255 characters.                                                                                                                                                                                                                                  |
   +-----------------------------+-----------------+-----------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | protocol                    | Yes             | String          | Specifies the protocol used by the listener.                                                                                                                                                                                                                                     |
   |                             |                 |                 |                                                                                                                                                                                                                                                                                  |
   |                             |                 |                 | The value can be **TCP**, **HTTP**, **UDP**, or **TERMINATED_HTTPS**.                                                                                                                                                                                                            |
   +-----------------------------+-----------------+-----------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | protocol_port               | Yes             | Integer         | Specifies the port used by the listener.                                                                                                                                                                                                                                         |
   |                             |                 |                 |                                                                                                                                                                                                                                                                                  |
   |                             |                 |                 | The port number ranges from 1 to 65535.                                                                                                                                                                                                                                          |
   |                             |                 |                 |                                                                                                                                                                                                                                                                                  |
   |                             |                 |                 | .. note::                                                                                                                                                                                                                                                                        |
   |                             |                 |                 |                                                                                                                                                                                                                                                                                  |
   |                             |                 |                 |    If the protocol used by the listener is UDP, the port number cannot be 4789.                                                                                                                                                                                                  |
   +-----------------------------+-----------------+-----------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | loadbalancer_id             | Yes             | String          | Specifies the ID of the associated load balancer.                                                                                                                                                                                                                                |
   +-----------------------------+-----------------+-----------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | connection_limit            | No              | Integer         | Specifies the maximum number of connections.                                                                                                                                                                                                                                     |
   |                             |                 |                 |                                                                                                                                                                                                                                                                                  |
   |                             |                 |                 | The value ranges from **-1** to **2147483647**. The default value is **-1**, indicating that there is no restriction on the maximum number of connections.                                                                                                                       |
   |                             |                 |                 |                                                                                                                                                                                                                                                                                  |
   |                             |                 |                 | This parameter is reserved.                                                                                                                                                                                                                                                      |
   +-----------------------------+-----------------+-----------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | admin_state_up              | No              | Boolean         | Specifies the administrative status of the listener.                                                                                                                                                                                                                             |
   |                             |                 |                 |                                                                                                                                                                                                                                                                                  |
   |                             |                 |                 | This parameter is reserved, and the default value is **true**.                                                                                                                                                                                                                   |
   +-----------------------------+-----------------+-----------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | http2_enable                | No              | Boolean         | Specifies whether to use HTTP/2.                                                                                                                                                                                                                                                 |
   |                             |                 |                 |                                                                                                                                                                                                                                                                                  |
   |                             |                 |                 | The value can be **true** or **false**.                                                                                                                                                                                                                                          |
   |                             |                 |                 |                                                                                                                                                                                                                                                                                  |
   |                             |                 |                 | -  **true**: HTTP/2 is used.                                                                                                                                                                                                                                                     |
   |                             |                 |                 | -  **false**: HTTP/2 is not used.                                                                                                                                                                                                                                                |
   |                             |                 |                 |                                                                                                                                                                                                                                                                                  |
   |                             |                 |                 | The default value is **false**.                                                                                                                                                                                                                                                  |
   |                             |                 |                 |                                                                                                                                                                                                                                                                                  |
   |                             |                 |                 | This parameter is valid only when the protocol used by the listener is set to **TERMINATED_HTTPS**.                                                                                                                                                                              |
   +-----------------------------+-----------------+-----------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | default_pool_id             | No              | String          | Specifies the ID of the associated backend server group.                                                                                                                                                                                                                         |
   |                             |                 |                 |                                                                                                                                                                                                                                                                                  |
   |                             |                 |                 | If a request does not match the forwarding policy, the request is forwarded to the default backend server group for processing. If the value is **null**, the listener has no default backend server group.                                                                      |
   |                             |                 |                 |                                                                                                                                                                                                                                                                                  |
   |                             |                 |                 | This parameter has the following constraints:                                                                                                                                                                                                                                    |
   |                             |                 |                 |                                                                                                                                                                                                                                                                                  |
   |                             |                 |                 | -  Its value cannot be the ID of any backend server group of other listeners.                                                                                                                                                                                                    |
   |                             |                 |                 | -  Its value cannot be the ID of any backend server group associated with the forwarding policies set for other listeners.                                                                                                                                                       |
   |                             |                 |                 |                                                                                                                                                                                                                                                                                  |
   |                             |                 |                 | The relationships between the protocol used by the listener and the protocol of the backend server group are as follows:                                                                                                                                                         |
   |                             |                 |                 |                                                                                                                                                                                                                                                                                  |
   |                             |                 |                 | -  When the protocol used by the listener is **TCP**, the protocol of the backend server group must be **TCP**.                                                                                                                                                                  |
   |                             |                 |                 | -  When the protocol used by the listener is **UDP**, the protocol of the backend server group must be **UDP**.                                                                                                                                                                  |
   |                             |                 |                 | -  When the protocol used by the listener is **HTTP** or **TERMINATED_HTTPS**, the protocol of the backend server group must be **HTTP**.                                                                                                                                        |
   +-----------------------------+-----------------+-----------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | default_tls_container_ref   | No              | String          | Specifies the ID of the server certificate used by the listener.                                                                                                                                                                                                                 |
   |                             |                 |                 |                                                                                                                                                                                                                                                                                  |
   |                             |                 |                 | This parameter is mandatory when **protocol** is set to **TERMINATED_HTTPS**.                                                                                                                                                                                                    |
   |                             |                 |                 |                                                                                                                                                                                                                                                                                  |
   |                             |                 |                 | The default value is **null** when **protocol** is not set to **TERMINATED_HTTPS**.                                                                                                                                                                                              |
   |                             |                 |                 |                                                                                                                                                                                                                                                                                  |
   |                             |                 |                 | The value contains a maximum of 128 characters.                                                                                                                                                                                                                                  |
   |                             |                 |                 |                                                                                                                                                                                                                                                                                  |
   |                             |                 |                 | .. note::                                                                                                                                                                                                                                                                        |
   |                             |                 |                 |                                                                                                                                                                                                                                                                                  |
   |                             |                 |                 |    This parameter is valid only when **protocol** is set to **TERMINATED_HTTPS**.                                                                                                                                                                                                |
   +-----------------------------+-----------------+-----------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | client_ca_tls_container_ref | No              | String          | Specifies the ID of the CA certificate used by the listener.                                                                                                                                                                                                                     |
   |                             |                 |                 |                                                                                                                                                                                                                                                                                  |
   |                             |                 |                 | The default value is **null**.                                                                                                                                                                                                                                                   |
   |                             |                 |                 |                                                                                                                                                                                                                                                                                  |
   |                             |                 |                 | The value contains a maximum of 128 characters.                                                                                                                                                                                                                                  |
   |                             |                 |                 |                                                                                                                                                                                                                                                                                  |
   |                             |                 |                 | .. note::                                                                                                                                                                                                                                                                        |
   |                             |                 |                 |                                                                                                                                                                                                                                                                                  |
   |                             |                 |                 |    This parameter is valid only when **protocol** is set to **TERMINATED_HTTPS**.                                                                                                                                                                                                |
   +-----------------------------+-----------------+-----------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | sni_container_refs          | No              | Array           | Lists the IDs of SNI certificates (server certificates with domain names) used by the listener.                                                                                                                                                                                  |
   |                             |                 |                 |                                                                                                                                                                                                                                                                                  |
   |                             |                 |                 | If the parameter value is an empty list, the SNI feature is disabled.                                                                                                                                                                                                            |
   |                             |                 |                 |                                                                                                                                                                                                                                                                                  |
   |                             |                 |                 | The default value is **[]**.                                                                                                                                                                                                                                                     |
   |                             |                 |                 |                                                                                                                                                                                                                                                                                  |
   |                             |                 |                 | .. note::                                                                                                                                                                                                                                                                        |
   |                             |                 |                 |                                                                                                                                                                                                                                                                                  |
   |                             |                 |                 |    This parameter is valid only when **protocol** is set to **TERMINATED_HTTPS**.                                                                                                                                                                                                |
   +-----------------------------+-----------------+-----------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | tls_ciphers_policy          | No              | String          | Specifies the security policy used by the listener. This parameter is valid only when the protocol used by the listener is set to **TERMINATED_HTTPS**.                                                                                                                          |
   |                             |                 |                 |                                                                                                                                                                                                                                                                                  |
   |                             |                 |                 | The value can be **tls-1-0-inherit**, **tls-1-0**, **tls-1-1**, **tls-1-2**, or **tls-1-2-strict**, and the default value is **tls-1-0**. For details of cipher suites for each security policy, see :ref:`Table 3 <elb_zq_jt_0001__en-us_topic_0096561542_table1247813103533>`. |
   +-----------------------------+-----------------+-----------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

.. _elb_zq_jt_0001__en-us_topic_0096561542_table1247813103533:

.. table:: **Table 3** **tls_ciphers_policy** parameter description

   +-----------------+-------------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Security Policy | TLS Version             | Cipher Suite                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       |
   +=================+=========================+====================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================+
   | tls-1-0-inherit | TLS 1.2 TLS 1.1 TLS 1.0 | ECDHE-RSA-AES256-GCM-SHA384:ECDHE-RSA-AES128-GCM-SHA256:ECDHE-ECDSA-AES256-GCM-SHA384:ECDHE-ECDSA-AES128-GCM-SHA256:AES128-GCM-SHA256:AES256-GCM-SHA384:ECDHE-ECDSA-AES128-SHA256:ECDHE-RSA-AES128-SHA256:AES128-SHA256:AES256-SHA256:ECDHE-ECDSA-AES256-SHA384:ECDHE-RSA-AES256-SHA384:ECDHE-ECDSA-AES128-SHA:ECDHE-RSA-AES128-SHA:DHE-RSA-AES128-SHA:ECDHE-RSA-AES256-SHA:ECDHE-ECDSA-AES256-SHA:AES128-SHA:AES256-SHA:DHE-DSS-AES128-SHA:CAMELLIA128-SHA:EDH-RSA-DES-CBC3-SHA:DES-CBC3-SHA:ECDHE-RSA-RC4-SHA:RC4-SHA:DHE-RSA-AES256-SHA:DHE-DSS-AES256-SHA:DHE-RSA-CAMELLIA256-SHA:DHE-DSS-CAMELLIA256-SHA:CAMELLIA256-SHA:EDH-DSS-DES-CBC3-SHA:DHE-RSA-CAMELLIA128-SHA:DHE-DSS-CAMELLIA128-SHA |
   +-----------------+-------------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | tls-1-0         | TLS 1.2 TLS 1.1 TLS 1.0 | ECDHE-RSA-AES256-GCM-SHA384:ECDHE-RSA-AES128-GCM-SHA256:ECDHE-ECDSA-AES256-GCM-SHA384:ECDHE-ECDSA-AES128-GCM-SHA256:AES128-GCM-SHA256:AES256-GCM-SHA384:ECDHE-ECDSA-AES128-SHA256:ECDHE-RSA-AES128-SHA256:AES128-SHA256:AES256-SHA256:ECDHE-ECDSA-AES256-SHA384:ECDHE-RSA-AES256-SHA384:ECDHE-ECDSA-AES128-SHA:ECDHE-RSA-AES128-SHA:ECDHE-RSA-AES256-SHA:ECDHE-ECDSA-AES256-SHA:AES128-SHA:AES256-SHA                                                                                                                                                                                                                                                                                              |
   +-----------------+-------------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | tls-1-1         | TLS 1.2 TLS 1.1         |                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    |
   +-----------------+-------------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | tls-1-2         | TLS 1.2                 |                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    |
   +-----------------+-------------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | tls-1-2-strict  | TLS 1.2                 | ECDHE-RSA-AES256-GCM-SHA384:ECDHE-RSA-AES128-GCM-SHA256:ECDHE-ECDSA-AES256-GCM-SHA384:ECDHE-ECDSA-AES128-GCM-SHA256:AES128-GCM-SHA256:AES256-GCM-SHA384:ECDHE-ECDSA-AES128-SHA256:ECDHE-RSA-AES128-SHA256:AES128-SHA256:AES256-SHA256:ECDHE-ECDSA-AES256-SHA384:ECDHE-RSA-AES256-SHA384                                                                                                                                                                                                                                                                                                                                                                                                            |
   +-----------------+-------------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

Response
--------

.. table:: **Table 4** Response parameters

   +-----------+--------+----------------------------------------------------------------------------------------------------------------------+
   | Parameter | Type   | Description                                                                                                          |
   +===========+========+======================================================================================================================+
   | listener  | Object | Specifies the listener. For details, see :ref:`Table 5 <elb_zq_jt_0001__en-us_topic_0096561542_table5301132505414>`. |
   +-----------+--------+----------------------------------------------------------------------------------------------------------------------+

.. _elb_zq_jt_0001__en-us_topic_0096561542_table5301132505414:

.. table:: **Table 5** **listeners** parameter description

   +-----------------------------+-----------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter                   | Type                  | Description                                                                                                                                                                                                                                                                      |
   +=============================+=======================+==================================================================================================================================================================================================================================================================================+
   | id                          | String                | Specifies the listener ID.                                                                                                                                                                                                                                                       |
   +-----------------------------+-----------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | tenant_id                   | String                | Specifies the ID of the project where the listener is used.                                                                                                                                                                                                                      |
   +-----------------------------+-----------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | name                        | String                | Specifies the listener name.                                                                                                                                                                                                                                                     |
   +-----------------------------+-----------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | description                 | String                | Provides supplementary information about the listener.                                                                                                                                                                                                                           |
   +-----------------------------+-----------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | protocol                    | String                | Specifies the protocol used by the listener.                                                                                                                                                                                                                                     |
   |                             |                       |                                                                                                                                                                                                                                                                                  |
   |                             |                       | The value can be **TCP**, **HTTP**, **UDP**, or **TERMINATED_HTTPS**.                                                                                                                                                                                                            |
   +-----------------------------+-----------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | protocol_port               | Integer               | Specifies the port used by the listener.                                                                                                                                                                                                                                         |
   |                             |                       |                                                                                                                                                                                                                                                                                  |
   |                             |                       | The port number ranges from 1 to 65535.                                                                                                                                                                                                                                          |
   +-----------------------------+-----------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | loadbalancers               | Array                 | Specifies the ID of the associated load balancer. For details, see :ref:`Table 6 <elb_zq_jt_0001__en-us_topic_0096561542_table17641175071912>`.                                                                                                                                  |
   +-----------------------------+-----------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | connection_limit            | Integer               | Specifies the maximum number of connections.                                                                                                                                                                                                                                     |
   |                             |                       |                                                                                                                                                                                                                                                                                  |
   |                             |                       | The value ranges from **-1** to **2147483647**. The default value is **-1**, indicating that there is no restriction on the maximum number of connections.                                                                                                                       |
   |                             |                       |                                                                                                                                                                                                                                                                                  |
   |                             |                       | This parameter is reserved.                                                                                                                                                                                                                                                      |
   +-----------------------------+-----------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | admin_state_up              | Boolean               | Specifies the administrative status of the listener.                                                                                                                                                                                                                             |
   |                             |                       |                                                                                                                                                                                                                                                                                  |
   |                             |                       | This parameter is reserved. The value can be **true** or **false**.                                                                                                                                                                                                              |
   |                             |                       |                                                                                                                                                                                                                                                                                  |
   |                             |                       | -  **true**: The load balancer is enabled.                                                                                                                                                                                                                                       |
   |                             |                       | -  **false**: The load balancer is disabled.                                                                                                                                                                                                                                     |
   +-----------------------------+-----------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | http2_enable                | Boolean               | Specifies whether to use HTTP/2.                                                                                                                                                                                                                                                 |
   |                             |                       |                                                                                                                                                                                                                                                                                  |
   |                             |                       | The value can be **true** or **false**.                                                                                                                                                                                                                                          |
   |                             |                       |                                                                                                                                                                                                                                                                                  |
   |                             |                       | -  **true**: HTTP/2 is used.                                                                                                                                                                                                                                                     |
   |                             |                       | -  **false**: HTTP/2 is not used.                                                                                                                                                                                                                                                |
   |                             |                       |                                                                                                                                                                                                                                                                                  |
   |                             |                       | This parameter is valid only when the protocol used by the listener is set to **TERMINATED_HTTPS**.                                                                                                                                                                              |
   +-----------------------------+-----------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | default_pool_id             | String                | Specifies the ID of the associated backend server group.                                                                                                                                                                                                                         |
   |                             |                       |                                                                                                                                                                                                                                                                                  |
   |                             |                       | If a request does not match the forwarding policy, the request is forwarded to the default backend server group for processing. If the value is **null**, the listener has no default backend server group.                                                                      |
   +-----------------------------+-----------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | default_tls_container_ref   | String                | Specifies the ID of the server certificate used by the listener. For details, see :ref:`Certificate <elb_zq_zs_0000>`.                                                                                                                                                           |
   |                             |                       |                                                                                                                                                                                                                                                                                  |
   |                             |                       | This parameter is mandatory when **protocol** is set to **TERMINATED_HTTPS**.                                                                                                                                                                                                    |
   +-----------------------------+-----------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | client_ca_tls_container_ref | String                | Specifies the ID of the CA certificate used by the listener. For details, see :ref:`Certificate <elb_zq_zs_0000>`.                                                                                                                                                               |
   +-----------------------------+-----------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | sni_container_refs          | Array                 | Lists the IDs of SNI certificates (server certificates with domain names) used by the listener.                                                                                                                                                                                  |
   |                             |                       |                                                                                                                                                                                                                                                                                  |
   |                             |                       | If the parameter value is an empty list, the SNI feature is disabled.                                                                                                                                                                                                            |
   +-----------------------------+-----------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | tags                        | Array                 | Tags the listener.                                                                                                                                                                                                                                                               |
   +-----------------------------+-----------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | created_at                  | String                | Specifies the time when the listener was created. The UTC time is in *YYYY-MM-DDTHH:MM:SS* format.                                                                                                                                                                               |
   +-----------------------------+-----------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | updated_at                  | String                | Specifies the time when the listener was updated. The UTC time is in *YYYY-MM-DDTHH:MM:SS* format.                                                                                                                                                                               |
   +-----------------------------+-----------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | tls_ciphers_policy          | String                | Specifies the security policy used by the listener. This parameter is valid only when the protocol used by the listener is set to **TERMINATED_HTTPS**.                                                                                                                          |
   |                             |                       |                                                                                                                                                                                                                                                                                  |
   |                             |                       | The value can be **tls-1-0-inherit**, **tls-1-0**, **tls-1-1**, **tls-1-2**, or **tls-1-2-strict**, and the default value is **tls-1-0**. For details of cipher suites for each security policy, see :ref:`Table 3 <elb_zq_jt_0001__en-us_topic_0096561542_table1247813103533>`. |
   +-----------------------------+-----------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

.. _elb_zq_jt_0001__en-us_topic_0096561542_table17641175071912:

.. table:: **Table 6** **loadbalancers** parameter description

   ========= ====== =================================================
   Parameter Type   Description
   ========= ====== =================================================
   id        String Specifies the ID of the associated load balancer.
   ========= ====== =================================================

Example Request
---------------

-  Example request 1: Adding a TCP listener

   .. code-block:: text

      POST https://{Endpoint}/v2.0/lbaas/listeners

      {
          "listener": {
              "protocol_port": 80,
              "protocol": "TCP",
              "loadbalancer_id": "0416b6f1-877f-4a51-987e-978b3f084253",
              "name": "listener-test",
              "admin_state_up": true
          }
      }

-  Example request 2: Adding an HTTPS listener

   .. code-block:: text

      POST https://{Endpoint}/v2.0/lbaas/listeners

      {
          "listener": {
              "protocol_port": 25,
              "protocol": "TERMINATED_HTTPS",
              "default_tls_container_ref": "02dcd56799e045bf8b131533cc911dd6",
              "loadbalancer_id": "0416b6f1-877f-4a51-987e-978b3f084253",
              "name": "listener-test",
              "admin_state_up": true

          }
      }

-  Example request 3: Adding a listener with the SNI feature enabled

   .. code-block:: text

      POST https://{Endpoint}/v2.0/lbaas/listeners

      {
          "listener": {
              "protocol_port": 27,
              "protocol": "TERMINATED_HTTPS",
              "loadbalancer_id": "6bb85e33-4953-457a-85a9-336d76125b7b",
              "name": "listener-test",
              "admin_state_up": true,
              "default_tls_container_ref":"02dcd56799e045bf8b131533cc911dd6",
              "sni_container_refs": ["e15d1b5000474adca383c3cd9ddc06d4",
                                "5882325fd6dd4b95a88d33238d293a0f"]
          }
      }

Example Response
----------------

-  Example response 1

   .. code-block::

      {
          "listener": {
              "protocol_port": 80,
              "protocol": "TCP",
              "description": "",
              "client_ca_tls_container_ref": null,
              "default_tls_container_ref": null,
              "admin_state_up": true,
              "http2_enable": false,
              "loadbalancers": [
                  {
                      "id": "0416b6f1-877f-4a51-987e-978b3f084253"
                  }
              ],
              "tenant_id": "145483a5107745e9b3d80f956713e6a3",
              "sni_container_refs": [],
              "connection_limit": -1,
              "default_pool_id": null,
              "tags": [],
              "id": "b7f32b52-6f17-4b16-9ec8-063d71b653ce",
              "name": "listener-test",
              "tls_ciphers_policy": null,
              "created_at": "2018-07-25T01:54:13",
              "updated_at": "2018-07-25T01:54:14"
          }
      }

-  Example response 2

   .. code-block::

      {
          "listener": {
              "protocol_port": 25,
              "protocol": "TERMINATED_HTTPS",
              "description": "",
              "default_tls_container_ref": "02dcd56799e045bf8b131533cc911dd6",
              "sni_container_refs": [],
              "loadbalancers": [
                  {
                      "id": "0416b6f1-877f-4a51-987e-978b3f084253"
                  }
              ],
              "tenant_id": "601240b9c5c94059b63d484c92cfe308",

              "created_at": "2019-01-21T12:38:31",
              "client_ca_tls_container_ref": null,
              "connection_limit": -1,
              "updated_at": "2019-01-21T12:38:31",
              "http2_enable": false,
              "admin_state_up": true,
              "default_pool_id": null,
              "tls_ciphers_policy": "tls-1-0",
              "id": "b56634cd-5ba8-460e-b5a2-6de5ba8eaf60",
              "tags": [],
              "name": "listener-test"

          }
      }

-  Example response 3

   .. code-block::

      {
          "listener": {
              "protocol_port": 27,
              "protocol": "TERMINATED_HTTPS",
              "description": "",
              "default_tls_container_ref": "02dcd56799e045bf8b131533cc911dd6",
              "sni_container_refs": [
                  "5882325fd6dd4b95a88d33238d293a0f",
                  "e15d1b5000474adca383c3cd9ddc06d4"
              ],
              "loadbalancers": [
                  {
                      "id": "6bb85e33-4953-457a-85a9-336d76125b7b"
                  }
              ],
              "tenant_id": "601240b9c5c94059b63d484c92cfe308",
              "project_id": "601240b9c5c94059b63d484c92cfe308",
              "created_at": "2019-01-21T12:43:55",
              "client_ca_tls_container_ref": null,
              "connection_limit": -1,
              "updated_at": "2019-01-21T12:43:55",
              "http2_enable": false,
              "admin_state_up": true,
              "default_pool_id": null,
              "": "tls-1-0",
              "id": "b2cfda5b-52fe-4320-8845-34e8d4dac2c7",
              "tags": [],
              "name": "listener-test"
          }
      }

Status Code
-----------

For details, see :ref:`HTTP Status Codes of Shared Load Balancers <elb_gc_0002>`.

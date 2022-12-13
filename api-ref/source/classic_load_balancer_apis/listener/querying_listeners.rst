:original_name: elb_jd_jt_0005.html

.. _elb_jd_jt_0005:

Querying Listeners
==================

Function
--------

This API is used to query listeners using search criteria and display them in a list.

URI
---

GET /v1.0/{project_id}/elbaas/listeners?loadbalancer_id={loadbalancer_id}

.. note::

   Enter a question mark (?) and an ampersand (&) at the end of the URI to define multiple search criteria. You can filter the listeners using the parameters in the response except **update_time**, **create_time**, **admin_state_up**, **session_sticky**, and **member_number**.

.. table:: **Table 1** Parameter description

   =============== ========= ====== ===============================
   Parameter       Mandatory Type   Description
   =============== ========= ====== ===============================
   project_id      Yes       String Specifies the project ID.
   loadbalancer_id No        String Specifies the load balancer ID.
   =============== ========= ====== ===============================

Request
-------

-  Request parameters

   None

-  Example request

   None

Response
--------

-  Response parameters

   .. table:: **Table 2** Parameter description

      +-----------------------+-----------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
      | Parameter             | Type                  | Description                                                                                                                                                                                    |
      +=======================+=======================+================================================================================================================================================================================================+
      | update_time           | String                | Specifies the time when the listener was updated.                                                                                                                                              |
      +-----------------------+-----------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
      | backend_port          | Integer               | Specifies the port used by backend ECSs.                                                                                                                                                       |
      +-----------------------+-----------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
      | id                    | String                | Specifies the listener ID.                                                                                                                                                                     |
      +-----------------------+-----------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
      | backend_protocol      | String                | Specifies the protocol used by backend ECSs.                                                                                                                                                   |
      +-----------------------+-----------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
      | sticky_session_type   | String                | Specifies where the cookie is from. The only value is **insert**, indicating that the cookie is inserted by the load balancer.                                                                 |
      |                       |                       |                                                                                                                                                                                                |
      |                       |                       | -  This parameter is valid when **protocol** is set to **HTTP** and **session_sticky** to **true**. The default value is **insert**.                                                           |
      |                       |                       | -  This parameter is invalid when **protocol** is set to **TCP**, which means that the parameter is unavailable or its value is set to **null**.                                               |
      +-----------------------+-----------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
      | description           | String                | Provides supplementary information about the listener.                                                                                                                                         |
      +-----------------------+-----------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
      | loadbalancer_id       | String                | Specifies the load balancer ID.                                                                                                                                                                |
      +-----------------------+-----------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
      | create_time           | String                | Specifies the time when the listener was created.                                                                                                                                              |
      +-----------------------+-----------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
      | status                | String                | Specifies the listener status. The value can be **ACTIVE**, **PENDING_CREATE**, or **ERROR**.                                                                                                  |
      +-----------------------+-----------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
      | protocol              | String                | Specifies the protocol used for load balancing at Layer 4 or Layer 7.                                                                                                                          |
      +-----------------------+-----------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
      | lb_algorithm          | String                | Specifies the load balancing algorithm.                                                                                                                                                        |
      +-----------------------+-----------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
      | admin_state_up        | Boolean               | -  Specifies the administrative status of the load balancer.                                                                                                                                   |
      |                       |                       |                                                                                                                                                                                                |
      |                       |                       | -  Two options are available:                                                                                                                                                                  |
      |                       |                       |                                                                                                                                                                                                |
      |                       |                       |    **false**: The load balancer is disabled.                                                                                                                                                   |
      |                       |                       |                                                                                                                                                                                                |
      |                       |                       |    **true**: The load balancer is running properly.                                                                                                                                            |
      +-----------------------+-----------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
      | cookie_timeout        | Integer               | -  Specifies the cookie timeout duration. This parameter is valid when **session_sticky** is set to **true** and **sticky_session_type** to **insert**.                                        |
      |                       |                       | -  The value ranges from **1** to **1440**.                                                                                                                                                    |
      +-----------------------+-----------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
      | member_number         | Integer               | Specifies the quantity of backend ECSs.                                                                                                                                                        |
      +-----------------------+-----------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
      | healthcheck_id        | String                | Specifies the health check ID.                                                                                                                                                                 |
      +-----------------------+-----------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
      | session_sticky        | Boolean               | Specifies whether to enable the sticky session feature. The feature is enabled when the value is **true**.                                                                                     |
      +-----------------------+-----------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
      | port                  | Integer               | Specifies the port used by the listener.                                                                                                                                                       |
      +-----------------------+-----------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
      | name                  | String                | Specifies the listener name.                                                                                                                                                                   |
      +-----------------------+-----------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
      | certificate_id        | String                | Specifies the ID of the SSL certificate for security authentication. This parameter is mandatory when **protocol** is set to **HTTPS** or **SSL**. Otherwise, the parameter value is **null**. |
      +-----------------------+-----------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
      | certificates          | String                | Lists the certificate IDs if **protocol** is set to **HTTPS**.                                                                                                                                 |
      |                       |                       |                                                                                                                                                                                                |
      |                       |                       | This parameter is mandatory in the SNI scenario.                                                                                                                                               |
      +-----------------------+-----------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
      | tcp_timeout           | Integer               | Specifies the TCP session timeout duration.                                                                                                                                                    |
      +-----------------------+-----------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
      | udp_timeout           | Integer               | Specifies the UDP session timeout duration.                                                                                                                                                    |
      +-----------------------+-----------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
      | ssl_protocols         | String                | Specifies the supported SSL/TLS protocol version. This parameter is available only when **protocol** is set to **HTTPS** or **SSL**.                                                           |
      |                       |                       |                                                                                                                                                                                                |
      |                       |                       | .. note::                                                                                                                                                                                      |
      |                       |                       |                                                                                                                                                                                                |
      |                       |                       |    For HTTPS listeners in versions earlier than 1.2.8, the parameter value is **TLS 1.2**.                                                                                                     |
      +-----------------------+-----------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
      | ssl_ciphers           | String                | Specifies the cipher suite of an encryption protocol. This parameter is available only when **protocol** is set to **HTTPS** or **SSL**.                                                       |
      +-----------------------+-----------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

-  Example response

   .. code-block::

      [
       {
           "update_time": "2016-12-01 07:12:59",
           "backend_port": 9090,
           "id": "a824584fb3ba4d39ba0cf372c7cbbb67",
           "backend_protocol": "TCP",
           "sticky_session_type": null,
           "certificate_id": null,
           "description": "",
           "loadbalancer_id": "f54c65b1b5dd4a4f95b71b44796ac013",
           "lb_algorithm": "roundrobin",
           "create_time": "2016-12-01 07:12:43",
           "admin_state_up": false,
           "status": "ACTIVE",
           "protocol": "TCP",
           "cookie_timeout": 100,
           "port": 9092,
           "tcp_draining": true,
           "tcp_timeout": 1,
           "member_number": 0,
           "healthcheck_id": null,
           "session_sticky": true,
           "tcp_draining_timeout": 5,
           "name": "lis"
      },

      {
           "update_time": "2016-12-01 07:11:49",
           "backend_port": 9090,
           "id": "4818300858fc43e0a4d843ce74ee83a4",
           "backend_protocol": "HTTP",
           "sticky_session_type": "insert",
           "certificate_id": null,
           "description": "",
           "loadbalancer_id": "f54c65b1b5dd4a4f95b71b44796ac013",
           "lb_algorithm": "roundrobin",
           "create_time": "2016-12-01 07:11:30",
           "admin_state_up": false,
           "status": "ACTIVE",
           "protocol": "HTTP",
           "cookie_timeout": 100,
           "port": 9091,
           "tcp_draining": true,
           "tcp_timeout": null,
           "member_number": 0,
           "healthcheck_id": null,
           "session_sticky": true,
           "tcp_draining_timeout": 5,
           "name": "lis"
       }
      ]

Status Code
-----------

-  Normal

   200

-  Error

   +-------------+--------------------+----------------------------------------------------------+
   | Status Code | Message            | Description                                              |
   +=============+====================+==========================================================+
   | 400         | badRequest         | Request error.                                           |
   +-------------+--------------------+----------------------------------------------------------+
   | 401         | unauthorized       | Authentication failed.                                   |
   +-------------+--------------------+----------------------------------------------------------+
   | 403         | userDisabled       | You do not have the permission to perform the operation. |
   +-------------+--------------------+----------------------------------------------------------+
   | 404         | Not Found          | The requested page does not exist.                       |
   +-------------+--------------------+----------------------------------------------------------+
   | 500         | authFault          | System error.                                            |
   +-------------+--------------------+----------------------------------------------------------+
   | 503         | serviceUnavailable | The service is unavailable.                              |
   +-------------+--------------------+----------------------------------------------------------+

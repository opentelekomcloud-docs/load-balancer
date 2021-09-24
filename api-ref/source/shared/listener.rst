Listener
########

Adding a Listener
=================

Function
^^^^^^^^

This API is used to add a listener to a load balancer.

Constraints
^^^^^^^^^^^

When **protocol** is set to **TCP** and **protocol_port** to **0**, the listener works in IP mode (DR mode).

URI
^^^

POST /v2.0/lbaas/listeners

Request
^^^^^^^

.. table:: **Table 1** Parameter description

   +-----------+-----------+--------+---------------------------------------------------------+
   | Parameter | Mandatory | Type   | Description                                             |
   +===========+===========+========+=========================================================+
   | listener  | Yes       | Object | Specifies the listener. For details, see :ref:`scl_t2`. |
   +-----------+-----------+--------+---------------------------------------------------------+

.. _scl_t2:
.. table:: **Table 2** **listener** parameter description

   +-----------------------------+-----------+---------+-------------------------------------+
   | Parameter                   | Mandatory | Type    | Description                         |
   +=============================+===========+=========+=====================================+
   | tenant_id                   | No        | String  | Specifies the ID of the             |
   |                             |           |         | project where the listener          |
   |                             |           |         | is used.                            |
   |                             |           |         |                                     |
   |                             |           |         | The value must be the same          |
   |                             |           |         | as the value of                     |
   |                             |           |         | **project_id** in the               |
   |                             |           |         | token.                              |
   |                             |           |         |                                     |
   |                             |           |         | The value contains a                |
   |                             |           |         | maximum of 255 characters.          |
   +-----------------------------+-----------+---------+-------------------------------------+
   | name                        | No        | String  | Specifies the listener              |
   |                             |           |         | name.                               |
   |                             |           |         |                                     |
   |                             |           |         | The value contains a                |
   |                             |           |         | maximum of 255 characters.          |
   +-----------------------------+-----------+---------+-------------------------------------+
   | description                 | No        | String  | Provides supplementary              |
   |                             |           |         | information about the               |
   |                             |           |         | listener.                           |
   |                             |           |         |                                     |
   |                             |           |         | The value contains a                |
   |                             |           |         | maximum of 255 characters.          |
   +-----------------------------+-----------+---------+-------------------------------------+
   | protocol                    | Yes       | String  | Specifies the protocol used         |
   |                             |           |         | by the listener.                    |
   |                             |           |         |                                     |
   |                             |           |         | The value can be **TCP**,           |
   |                             |           |         | **HTTP**, **UDP**, or               |
   |                             |           |         | **TERMINATED_HTTPS**.               |
   +-----------------------------+-----------+---------+-------------------------------------+
   | protocol_port               | Yes       | Integer | Specifies the port used by          |
   |                             |           |         | the listener.                       |
   |                             |           |         |                                     |
   |                             |           |         | The port number ranges from         |
   |                             |           |         | 1 to 65535.                         |
   |                             |           |         |                                     |
   |                             |           |         | NOTE:                               |
   |                             |           |         | If the protocol used by the         |
   |                             |           |         | listener is UDP, the port           |
   |                             |           |         | number cannot be 4789.              |
   +-----------------------------+-----------+---------+-------------------------------------+
   | loadbalancer_id             | Yes       | String  | Specifies the ID of the             |
   |                             |           |         | associated load balancer.           |
   +-----------------------------+-----------+---------+-------------------------------------+
   | connection_limit            | No        | Integer | Specifies the maximum               |
   |                             |           |         | number of connections.              |
   |                             |           |         |                                     |
   |                             |           |         | The value ranges from               |
   |                             |           |         | **-1** to **2147483647**.           |
   |                             |           |         | The default value is                |
   |                             |           |         | **-1**, indicating that             |
   |                             |           |         | there is no restriction on          |
   |                             |           |         | the maximum number of               |
   |                             |           |         | connections.                        |
   |                             |           |         |                                     |
   |                             |           |         | This parameter is reserved.         |
   +-----------------------------+-----------+---------+-------------------------------------+
   | admin_state_up              | No        | Boolean | Specifies the                       |
   |                             |           |         | administrative status of            |
   |                             |           |         | the listener.                       |
   |                             |           |         |                                     |
   |                             |           |         | This parameter is reserved,         |
   |                             |           |         | and the default value is            |
   |                             |           |         | **true**.                           |
   +-----------------------------+-----------+---------+-------------------------------------+
   | http2_enable                | No        | Boolean | Specifies whether to use            |
   |                             |           |         | HTTP/2.                             |
   |                             |           |         |                                     |
   |                             |           |         | The value can be **true**           |
   |                             |           |         | or **false**.                       |
   |                             |           |         |                                     |
   |                             |           |         | -  **true**: HTTP/2 is              |
   |                             |           |         |    used.                            |
   |                             |           |         | -  **false**: HTTP/2 is not         |
   |                             |           |         |    used.                            |
   |                             |           |         |                                     |
   |                             |           |         | The default value is                |
   |                             |           |         | **false**.                          |
   |                             |           |         |                                     |
   |                             |           |         | This parameter is valid             |
   |                             |           |         | only when the protocol used         |
   |                             |           |         | by the listener is set to           |
   |                             |           |         | **TERMINATED_HTTPS**.               |
   +-----------------------------+-----------+---------+-------------------------------------+
   | default_pool_id             | No        | String  | Specifies the ID of the             |
   |                             |           |         | associated backend server           |
   |                             |           |         | group.                              |
   |                             |           |         |                                     |
   |                             |           |         | If a request does not match         |
   |                             |           |         | the forwarding policy, the          |
   |                             |           |         | request is forwarded to the         |
   |                             |           |         | default backend server              |
   |                             |           |         | group for processing. If            |
   |                             |           |         | the value is **null**, the          |
   |                             |           |         | listener has no default             |
   |                             |           |         | backend server group.               |
   |                             |           |         |                                     |
   |                             |           |         | This parameter has the              |
   |                             |           |         | following constraints:              |
   |                             |           |         |                                     |
   |                             |           |         | -  Its value cannot be the          |
   |                             |           |         |    ID of any backend server         |
   |                             |           |         |    group of other                   |
   |                             |           |         |    listeners.                       |
   |                             |           |         | -  Its value cannot be the          |
   |                             |           |         |    ID of any backend server         |
   |                             |           |         |    group associated with            |
   |                             |           |         |    the forwarding policies          |
   |                             |           |         |    set for other listeners.         |
   |                             |           |         |                                     |
   |                             |           |         | The relationships between           |
   |                             |           |         | the protocol used by the            |
   |                             |           |         | listener and the protocol           |
   |                             |           |         | of the backend server group         |
   |                             |           |         | are as follows:                     |
   |                             |           |         |                                     |
   |                             |           |         | -  When the protocol used           |
   |                             |           |         |    by the listener is               |
   |                             |           |         |    **TCP**, the protocol of         |
   |                             |           |         |    the backend server group         |
   |                             |           |         |    must be **TCP**.                 |
   |                             |           |         | -  When the protocol used           |
   |                             |           |         |    by the listener is               |
   |                             |           |         |    **UDP**, the protocol of         |
   |                             |           |         |    the backend server group         |
   |                             |           |         |    must be **UDP**.                 |
   |                             |           |         | -  When the protocol used           |
   |                             |           |         |    by the listener is               |
   |                             |           |         |    **HTTP** or                      |
   |                             |           |         |    **TERMINATED_HTTPS**,            |
   |                             |           |         |    the protocol of the              |
   |                             |           |         |    backend server group             |
   |                             |           |         |    must be **HTTP**.                |
   +-----------------------------+-----------+---------+-------------------------------------+
   | default_tls_container_ref   | No        | String  | Specifies the ID of the             |
   |                             |           |         | server certificate used by          |
   |                             |           |         | the listener.                       |
   |                             |           |         |                                     |
   |                             |           |         | This parameter is mandatory         |
   |                             |           |         | when **protocol** is set to         |
   |                             |           |         | **TERMINATED_HTTPS**.               |
   |                             |           |         |                                     |
   |                             |           |         | The default value is                |
   |                             |           |         | **null** when **protocol**          |
   |                             |           |         | is not set to                       |
   |                             |           |         | **TERMINATED_HTTPS**.               |
   |                             |           |         |                                     |
   |                             |           |         | The value contains a                |
   |                             |           |         | maximum of 128 characters.          |
   |                             |           |         |                                     |
   |                             |           |         | NOTE:                               |
   |                             |           |         | This parameter is valid             |
   |                             |           |         | only when **protocol** is           |
   |                             |           |         | set to                              |
   |                             |           |         | **TERMINATED_HTTPS**.               |
   +-----------------------------+-----------+---------+-------------------------------------+
   | client_ca_tls_container_ref | No        | String  | Specifies the ID of the CA          |
   |                             |           |         | certificate used by the             |
   |                             |           |         | listener.                           |
   |                             |           |         |                                     |
   |                             |           |         | The default value is                |
   |                             |           |         | **null**.                           |
   |                             |           |         |                                     |
   |                             |           |         | The value contains a                |
   |                             |           |         | maximum of 128 characters.          |
   |                             |           |         |                                     |
   |                             |           |         | NOTE:                               |
   |                             |           |         | This parameter is valid             |
   |                             |           |         | only when **protocol** is           |
   |                             |           |         | set to                              |
   |                             |           |         | **TERMINATED_HTTPS**.               |
   +-----------------------------+-----------+---------+-------------------------------------+
   | sni_container_refs          | No        | Array   | Lists the IDs of SNI                |
   |                             |           |         | certificates (server                |
   |                             |           |         | certificates with a domain          |
   |                             |           |         | name) used by the listener.         |
   |                             |           |         |                                     |
   |                             |           |         | If the parameter value is           |
   |                             |           |         | an empty list, the SNI              |
   |                             |           |         | feature is disabled.                |
   |                             |           |         |                                     |
   |                             |           |         | The default value is                |
   |                             |           |         | **[]**.                             |
   |                             |           |         |                                     |
   |                             |           |         | NOTE:                               |
   |                             |           |         | This parameter is valid             |
   |                             |           |         | only when **protocol** is           |
   |                             |           |         | set to                              |
   |                             |           |         | **TERMINATED_HTTPS**.               |
   +-----------------------------+-----------+---------+-------------------------------------+
   | tls_ciphers_policy          | No        | String  | Specifies the security              |
   |                             |           |         | policy used by the                  |
   |                             |           |         | listener. This parameter is         |
   |                             |           |         | valid only when the                 |
   |                             |           |         | protocol used by the                |
   |                             |           |         | listener is set to                  |
   |                             |           |         | **TERMINATED_HTTPS**.               |
   |                             |           |         |                                     |
   |                             |           |         | The value can be                    |
   |                             |           |         | **tls-1-0-inherit**,                |
   |                             |           |         | **tls-1-0**, **tls-1-1**,           |
   |                             |           |         | **tls-1-2**, or                     |
   |                             |           |         | **tls-1-2-strict**, and the         |
   |                             |           |         | default value is                    |
   |                             |           |         | **tls-1-0**. For details of         |
   |                             |           |         | cipher suites for each              |
   |                             |           |         | security policy, see :ref:`scl_t3`. |
   +-----------------------------+-----------+---------+-------------------------------------+

.. _scl_t3:
.. table:: **Table 3** **tls_ciphers_policy** parameter description

   +-----------------+-------------------------+------------------------------------------------------------------------+
   | Security Policy | TLS Version             | Cipher Suite                                                           |
   +=================+=========================+========================================================================+
   | tls-1-0-inherit | TLS 1.2 TLS 1.1 TLS 1.0 | ECDHE-RSA-AES256-GCM-SHA384:ECDHE-RSA-AES128                           |
   |                 |                         | -GCM-SHA256:ECDHE-ECDSA-AES256-GCM-SHA384:ECDHE-ECDSA-AES128-GCM-SHA25 |
   |                 |                         | 6:AES128-GCM-SHA256:AES256-GCM-SHA384:ECDHE-ECDSA-AES128-SHA256:ECDHE- |
   |                 |                         | RSA-AES128-SHA256:AES128-SHA256:AES256-SHA256:ECDHE-ECDSA-AES256-SHA38 |
   |                 |                         | 4:ECDHE-RSA-AES256-SHA384:ECDHE-ECDSA-AES128-SHA:ECDHE-RSA-AES128-SHA: |
   |                 |                         | DHE-RSA-AES128-SHA:ECDHE-RSA-AES256-SHA:ECDHE-ECDSA-AES256-SHA:AES128- |
   |                 |                         | SHA:AES256-SHA:DHE-DSS-AES128-SHA:CAMELLIA128-SHA:EDH-RSA-DES-CBC3-SHA |
   |                 |                         | :DES-CBC3-SHA:ECDHE-RSA-RC4-SHA:RC4-SHA:DHE-RSA-AES256-SHA:DHE-DSS-AES |
   |                 |                         | 256-SHA:DHE-RSA-CAMELLIA256-SHA:DHE-DSS-CAMELLIA256-SHA:CAMELLIA256-SH |
   |                 |                         | A:EDH-DSS-DES-CBC3-SHA:DHE-RSA-CAMELLIA128-SHA:DHE-DSS-CAMELLIA128-SHA |
   +-----------------+-------------------------+------------------------------------------------------------------------+
   | tls-1-0         | TLS 1.2 TLS 1.1 TLS 1.0 | ECDHE-RSA-AES256-GCM-SHA384:ECDHE-RSA-A                                |
   |                 |                         | ES128-GCM-SHA256:ECDHE-ECDSA-AES256-GCM-SHA384:ECDHE-ECDSA-AES128-GCM- |
   |                 |                         | SHA256:AES128-GCM-SHA256:AES256-GCM-SHA384:ECDHE-ECDSA-AES128-SHA256:E |
   |                 |                         | CDHE-RSA-AES128-SHA256:AES128-SHA256:AES256-SHA256:ECDHE-ECDSA-AES256- |
   |                 |                         | SHA384:ECDHE-RSA-AES256-SHA384:ECDHE-ECDSA-AES128-SHA:ECDHE-RSA-AES128 |
   |                 |                         | -SHA:ECDHE-RSA-AES256-SHA:ECDHE-ECDSA-AES256-SHA:AES128-SHA:AES256-SHA |
   +-----------------+-------------------------+------------------------------------------------------------------------+
   | tls-1-1         |                         | TLS 1.2 TLS 1.1                                                        |
   +-----------------+-------------------------+------------------------------------------------------------------------+
   | tls-1-2         |                         | TLS 1.2                                                                |
   +-----------------+-------------------------+------------------------------------------------------------------------+
   | tls-1-2-strict  | TLS 1.2                 | ECDHE-RSA-AES256-GCM-SHA384:ECDHE-RSA-AES128-GCM-SHA256:ECDHE-ECDSA-A  |
   |                 |                         | ES256-GCM-SHA384:ECDHE-ECDSA-AES128-GCM-SHA256:AES128-GCM-SHA256:AES25 |
   |                 |                         | 6-GCM-SHA384:ECDHE-ECDSA-AES128-SHA256:ECDHE-RSA-AES128-SHA256:AES128- |
   |                 |                         | SHA256:AES256-SHA256:ECDHE-ECDSA-AES256-SHA384:ECDHE-RSA-AES256-SHA384 |
   +-----------------+-------------------------+------------------------------------------------------------------------+

Response
^^^^^^^^

.. table:: **Table 4** Response parameters

   +-----------+--------+---------------------------------------------------------+
   | Parameter | Type   | Description                                             |
   +===========+========+=========================================================+
   | listener  | Object | Specifies the listener. For details, see :ref:`scl_t5`. |
   +-----------+--------+---------------------------------------------------------+

.. _scl_t5:
.. table:: **Table 5** **listeners** parameter description

   +-----------------------------+---------+---------------------------------------+
   | Parameter                   | Type    | Description                           |
   +=============================+=========+=======================================+
   | id                          | String  | Specifies the listener ID.            |
   +-----------------------------+---------+---------------------------------------+
   | tenant_id                   | String  | Specifies the ID of the project where |
   |                             |         | the listener is used.                 |
   +-----------------------------+---------+---------------------------------------+
   | name                        | String  | Specifies the listener name.          |
   +-----------------------------+---------+---------------------------------------+
   | description                 | String  | Provides supplementary information    |
   |                             |         | about the listener.                   |
   +-----------------------------+---------+---------------------------------------+
   | protocol                    | String  | Specifies the protocol used by the    |
   |                             |         | listener.                             |
   |                             |         |                                       |
   |                             |         | The value can be **TCP**, **HTTP**,   |
   |                             |         | **UDP**, or **TERMINATED_HTTPS**.     |
   +-----------------------------+---------+---------------------------------------+
   | protocol_port               | Integer | Specifies the port used by the        |
   |                             |         | listener.                             |
   |                             |         |                                       |
   |                             |         | The port number ranges from 1 to      |
   |                             |         | 65535.                                |
   +-----------------------------+---------+---------------------------------------+
   | loadbalancers               | Array   | Specifies the ID of the associated    |
   |                             |         | load balancer. For details, see       |
   |                             |         | :ref:`scl_t6`.                        |
   +-----------------------------+---------+---------------------------------------+
   | connection_limit            | Integer | Specifies the maximum number of       |
   |                             |         | connections.                          |
   |                             |         |                                       |
   |                             |         | The value ranges from **-1** to       |
   |                             |         | **2147483647**. The default value is  |
   |                             |         | **-1**, indicating that there is no   |
   |                             |         | restriction on the maximum number of  |
   |                             |         | connections.                          |
   |                             |         |                                       |
   |                             |         | This parameter is reserved.           |
   +-----------------------------+---------+---------------------------------------+
   | admin_state_up              | Boolean | Specifies the administrative status   |
   |                             |         | of the listener.                      |
   |                             |         |                                       |
   |                             |         | This parameter is reserved. The value |
   |                             |         | can be **true** or **false**.         |
   |                             |         |                                       |
   |                             |         | -  **true**: The load balancer is     |
   |                             |         |    enabled.                           |
   |                             |         | -  **false**: The load balancer is    |
   |                             |         |    disabled.                          |
   +-----------------------------+---------+---------------------------------------+
   | http2_enable                | Boolean | Specifies whether to use HTTP/2.      |
   |                             |         |                                       |
   |                             |         | The value can be **true** or          |
   |                             |         | **false**.                            |
   |                             |         |                                       |
   |                             |         | -  **true**: HTTP/2 is used.          |
   |                             |         | -  **false**: HTTP/2 is not used.     |
   |                             |         |                                       |
   |                             |         | This parameter is valid only when the |
   |                             |         | protocol used by the listener is set  |
   |                             |         | to **TERMINATED_HTTPS**.              |
   +-----------------------------+---------+---------------------------------------+
   | default_pool_id             | String  | Specifies the ID of the associated    |
   |                             |         | backend server group.                 |
   |                             |         |                                       |
   |                             |         | If a request does not match the       |
   |                             |         | forwarding policy, the request is     |
   |                             |         | forwarded to the default backend      |
   |                             |         | server group for processing. If the   |
   |                             |         | value is **null**, the listener has   |
   |                             |         | no default backend server group.      |
   +-----------------------------+---------+---------------------------------------+
   | default_tls_container_ref   | String  | Specifies the ID of the server        |
   |                             |         | certificate used by the listener. For |
   |                             |         | details, see :ref:`scert`.            |
   |                             |         |                                       |
   |                             |         | This parameter is mandatory when      |
   |                             |         | **protocol** is set to                |
   |                             |         | **TERMINATED_HTTPS**.                 |
   +-----------------------------+---------+---------------------------------------+
   | client_ca_tls_container_ref | String  | Specifies the ID of the CA            |
   |                             |         | certificate used by the listener. For |
   |                             |         | details, see :ref:`scert`.            |
   +-----------------------------+---------+---------------------------------------+
   | sni_container_refs          | Array   | Lists the IDs of SNI certificates     |
   |                             |         | (server certificates with a domain    |
   |                             |         | name) used by the listener.           |
   |                             |         |                                       |
   |                             |         | If the parameter value is an empty    |
   |                             |         | list, the SNI feature is disabled.    |
   +-----------------------------+---------+---------------------------------------+
   | tags                        | Array   | Tags the listener.                    |
   +-----------------------------+---------+---------------------------------------+
   | created_at                  | String  | Specifies the time when the listener  |
   |                             |         | was created. The UTC time is in       |
   |                             |         | *YYYY-MM-DDTHH:MM:SS* format.         |
   +-----------------------------+---------+---------------------------------------+
   | updated_at                  | String  | Specifies the time when the listener  |
   |                             |         | was updated. The UTC time is in       |
   |                             |         | *YYYY-MM-DDTHH:MM:SS* format.         |
   +-----------------------------+---------+---------------------------------------+
   | tls_ciphers_policy          | String  | Specifies the security policy used by |
   |                             |         | the listener. This parameter is valid |
   |                             |         | only when the protocol used by the    |
   |                             |         | listener is set to                    |
   |                             |         | **TERMINATED_HTTPS**.                 |
   |                             |         |                                       |
   |                             |         | The value can be **tls-1-0-inherit**, |
   |                             |         | **tls-1-0**, **tls-1-1**,             |
   |                             |         | **tls-1-2**, or **tls-1-2-strict**,   |
   |                             |         | and the default value is **tls-1-0**. |
   |                             |         | For details of cipher suites for each |
   |                             |         | security policy, see :ref:`scl_t3`.   |
   +-----------------------------+---------+---------------------------------------+

.. _scl_t6:
.. table:: **Table 6** **loadbalancers** parameter description

   ========= ====== =================================================
   Parameter Type   Description
   ========= ====== =================================================
   id        String Specifies the ID of the associated load balancer.
   ========= ====== =================================================

Example Request
^^^^^^^^^^^^^^^

-  Example request 1: Adding a TCP listener

   .. code::

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

   .. code::

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

   .. code::

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
^^^^^^^^^^^^^^^^

-  Example response 1

   .. code:: json

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

   .. code:: json

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

   .. code:: json

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
^^^^^^^^^^^

See :ref:`shared_lb_status_code`.

Querying Listeners
==================

Function
^^^^^^^^

This API is used to query the listeners and display them in a list. Filter query and pagination query are supported. Unless otherwise specified, exact match is applied.

You can query listeners using information such as listener ID, protocol used by the listener, port used by the listener, or backend server private IP address.

Constraints
^^^^^^^^^^^

Parameters **marker**, **limit**, and **page_reverse** are used for pagination query. Parameters **marker** and **page_reverse** take effect only when they are used together with parameter **limit**.

URI
^^^

GET /v2.0/lbaas/listeners

Request
^^^^^^^

.. table:: **Table 1** Parameter description

   +-----------------------------+-----------+---------+-----------------------------+
   | Parameter                   | Mandatory | Type    | Description                 |
   +=============================+===========+=========+=============================+
   | marker                      | No        | String  | Specifies the ID of the     |
   |                             |           |         | listener from which         |
   |                             |           |         | pagination query starts,    |
   |                             |           |         | that is, the ID of the last |
   |                             |           |         | listener on the previous    |
   |                             |           |         | page.                       |
   |                             |           |         |                             |
   |                             |           |         | This parameter must be used |
   |                             |           |         | together with **limit**.    |
   +-----------------------------+-----------+---------+-----------------------------+
   | limit                       | No        | Integer | Specifies the number of     |
   |                             |           |         | listeners on each page.     |
   +-----------------------------+-----------+---------+-----------------------------+
   | page_reverse                | No        | Boolean | Specifies the page          |
   |                             |           |         | direction. The value can be |
   |                             |           |         | **true** or **false**, and  |
   |                             |           |         | the default value is        |
   |                             |           |         | **false**. The last page in |
   |                             |           |         | the list requested with     |
   |                             |           |         | **page_reverse** set to     |
   |                             |           |         | **false** will not contain  |
   |                             |           |         | the "next" link, and the    |
   |                             |           |         | last page in the list       |
   |                             |           |         | requested with              |
   |                             |           |         | **page_reverse** set to     |
   |                             |           |         | **true** will not contain   |
   |                             |           |         | the "previous" link.        |
   |                             |           |         |                             |
   |                             |           |         | This parameter must be used |
   |                             |           |         | together with **limit**.    |
   +-----------------------------+-----------+---------+-----------------------------+
   | id                          | No        | String  | Specifies the listener ID.  |
   +-----------------------------+-----------+---------+-----------------------------+
   | tenant_id                   | No        | String  | Specifies the ID of the     |
   |                             |           |         | project where the listener  |
   |                             |           |         | is used.                    |
   +-----------------------------+-----------+---------+-----------------------------+
   | name                        | No        | String  | Specifies the listener      |
   |                             |           |         | name.                       |
   |                             |           |         |                             |
   |                             |           |         | The value contains a        |
   |                             |           |         | maximum of 255 characters.  |
   +-----------------------------+-----------+---------+-----------------------------+
   | description                 | No        | String  | Provides supplementary      |
   |                             |           |         | information about the       |
   |                             |           |         | listener.                   |
   |                             |           |         |                             |
   |                             |           |         | The value contains a        |
   |                             |           |         | maximum of 255 characters.  |
   +-----------------------------+-----------+---------+-----------------------------+
   | loadbalancer_id             | No        | String  | Specifies the ID of the     |
   |                             |           |         | associated load balancer.   |
   +-----------------------------+-----------+---------+-----------------------------+
   | connection_limit            | No        | Integer | Specifies the maximum       |
   |                             |           |         | number of connections.      |
   +-----------------------------+-----------+---------+-----------------------------+
   | admin_state_up              | No        | Boolean | Specifies the               |
   |                             |           |         | administrative status of    |
   |                             |           |         | the listener.               |
   |                             |           |         |                             |
   |                             |           |         | This parameter is reserved, |
   |                             |           |         | and the default value is    |
   |                             |           |         | **true**.                   |
   +-----------------------------+-----------+---------+-----------------------------+
   | default_pool_id             | No        | String  | Specifies the ID of the     |
   |                             |           |         | associated backend server   |
   |                             |           |         | group.                      |
   +-----------------------------+-----------+---------+-----------------------------+
   | http2_enable                | No        | Boolean | Specifies whether to use    |
   |                             |           |         | HTTP/2.                     |
   |                             |           |         |                             |
   |                             |           |         | The value can be **true**   |
   |                             |           |         | or **false**.               |
   |                             |           |         |                             |
   |                             |           |         | -  **true**: HTTP/2 is      |
   |                             |           |         |    used.                    |
   |                             |           |         | -  **false**: HTTP/2 is not |
   |                             |           |         |    used.                    |
   +-----------------------------+-----------+---------+-----------------------------+
   | default_tls_container_ref   | No        | String  | Specifies the ID of the     |
   |                             |           |         | server certificate used by  |
   |                             |           |         | the listener.               |
   |                             |           |         |                             |
   |                             |           |         | The value contains a        |
   |                             |           |         | maximum of 128 characters.  |
   +-----------------------------+-----------+---------+-----------------------------+
   | client_ca_tls_container_ref | No        | String  | Specifies the ID of the CA  |
   |                             |           |         | certificate used by the     |
   |                             |           |         | listener.                   |
   |                             |           |         |                             |
   |                             |           |         | The value contains a        |
   |                             |           |         | maximum of 128 characters.  |
   +-----------------------------+-----------+---------+-----------------------------+
   | protocol                    | No        | String  | Specifies the protocol used |
   |                             |           |         | by the listener.            |
   |                             |           |         |                             |
   |                             |           |         | The value can be **TCP**,   |
   |                             |           |         | **HTTP**, **UDP**, or       |
   |                             |           |         | **TERMINATED_HTTPS**.       |
   +-----------------------------+-----------+---------+-----------------------------+
   | protocol_port               | No        | Integer | Specifies the port used by  |
   |                             |           |         | the listener.               |
   +-----------------------------+-----------+---------+-----------------------------+
   | tls_ciphers_policy          | No        | String  | Specifies the security      |
   |                             |           |         | policy used by the          |
   |                             |           |         | listener. This parameter is |
   |                             |           |         | valid only when the         |
   |                             |           |         | protocol used by the        |
   |                             |           |         | listener is set to          |
   |                             |           |         | **TERMINATED_HTTPS**.       |
   |                             |           |         |                             |
   |                             |           |         | The value can be            |
   |                             |           |         | **tls-1-0**, **tls-1-1**,   |
   |                             |           |         | **tls-1-2**, or             |
   |                             |           |         | **tls-1-2-strict**. For     |
   |                             |           |         | details of cipher suites    |
   |                             |           |         | for each security policy,   |
   |                             |           |         | see :ref:`sll_t2`.          |
   +-----------------------------+-----------+---------+-----------------------------+
   | tls_container_id            | No        | String  | Queries the listener        |
   |                             |           |         | associated with the         |
   |                             |           |         | certificate.                |
   +-----------------------------+-----------+---------+-----------------------------+
   | sni_container_refs          | No        | String  | Queries the listener        |
   |                             |           |         | associated with the SNI     |
   |                             |           |         | certificate.                |
   +-----------------------------+-----------+---------+-----------------------------+

.. _sll_t2:
.. table:: **Table 2** **tls_ciphers_policy** parameter description

   +-----------------+-------------------------+------------------------------------------------------------------------+
   | Security Policy | TLS Version             | Cipher Suite                                                           |
   +=================+=========================+========================================================================+
   | tls-1-0-inherit | TLS 1.2 TLS 1.1 TLS 1.0 | ECDHE-RSA-AES256-GCM-SHA384:ECDHE-RSA-AES128                           |
   |                 |                         | -GCM-SHA256:ECDHE-ECDSA-AES256-GCM-SHA384:ECDHE-ECDSA-AES128-GCM-SHA25 |
   |                 |                         | 6:AES128-GCM-SHA256:AES256-GCM-SHA384:ECDHE-ECDSA-AES128-SHA256:ECDHE- |
   |                 |                         | RSA-AES128-SHA256:AES128-SHA256:AES256-SHA256:ECDHE-ECDSA-AES256-SHA38 |
   |                 |                         | 4:ECDHE-RSA-AES256-SHA384:ECDHE-ECDSA-AES128-SHA:ECDHE-RSA-AES128-SHA: |
   |                 |                         | DHE-RSA-AES128-SHA:ECDHE-RSA-AES256-SHA:ECDHE-ECDSA-AES256-SHA:AES128- |
   |                 |                         | SHA:AES256-SHA:DHE-DSS-AES128-SHA:CAMELLIA128-SHA:EDH-RSA-DES-CBC3-SHA |
   |                 |                         | :DES-CBC3-SHA:ECDHE-RSA-RC4-SHA:RC4-SHA:DHE-RSA-AES256-SHA:DHE-DSS-AES |
   |                 |                         | 256-SHA:DHE-RSA-CAMELLIA256-SHA:DHE-DSS-CAMELLIA256-SHA:CAMELLIA256-SH |
   |                 |                         | A:EDH-DSS-DES-CBC3-SHA:DHE-RSA-CAMELLIA128-SHA:DHE-DSS-CAMELLIA128-SHA |
   +-----------------+-------------------------+------------------------------------------------------------------------+
   | tls-1-0         | TLS 1.2 TLS 1.1 TLS 1.0 | ECDHE-RSA-AES256-GCM-SHA384:ECDHE-RSA-A                                |
   |                 |                         | ES128-GCM-SHA256:ECDHE-ECDSA-AES256-GCM-SHA384:ECDHE-ECDSA-AES128-GCM- |
   |                 |                         | SHA256:AES128-GCM-SHA256:AES256-GCM-SHA384:ECDHE-ECDSA-AES128-SHA256:E |
   |                 |                         | CDHE-RSA-AES128-SHA256:AES128-SHA256:AES256-SHA256:ECDHE-ECDSA-AES256- |
   |                 |                         | SHA384:ECDHE-RSA-AES256-SHA384:ECDHE-ECDSA-AES128-SHA:ECDHE-RSA-AES128 |
   |                 |                         | -SHA:ECDHE-RSA-AES256-SHA:ECDHE-ECDSA-AES256-SHA:AES128-SHA:AES256-SHA |
   +-----------------+-------------------------+------------------------------------------------------------------------+
   | tls-1-1         |                         | TLS 1.2 TLS 1.1                                                        |
   +-----------------+-------------------------+------------------------------------------------------------------------+
   | tls-1-2         |                         | TLS 1.2                                                                |
   +-----------------+-------------------------+------------------------------------------------------------------------+
   | tls-1-2-strict  | TLS 1.2                 | ECDHE-RSA-AES256-GCM-SHA384:ECDHE-RSA-AES128-GCM-SHA256:ECDHE-ECDSA-A  |
   |                 |                         | ES256-GCM-SHA384:ECDHE-ECDSA-AES128-GCM-SHA256:AES128-GCM-SHA256:AES25 |
   |                 |                         | 6-GCM-SHA384:ECDHE-ECDSA-AES128-SHA256:ECDHE-RSA-AES128-SHA256:AES128- |
   |                 |                         | SHA256:AES256-SHA256:ECDHE-ECDSA-AES256-SHA384:ECDHE-RSA-AES256-SHA384 |
   +-----------------+-------------------------+------------------------------------------------------------------------+

Response
^^^^^^^^

.. table:: **Table 3** Parameter description

   +-----------------+-------+-----------------------------------------------------------------------------------------+
   | Parameter       | Type  | Description                                                                             |
   +=================+=======+=========================================================================================+
   | listeners       | Array | Lists the listeners. For details, see :ref:`sll_t4`.                                    |
   +-----------------+-------+-----------------------------------------------------------------------------------------+
   | listeners_links | Array | Provides links to the previous or next page during pagination query, respectively. This |
   |                 |       | parameter exists only in the response body of pagination query. For details, see        |
   |                 |       | :ref:`sll_t7`.                                                                          |
   +-----------------+-------+-----------------------------------------------------------------------------------------+

.. _sll_t4:
.. table:: **Table 4** **listeners** parameter description

   +-----------------------------+---------+---------------------------------------+
   | Parameter                   | Type    | Description                           |
   +=============================+=========+=======================================+
   | id                          | String  | Specifies the listener ID.            |
   +-----------------------------+---------+---------------------------------------+
   | tenant_id                   | String  | Specifies the ID of the project where |
   |                             |         | the listener is used.                 |
   |                             |         |                                       |
   |                             |         | The value contains a maximum of 255   |
   |                             |         | characters.                           |
   +-----------------------------+---------+---------------------------------------+
   | name                        | String  | Specifies the listener name.          |
   |                             |         |                                       |
   |                             |         | The value contains a maximum of 255   |
   |                             |         | characters.                           |
   +-----------------------------+---------+---------------------------------------+
   | description                 | String  | Provides supplementary information    |
   |                             |         | about the listener.                   |
   |                             |         |                                       |
   |                             |         | The value contains a maximum of 255   |
   |                             |         | characters.                           |
   +-----------------------------+---------+---------------------------------------+
   | protocol                    | String  | Specifies the protocol used by the    |
   |                             |         | listener.                             |
   |                             |         |                                       |
   |                             |         | The value can be **TCP**, **HTTP**,   |
   |                             |         | **UDP**, or **TERMINATED_HTTPS**.     |
   +-----------------------------+---------+---------------------------------------+
   | protocol_port               | Integer | Specifies the port used by the        |
   |                             |         | listener.                             |
   |                             |         |                                       |
   |                             |         | The port number ranges from 1 to      |
   |                             |         | 65535.                                |
   +-----------------------------+---------+---------------------------------------+
   | loadbalancers               | Array   | Specifies the ID of the associated    |
   |                             |         | load balancer.                        |
   +-----------------------------+---------+---------------------------------------+
   | connection_limit            | Integer | Specifies the maximum number of       |
   |                             |         | connections.                          |
   |                             |         |                                       |
   |                             |         | The value ranges from **-1** to       |
   |                             |         | **2147483647**.                       |
   |                             |         |                                       |
   |                             |         | NOTE:                                 |
   |                             |         | This parameter is reserved. The       |
   |                             |         | default value is **-1**, indicating   |
   |                             |         | that there is no restriction on the   |
   |                             |         | maximum number of connections.        |
   +-----------------------------+---------+---------------------------------------+
   | admin_state_up              | Boolean | Specifies the administrative status   |
   |                             |         | of the listener.                      |
   |                             |         |                                       |
   |                             |         | This parameter is reserved. The value |
   |                             |         | can be **true** or **false**.         |
   |                             |         |                                       |
   |                             |         | -  **true**: Enabled                  |
   |                             |         | -  **false**: Disabled                |
   +-----------------------------+---------+---------------------------------------+
   | http2_enable                | Boolean | Specifies whether to use HTTP/2.      |
   |                             |         |                                       |
   |                             |         | The value can be **true** or          |
   |                             |         | **false**.                            |
   |                             |         |                                       |
   |                             |         | -  **true**: HTTP/2 will be used.     |
   |                             |         | -  **false**: HTTP/2 will not be      |
   |                             |         |    used.                              |
   |                             |         |                                       |
   |                             |         | NOTE:                                 |
   |                             |         | This parameter is valid only when the |
   |                             |         | protocol used by the listener is set  |
   |                             |         | to **TERMINATED_HTTPS**.              |
   +-----------------------------+---------+---------------------------------------+
   | keepalive_timeout           | Integer | Specifies the idle timeout duration   |
   |                             |         | in the unit of second.                |
   |                             |         |                                       |
   |                             |         | This parameter applies only to TCP,   |
   |                             |         | HTTP, or HTTPS listeners.             |
   |                             |         |                                       |
   |                             |         | The value can be one of the           |
   |                             |         | following:                            |
   |                             |         |                                       |
   |                             |         | -  TCP listeners: The value ranges    |
   |                             |         |    from **10** to **4000**, and the   |
   |                             |         |    default value is **300**.          |
   |                             |         |                                       |
   |                             |         | -  HTTP or HTTPS listeners: The value |
   |                             |         |    ranges from **0** to **4000**, and |
   |                             |         |    the default value is **60**.       |
   +-----------------------------+---------+---------------------------------------+
   | client_timeout              | Integer | Specifies the request timeout         |
   |                             |         | duration in the unit of second.       |
   |                             |         |                                       |
   |                             |         | The value ranges from **1** to        |
   |                             |         | **300**. The default value is **60**. |
   |                             |         |                                       |
   |                             |         | This parameter is valid only when     |
   |                             |         | **protocol** is set to **HTTP** or    |
   |                             |         | **HTTPS**. In other cases, the        |
   |                             |         | request body does not contain this    |
   |                             |         | parameter. Otherwise, an error is     |
   |                             |         | reported. When **protocol** is set to |
   |                             |         | **HTTP** or **HTTPS**, if the request |
   |                             |         | body does not contain this parameter  |
   |                             |         | or the value of this parameter is     |
   |                             |         | **null**, the default value is used.  |
   +-----------------------------+---------+---------------------------------------+
   | member_timeout              | Integer | Specifies the response timeout        |
   |                             |         | duration in the unit of second.       |
   |                             |         |                                       |
   |                             |         | The value ranges from **1** to        |
   |                             |         | **300**. The default value is **60**. |
   |                             |         |                                       |
   |                             |         | This parameter is valid only when     |
   |                             |         | **protocol** is set to **HTTP** or    |
   |                             |         | **HTTPS**. In other cases, the        |
   |                             |         | request body does not contain this    |
   |                             |         | parameter. Otherwise, an error is     |
   |                             |         | reported. When **protocol** is set to |
   |                             |         | **HTTP** or **HTTPS**, if the request |
   |                             |         | body does not contain this parameter  |
   |                             |         | or the value of this parameter is     |
   |                             |         | **null**, the default value is used.  |
   +-----------------------------+---------+---------------------------------------+
   | default_pool_id             | String  | Specifies the ID of the associated    |
   |                             |         | backend server group.                 |
   |                             |         |                                       |
   |                             |         | NOTE:                                 |
   |                             |         | If a request does not match the       |
   |                             |         | forwarding policy, the request is     |
   |                             |         | forwarded to the default backend      |
   |                             |         | server group for processing. If the   |
   |                             |         | value is **null**, the listener has   |
   |                             |         | no default backend server group.      |
   +-----------------------------+---------+---------------------------------------+
   | default_tls_container_ref   | String  | Specifies the ID of the server        |
   |                             |         | certificate used by the listener.     |
   |                             |         |                                       |
   |                             |         | This parameter is mandatory when      |
   |                             |         | **protocol** is set to                |
   |                             |         | **TERMINATED_HTTPS**.                 |
   |                             |         |                                       |
   |                             |         | The value contains a maximum of 128   |
   |                             |         | characters.                           |
   +-----------------------------+---------+---------------------------------------+
   | client_ca_tls_container_ref | String  | Specifies the ID of the CA            |
   |                             |         | certificate used by the listener.     |
   |                             |         |                                       |
   |                             |         | The value contains a maximum of 128   |
   |                             |         | characters.                           |
   +-----------------------------+---------+---------------------------------------+
   | sni_container_refs          | Array   | Lists the IDs of SNI certificates     |
   |                             |         | (server certificates with a domain    |
   |                             |         | name) used by the listener.           |
   +-----------------------------+---------+---------------------------------------+
   | tags                        | Array   | Tags the listener.                    |
   +-----------------------------+---------+---------------------------------------+
   | created_at                  | String  | Specifies the time when the listener  |
   |                             |         | was created. The UTC time is in       |
   |                             |         | *YYYY-MM-DDTHH:MM:SS* format.         |
   |                             |         |                                       |
   |                             |         | The value contains a maximum of 19    |
   |                             |         | characters.                           |
   +-----------------------------+---------+---------------------------------------+
   | updated_at                  | String  | Specifies the time when the listener  |
   |                             |         | was updated. The UTC time is in       |
   |                             |         | *YYYY-MM-DDTHH:MM:SS* format.         |
   |                             |         |                                       |
   |                             |         | The value contains a maximum of 19    |
   |                             |         | characters.                           |
   +-----------------------------+---------+---------------------------------------+
   | listeners_links             | Array   | Provides links to the previous or     |
   |                             |         | next page during pagination query,    |
   |                             |         | respectively. This parameter exists   |
   |                             |         | only in the response body of          |
   |                             |         | pagination query.                     |
   +-----------------------------+---------+---------------------------------------+
   | tls_ciphers_policy          | String  | Specifies the security policy used by |
   |                             |         | the listener. This parameter is valid |
   |                             |         | only when the protocol used by the    |
   |                             |         | listener is set to                    |
   |                             |         | **TERMINATED_HTTPS**.                 |
   |                             |         |                                       |
   |                             |         | The value can be **tls-1-0-inherit**, |
   |                             |         | **tls-1-0**, **tls-1-1**,             |
   |                             |         | **tls-1-2**, or **tls-1-2-strict**,   |
   |                             |         | and the default value is **tls-1-0**. |
   |                             |         | For details of cipher suites for each |
   |                             |         | security policy, see :ref:`sll_t6`.   |
   +-----------------------------+---------+---------------------------------------+

.. _sll_t5:
.. table:: **Table 5** **loadbalancers** parameter description

   ========= ====== =================================================
   Parameter Type   Description
   ========= ====== =================================================
   id        String Specifies the ID of the associated load balancer.
   ========= ====== =================================================

.. _sll_t6:
.. table:: **Table 6** **tls_ciphers_policy** parameter description

   +-----------------+-------------------------+------------------------------------------------------------------------+
   | Security Policy | TLS Version             | Cipher Suite                                                           |
   +=================+=========================+========================================================================+
   | tls-1-0-inherit | TLS 1.2 TLS 1.1 TLS 1.0 | ECDHE-RSA-AES256-GCM-SHA384:ECDHE-RSA-AES128                           |
   |                 |                         | -GCM-SHA256:ECDHE-ECDSA-AES256-GCM-SHA384:ECDHE-ECDSA-AES128-GCM-SHA25 |
   |                 |                         | 6:AES128-GCM-SHA256:AES256-GCM-SHA384:ECDHE-ECDSA-AES128-SHA256:ECDHE- |
   |                 |                         | RSA-AES128-SHA256:AES128-SHA256:AES256-SHA256:ECDHE-ECDSA-AES256-SHA38 |
   |                 |                         | 4:ECDHE-RSA-AES256-SHA384:ECDHE-ECDSA-AES128-SHA:ECDHE-RSA-AES128-SHA: |
   |                 |                         | DHE-RSA-AES128-SHA:ECDHE-RSA-AES256-SHA:ECDHE-ECDSA-AES256-SHA:AES128- |
   |                 |                         | SHA:AES256-SHA:DHE-DSS-AES128-SHA:CAMELLIA128-SHA:EDH-RSA-DES-CBC3-SHA |
   |                 |                         | :DES-CBC3-SHA:ECDHE-RSA-RC4-SHA:RC4-SHA:DHE-RSA-AES256-SHA:DHE-DSS-AES |
   |                 |                         | 256-SHA:DHE-RSA-CAMELLIA256-SHA:DHE-DSS-CAMELLIA256-SHA:CAMELLIA256-SH |
   |                 |                         | A:EDH-DSS-DES-CBC3-SHA:DHE-RSA-CAMELLIA128-SHA:DHE-DSS-CAMELLIA128-SHA |
   +-----------------+-------------------------+------------------------------------------------------------------------+
   | tls-1-0         | TLS 1.2 TLS 1.1 TLS 1.0 | ECDHE-RSA-AES256-GCM-SHA384:ECDHE-RSA-A                                |
   |                 |                         | ES128-GCM-SHA256:ECDHE-ECDSA-AES256-GCM-SHA384:ECDHE-ECDSA-AES128-GCM- |
   |                 |                         | SHA256:AES128-GCM-SHA256:AES256-GCM-SHA384:ECDHE-ECDSA-AES128-SHA256:E |
   |                 |                         | CDHE-RSA-AES128-SHA256:AES128-SHA256:AES256-SHA256:ECDHE-ECDSA-AES256- |
   |                 |                         | SHA384:ECDHE-RSA-AES256-SHA384:ECDHE-ECDSA-AES128-SHA:ECDHE-RSA-AES128 |
   |                 |                         | -SHA:ECDHE-RSA-AES256-SHA:ECDHE-ECDSA-AES256-SHA:AES128-SHA:AES256-SHA |
   +-----------------+-------------------------+------------------------------------------------------------------------+
   | tls-1-1         |                         | TLS 1.2 TLS 1.1                                                        |
   +-----------------+-------------------------+------------------------------------------------------------------------+
   | tls-1-2         |                         | TLS 1.2                                                                |
   +-----------------+-------------------------+------------------------------------------------------------------------+
   | tls-1-2-strict  | TLS 1.2                 | ECDHE-RSA-AES256-GCM-SHA384:ECDHE-RSA-AES128-GCM-SHA256:ECDHE-ECDSA-A  |
   |                 |                         | ES256-GCM-SHA384:ECDHE-ECDSA-AES128-GCM-SHA256:AES128-GCM-SHA256:AES25 |
   |                 |                         | 6-GCM-SHA384:ECDHE-ECDSA-AES128-SHA256:ECDHE-RSA-AES128-SHA256:AES128- |
   |                 |                         | SHA256:AES256-SHA256:ECDHE-ECDSA-AES256-SHA384:ECDHE-RSA-AES256-SHA384 |
   +-----------------+-------------------------+------------------------------------------------------------------------+

.. _sll_t7:
.. table:: **Table 7** **listeners_links** parameter description

   +-----------+--------+---------------------------------------+
   | Parameter | Type   | Description                           |
   +===========+========+=======================================+
   | href      | String | Provides links to the previous or     |
   |           |        | next page during pagination query,    |
   |           |        | respectively.                         |
   +-----------+--------+---------------------------------------+
   | rel       | String | Specifies the prompt of the previous  |
   |           |        | or next page.                         |
   |           |        |                                       |
   |           |        | The value can be **next** or          |
   |           |        | **previous**. The value **next**      |
   |           |        | indicates the href containing the URL |
   |           |        | of the next page, and **previous**    |
   |           |        | indicates the href containing the URL |
   |           |        | of the previous page.                 |
   +-----------+--------+---------------------------------------+

Example Request
^^^^^^^^^^^^^^^

-  Example request 1: Querying all listeners

   .. code::

      GET https://{Endpoint}/v2.0/lbaas/listeners?limit=2

-  Request example 2: Querying UDP listeners

   .. code::

      GET https://{Endpoint}/v2.0/lbaas/listeners?protocol=UDP

Example Response
^^^^^^^^^^^^^^^^

-  Example response 1

   .. code:: json

      {
          "listeners": [
              {
                  "client_ca_tls_container_ref": null,
                  "protocol": "TCP",
                  "description": "",
                  "default_tls_container_ref": null,
                  "admin_state_up": true,
                  "http2_enable": false,
                  "loadbalancers": [
                      {
                          "id": "bc7ba445-035a-4464-a1a3-a62cf4a14116"
                      }
                  ],
                  "tenant_id": "601240b9c5c94059b63d484c92cfe308",

                  "sni_container_refs": [],
                  "connection_limit": -1,
                  "protocol_port": 80,
                  "default_pool_id": "ed75f16e-fcc6-403e-a3fb-4eae82005eab",
                  "id": "75045172-70e9-480d-9443-b8b6459948f7",
                  "tags": [],
                  "name": "listener-cb2n",
                  "tls_ciphers_policy": null,
                  "created_at": "2018-07-25T01:54:13",
                  "updated_at": "2018-07-25T01:54:14"
              },
              {
                  "client_ca_tls_container_ref": null,
                  "protocol": "TCP",
                  "description": "",
                  "default_tls_container_ref": null,
                  "admin_state_up": true,
                  "http2_enable": false,
                  "loadbalancers": [
                      {
                          "id": "165b6a38-5278-4569-b747-b2ee65ea84a4"
                      }
                  ],
                  "tenant_id": "601240b9c5c94059b63d484c92cfe308",

                  "sni_container_refs": [],
                  "connection_limit": -1,
                  "protocol_port": 8080,
                  "default_pool_id": null,
                  "id": "dada0003-7b0e-4de8-a4e1-1e937be2ba14",
                  "tags": [],
                  "name": "lsnr_name_mod",
                  "tls_ciphers_policy": null,
                  "created_at": "2018-07-25T01:54:13",
                  "updated_at": "2018-07-25T01:54:14"

      ,

              }
          ],
          "listeners_links": [
              {
              "href": "https://{Endpoint}/v2.0/lbaas/listeners?limit=2&marker=042cc6a5-e385-4e39-83de-4dde1f801ccb",
              "rel": "next"
              },
              {
              "href": "https://{Endpoint}/v2.0/lbaas/listeners?limit=2&marker=025fcaa9-0159-4a0d-8583-d97fa77d9972&page_reverse=True",
              "rel": "previous"
              }
          ]
      }

-  Example response 2

   .. code:: json

      {
          "listeners": [
              {
                  "protocol_port": 64809,
                  "protocol": "UDP",
                  "description": "",
                  "default_tls_container_ref": null,
                  "sni_container_refs": [],
                  "loadbalancers": [
                      {
                          "id": "c1127125-64a9-4394-a08a-ef3be8f7ef9c"
                      }
                  ],
                  "tenant_id": "601240b9c5c94059b63d484c92cfe308",

                  "created_at": "2018-11-29T13:56:21",
                  "client_ca_tls_container_ref": null,
                  "connection_limit": -1,
                  "updated_at": "2018-11-29T13:56:22",
                  "http2_enable": false,

                  "tls_ciphers_policy": null,
                  "admin_state_up": true,
                  "default_pool_id": "2f6895be-019b-4c82-9b53-c4a2ac009e20",
                  "id": "5c63d176-444f-4c75-9cfe-bcb8a05a845c",
                  "tags": [],
                  "name": "listener-tvp8"
              }
          ]
      }

Status Code
^^^^^^^^^^^

See :ref:`shared_lb_status_code`.

Querying Details of a Listener
==============================

Function
^^^^^^^^

This API is used to query details about a listener using its ID.

URI
^^^

GET /v2.0/lbaas/listeners/{listener_id}

.. table:: **Table 1** Parameter description

   =========== ========= ====== ==========================
   Parameter   Mandatory Type   Description
   =========== ========= ====== ==========================
   listener_id Yes       String Specifies the listener ID.
   =========== ========= ====== ==========================

Request
^^^^^^^

None

Response
^^^^^^^^

.. table:: **Table 2** Response parameters

   +-----------+--------+------------------------------------------------------+
   | Parameter | Type   | Description                                          |
   +===========+========+======================================================+
   | listener  | Object | Lists the listeners. For details, see :ref:`ssl_t3`. |
   +-----------+--------+------------------------------------------------------+

.. _ssl_t3:
.. table:: **Table 3** **listeners** parameter description

   +-----------------------------+---------+---------------------------------------+
   | Parameter                   | Type    | Description                           |
   +=============================+=========+=======================================+
   | id                          | String  | Specifies the listener ID.            |
   +-----------------------------+---------+---------------------------------------+
   | tenant_id                   | String  | Specifies the ID of the project where |
   |                             |         | the listener is used.                 |
   +-----------------------------+---------+---------------------------------------+
   | name                        | String  | Specifies the listener name.          |
   +-----------------------------+---------+---------------------------------------+
   | description                 | String  | Provides supplementary information    |
   |                             |         | about the listener.                   |
   +-----------------------------+---------+---------------------------------------+
   | protocol                    | String  | Specifies the protocol used by the    |
   |                             |         | listener.                             |
   |                             |         |                                       |
   |                             |         | The value can be **TCP**, **HTTP**,   |
   |                             |         | **UDP**, or **TERMINATED_HTTPS**.     |
   +-----------------------------+---------+---------------------------------------+
   | protocol_port               | Integer | Specifies the port used by the        |
   |                             |         | listener.                             |
   |                             |         |                                       |
   |                             |         | The port number ranges from 1 to      |
   |                             |         | 65535.                                |
   +-----------------------------+---------+---------------------------------------+
   | loadbalancers               | Array   | Specifies the ID of the associated    |
   |                             |         | load balancer. For details, see       |
   |                             |         | :ref:`scl_t6`.                        |
   +-----------------------------+---------+---------------------------------------+
   | connection_limit            | Integer | Specifies the maximum number of       |
   |                             |         | connections.                          |
   |                             |         |                                       |
   |                             |         | The value ranges from **-1** to       |
   |                             |         | **2147483647**. The default value is  |
   |                             |         | **-1**, indicating that there is no   |
   |                             |         | restriction on the maximum number of  |
   |                             |         | connections.                          |
   |                             |         |                                       |
   |                             |         | This parameter is reserved.           |
   +-----------------------------+---------+---------------------------------------+
   | admin_state_up              | Boolean | Specifies the administrative status   |
   |                             |         | of the listener.                      |
   |                             |         |                                       |
   |                             |         | This parameter is reserved. The value |
   |                             |         | can be **true** or **false**.         |
   |                             |         |                                       |
   |                             |         | -  **true**: The load balancer is     |
   |                             |         |    enabled.                           |
   |                             |         | -  **false**: The load balancer is    |
   |                             |         |    disabled.                          |
   +-----------------------------+---------+---------------------------------------+
   | http2_enable                | Boolean | Specifies whether to use HTTP/2.      |
   |                             |         |                                       |
   |                             |         | The value can be **true** or          |
   |                             |         | **false**.                            |
   |                             |         |                                       |
   |                             |         | -  **true**: HTTP/2 is used.          |
   |                             |         | -  **false**: HTTP/2 is not used.     |
   |                             |         |                                       |
   |                             |         | This parameter is valid only when the |
   |                             |         | protocol used by the listener is set  |
   |                             |         | to **TERMINATED_HTTPS**.              |
   +-----------------------------+---------+---------------------------------------+
   | default_pool_id             | String  | Specifies the ID of the associated    |
   |                             |         | backend server group.                 |
   |                             |         |                                       |
   |                             |         | If a request does not match the       |
   |                             |         | forwarding policy, the request is     |
   |                             |         | forwarded to the default backend      |
   |                             |         | server group for processing. If the   |
   |                             |         | value is **null**, the listener has   |
   |                             |         | no default backend server group.      |
   +-----------------------------+---------+---------------------------------------+
   | default_tls_container_ref   | String  | Specifies the ID of the server        |
   |                             |         | certificate used by the listener. For |
   |                             |         | details, :ref:`scert`.                |
   |                             |         |                                       |
   |                             |         | This parameter is mandatory when      |
   |                             |         | **protocol** is set to                |
   |                             |         | **TERMINATED_HTTPS**.                 |
   +-----------------------------+---------+---------------------------------------+
   | client_ca_tls_container_ref | String  | Specifies the ID of the CA            |
   |                             |         | certificate used by the listener. For |
   |                             |         | details, :ref:`scert`.                |
   +-----------------------------+---------+---------------------------------------+
   | sni_container_refs          | Array   | Lists the IDs of SNI certificates     |
   |                             |         | (server certificates with a domain    |
   |                             |         | name) used by the listener.           |
   |                             |         |                                       |
   |                             |         | If the parameter value is an empty    |
   |                             |         | list, the SNI feature is disabled.    |
   +-----------------------------+---------+---------------------------------------+
   | tags                        | Array   | Tags the listener.                    |
   +-----------------------------+---------+---------------------------------------+
   | created_at                  | String  | Specifies the time when the listener  |
   |                             |         | was created. The UTC time is in       |
   |                             |         | *YYYY-MM-DDTHH:MM:SS* format.         |
   +-----------------------------+---------+---------------------------------------+
   | updated_at                  | String  | Specifies the time when the listener  |
   |                             |         | was updated. The UTC time is in       |
   |                             |         | *YYYY-MM-DDTHH:MM:SS* format.         |
   +-----------------------------+---------+---------------------------------------+
   | tls_ciphers_policy          | String  | Specifies the security policy used by |
   |                             |         | the listener. This parameter is valid |
   |                             |         | only when the protocol used by the    |
   |                             |         | listener is set to                    |
   |                             |         | **TERMINATED_HTTPS**.                 |
   |                             |         |                                       |
   |                             |         | The value can be **tls-1-0-inherit**, |
   |                             |         | **tls-1-0**, **tls-1-1**,             |
   |                             |         | **tls-1-2**, or **tls-1-2-strict**,   |
   |                             |         | and the default value is **tls-1-0**. |
   |                             |         | For details of cipher suites for each |
   |                             |         | security policy, see :ref:`scl_t3`.   |
   +-----------------------------+---------+---------------------------------------+

.. ssl_t4:
.. table:: **Table 4** **loadbalancers** parameter description

   ========= ====== =================================================
   Parameter Type   Description
   ========= ====== =================================================
   id        String Specifies the ID of the associated load balancer.
   ========= ====== =================================================

Example Request
^^^^^^^^^^^^^^^

-  Example request: Viewing details of a listener

   .. code::

      GET https://{Endpoint}/v2.0/lbaas/listeners/09e64049-2ab0-4763-a8c5-f4207875dc3e

Example Response
^^^^^^^^^^^^^^^^

-  Example response

   .. code:: json

      {
          "listener": {
              "protocol_port": 8000,
              "protocol": "TCP",
              "description": "",
              "client_ca_tls_container_ref": null,
              "default_tls_container_ref": null,
              "admin_state_up": true,
              "http2_enable": false,
              "loadbalancers": [
                  {
                      "id": "3d77894d-2ffe-4411-ac0a-0d57689779b8"
                  }
              ],
              "tenant_id": "1867112d054b427e808cc6096d8193a1",
              "sni_container_refs": [],
              "connection_limit": -1,
              "default_pool_id": "b7e53dbd-62ab-4505-a280-5c066078a5c9",
              "id": "09e64049-2ab0-4763-a8c5-f4207875dc3e",
              "tags": [],
              "name": "listener-2",
              "tls_ciphers_policy": null,
              "created_at": "2018-07-25T01:54:13",
              "updated_at": "2018-07-25T01:54:14"
          }
      }

Status Code
^^^^^^^^^^^

See :ref:`shared_lb_status_code`.

Updating a Listener
===================

Function
^^^^^^^^

This API is used to update a listener, such as listener name, description, associated backend server groups, and server certificates.

Constraints
^^^^^^^^^^^

-  If the provisioning status of the associated load balancer is not **ACTIVE**, the listener cannot be updated.
-  Only the administrator can specify **connection_limit**.
-  The **default_pool_id** parameter has the following constraints:

   -  Its value cannot be the ID of any backend server group of other listeners.
   -  Its value cannot be the ID of any backend server group associated with the forwarding policies set for other listeners.

-  The relationships between the protocol used by the listener and the protocol of the backend server group are as follows:

   -  When the protocol used by the listener is **TCP**, the protocol of the backend server group must be **TCP**.
   -  When the protocol used by the listener is **UDP**, the protocol of the backend server group must be **UDP**.
   -  When the protocol used by the listener is **HTTP** or **TERMINATED_HTTPS**, the protocol of the backend server group must be **HTTP**.

URI
^^^

PUT /v2.0/lbaas/listeners/{listener_id}

.. table:: **Table 1** Parameter description

   =========== ========= ====== ==========================
   Parameter   Mandatory Type   Description
   =========== ========= ====== ==========================
   listener_id Yes       String Specifies the listener ID.
   =========== ========= ====== ==========================

Request
^^^^^^^

.. table:: **Table 2** Parameter description

   +-----------+-----------+--------+---------------------------------------------------------+
   | Parameter | Mandatory | Type   | Description                                             |
   +===========+===========+========+=========================================================+
   | listener  | Yes       | Object | Specifies the listener. For details, see :ref:`sul_t3`. |
   +-----------+-----------+--------+---------------------------------------------------------+

.. _sul_t3:
.. table:: **Table 3** **listener** parameter description

   +-----------------------------+-----------+---------+-------------------------------------+
   | Parameter                   | Mandatory | Type    | Description                         |
   +=============================+===========+=========+=====================================+
   | name                        | No        | String  | Specifies the listener              |
   |                             |           |         | name.                               |
   |                             |           |         |                                     |
   |                             |           |         | The value contains a                |
   |                             |           |         | maximum of 255 characters.          |
   +-----------------------------+-----------+---------+-------------------------------------+
   | description                 | No        | String  | Provides supplementary              |
   |                             |           |         | information about the               |
   |                             |           |         | listener.                           |
   |                             |           |         |                                     |
   |                             |           |         | The value contains a                |
   |                             |           |         | maximum of 255 characters.          |
   +-----------------------------+-----------+---------+-------------------------------------+
   | connection_limit            | No        | Integer | Specifies the maximum               |
   |                             |           |         | number of connections.              |
   |                             |           |         |                                     |
   |                             |           |         | The value ranges from               |
   |                             |           |         | **-1** to **2147483647**.           |
   |                             |           |         |                                     |
   |                             |           |         | This parameter is reserved.         |
   |                             |           |         | Only the administrator can          |
   |                             |           |         | specify the maximum number          |
   |                             |           |         | of connections.                     |
   +-----------------------------+-----------+---------+-------------------------------------+
   | http2_enable                | No        | Boolean | Specifies whether to use            |
   |                             |           |         | HTTP/2.                             |
   |                             |           |         |                                     |
   |                             |           |         | The value can be **true**           |
   |                             |           |         | or **false**.                       |
   |                             |           |         |                                     |
   |                             |           |         | -  **true**: HTTP/2 is              |
   |                             |           |         |    used.                            |
   |                             |           |         | -  **false**: HTTP/2 is not         |
   |                             |           |         |    used.                            |
   |                             |           |         |                                     |
   |                             |           |         | This parameter is valid             |
   |                             |           |         | only when the protocol used         |
   |                             |           |         | by the listener is set to           |
   |                             |           |         | **TERMINATED_HTTPS**.               |
   +-----------------------------+-----------+---------+-------------------------------------+
   | default_pool_id             | No        | String  | Specifies the ID of the             |
   |                             |           |         | associated backend server           |
   |                             |           |         | group.                              |
   |                             |           |         |                                     |
   |                             |           |         | If a request does not match         |
   |                             |           |         | the forwarding policy, the          |
   |                             |           |         | request is forwarded to the         |
   |                             |           |         | default backend server              |
   |                             |           |         | group for processing. If            |
   |                             |           |         | the value is **null**, the          |
   |                             |           |         | listener has no default             |
   |                             |           |         | backend server group.               |
   |                             |           |         |                                     |
   |                             |           |         | This parameter has the              |
   |                             |           |         | following constraints:              |
   |                             |           |         |                                     |
   |                             |           |         | -  Its value cannot be the          |
   |                             |           |         |    ID of any backend server         |
   |                             |           |         |    group of other                   |
   |                             |           |         |    listeners.                       |
   |                             |           |         | -  Its value cannot be the          |
   |                             |           |         |    ID of any backend server         |
   |                             |           |         |    group associated with            |
   |                             |           |         |    the forwarding policies          |
   |                             |           |         |    set for other listeners.         |
   |                             |           |         |                                     |
   |                             |           |         | The relationships between           |
   |                             |           |         | the protocol used by the            |
   |                             |           |         | listener and the protocol           |
   |                             |           |         | of the backend server group         |
   |                             |           |         | are as follows:                     |
   |                             |           |         |                                     |
   |                             |           |         | -  When the protocol used           |
   |                             |           |         |    by the listener is               |
   |                             |           |         |    **TCP**, the protocol of         |
   |                             |           |         |    the backend server group         |
   |                             |           |         |    must be **TCP**.                 |
   |                             |           |         | -  When the protocol used           |
   |                             |           |         |    by the listener is               |
   |                             |           |         |    **UDP**, the protocol of         |
   |                             |           |         |    the backend server group         |
   |                             |           |         |    must be **UDP**.                 |
   |                             |           |         | -  When the protocol used           |
   |                             |           |         |    by the listener is               |
   |                             |           |         |    **HTTP** or                      |
   |                             |           |         |    **TERMINATED_HTTPS**,            |
   |                             |           |         |    the protocol of the              |
   |                             |           |         |    backend server group             |
   |                             |           |         |    must be **HTTP**.                |
   +-----------------------------+-----------+---------+-------------------------------------+
   | admin_state_up              | No        | Boolean | Specifies the                       |
   |                             |           |         | administrative status of            |
   |                             |           |         | the listener.                       |
   |                             |           |         |                                     |
   |                             |           |         | This parameter is reserved,         |
   |                             |           |         | and the default value is            |
   |                             |           |         | **true**.                           |
   +-----------------------------+-----------+---------+-------------------------------------+
   | default_tls_container_ref   | No        | String  | Specifies the ID of the             |
   |                             |           |         | server certificate used by          |
   |                             |           |         | the listener.                       |
   |                             |           |         |                                     |
   |                             |           |         | The value contains a                |
   |                             |           |         | maximum of 128 characters.          |
   |                             |           |         |                                     |
   |                             |           |         | NOTE:                               |
   |                             |           |         | This parameter is valid             |
   |                             |           |         | only when **protocol** is           |
   |                             |           |         | set to                              |
   |                             |           |         | **TERMINATED_HTTPS**.               |
   +-----------------------------+-----------+---------+-------------------------------------+
   | client_ca_tls_container_ref | No        | String  | Specifies the ID of the CA          |
   |                             |           |         | certificate used by the             |
   |                             |           |         | listener.                           |
   |                             |           |         |                                     |
   |                             |           |         | The value contains a                |
   |                             |           |         | maximum of 128 characters.          |
   |                             |           |         |                                     |
   |                             |           |         | NOTE:                               |
   |                             |           |         | This parameter is valid             |
   |                             |           |         | only when **protocol** is           |
   |                             |           |         | set to                              |
   |                             |           |         | **TERMINATED_HTTPS**.               |
   +-----------------------------+-----------+---------+-------------------------------------+
   | sni_container_refs          | No        | Array   | Lists the IDs of SNI                |
   |                             |           |         | certificates (server                |
   |                             |           |         | certificates with a domain          |
   |                             |           |         | name) used by the listener.         |
   |                             |           |         |                                     |
   |                             |           |         | If the parameter value is           |
   |                             |           |         | an empty list, the SNI              |
   |                             |           |         | feature is disabled.                |
   |                             |           |         |                                     |
   |                             |           |         | NOTE:                               |
   |                             |           |         | This parameter is valid             |
   |                             |           |         | only when **protocol** is           |
   |                             |           |         | set to                              |
   |                             |           |         | **TERMINATED_HTTPS**.               |
   +-----------------------------+-----------+---------+-------------------------------------+
   | tls_ciphers_policy          | No        | String  | Specifies the security              |
   |                             |           |         | policy used by the                  |
   |                             |           |         | listener. This parameter is         |
   |                             |           |         | valid only when the                 |
   |                             |           |         | protocol used by the                |
   |                             |           |         | listener is set to                  |
   |                             |           |         | **TERMINATED_HTTPS**.               |
   |                             |           |         |                                     |
   |                             |           |         | The value can be                    |
   |                             |           |         | **tls-1-0-inherit**,                |
   |                             |           |         | **tls-1-0**, **tls-1-1**,           |
   |                             |           |         | **tls-1-2**, or                     |
   |                             |           |         | **tls-1-2-strict**, and the         |
   |                             |           |         | default value is                    |
   |                             |           |         | **tls-1-0**. For details of         |
   |                             |           |         | cipher suites for each              |
   |                             |           |         | security policy, see :ref:`sul_t4`. |
   +-----------------------------+-----------+---------+-------------------------------------+

.. _sul_t4:
.. table:: **Table 4** **tls_ciphers_policy** parameter description

   +-----------------+-------------------------+------------------------------------------------------------------------+
   | Security Policy | TLS Version             | Cipher Suite                                                           |
   +=================+=========================+========================================================================+
   | tls-1-0-inherit | TLS 1.2 TLS 1.1 TLS 1.0 | ECDHE-RSA-AES256-GCM-SHA384:ECDHE-RSA-AES128                           |
   |                 |                         | -GCM-SHA256:ECDHE-ECDSA-AES256-GCM-SHA384:ECDHE-ECDSA-AES128-GCM-SHA25 |
   |                 |                         | 6:AES128-GCM-SHA256:AES256-GCM-SHA384:ECDHE-ECDSA-AES128-SHA256:ECDHE- |
   |                 |                         | RSA-AES128-SHA256:AES128-SHA256:AES256-SHA256:ECDHE-ECDSA-AES256-SHA38 |
   |                 |                         | 4:ECDHE-RSA-AES256-SHA384:ECDHE-ECDSA-AES128-SHA:ECDHE-RSA-AES128-SHA: |
   |                 |                         | DHE-RSA-AES128-SHA:ECDHE-RSA-AES256-SHA:ECDHE-ECDSA-AES256-SHA:AES128- |
   |                 |                         | SHA:AES256-SHA:DHE-DSS-AES128-SHA:CAMELLIA128-SHA:EDH-RSA-DES-CBC3-SHA |
   |                 |                         | :DES-CBC3-SHA:ECDHE-RSA-RC4-SHA:RC4-SHA:DHE-RSA-AES256-SHA:DHE-DSS-AES |
   |                 |                         | 256-SHA:DHE-RSA-CAMELLIA256-SHA:DHE-DSS-CAMELLIA256-SHA:CAMELLIA256-SH |
   |                 |                         | A:EDH-DSS-DES-CBC3-SHA:DHE-RSA-CAMELLIA128-SHA:DHE-DSS-CAMELLIA128-SHA |
   +-----------------+-------------------------+------------------------------------------------------------------------+
   | tls-1-0         | TLS 1.2 TLS 1.1 TLS 1.0 | ECDHE-RSA-AES256-GCM-SHA384:ECDHE-RSA-A                                |
   |                 |                         | ES128-GCM-SHA256:ECDHE-ECDSA-AES256-GCM-SHA384:ECDHE-ECDSA-AES128-GCM- |
   |                 |                         | SHA256:AES128-GCM-SHA256:AES256-GCM-SHA384:ECDHE-ECDSA-AES128-SHA256:E |
   |                 |                         | CDHE-RSA-AES128-SHA256:AES128-SHA256:AES256-SHA256:ECDHE-ECDSA-AES256- |
   |                 |                         | SHA384:ECDHE-RSA-AES256-SHA384:ECDHE-ECDSA-AES128-SHA:ECDHE-RSA-AES128 |
   |                 |                         | -SHA:ECDHE-RSA-AES256-SHA:ECDHE-ECDSA-AES256-SHA:AES128-SHA:AES256-SHA |
   +-----------------+-------------------------+------------------------------------------------------------------------+
   | tls-1-1         |                         | TLS 1.2 TLS 1.1                                                        |
   +-----------------+-------------------------+------------------------------------------------------------------------+
   | tls-1-2         |                         | TLS 1.2                                                                |
   +-----------------+-------------------------+------------------------------------------------------------------------+
   | tls-1-2-strict  | TLS 1.2                 | ECDHE-RSA-AES256-GCM-SHA384:ECDHE-RSA-AES128-GCM-SHA256:ECDHE-ECDSA-A  |
   |                 |                         | ES256-GCM-SHA384:ECDHE-ECDSA-AES128-GCM-SHA256:AES128-GCM-SHA256:AES25 |
   |                 |                         | 6-GCM-SHA384:ECDHE-ECDSA-AES128-SHA256:ECDHE-RSA-AES128-SHA256:AES128- |
   |                 |                         | SHA256:AES256-SHA256:ECDHE-ECDSA-AES256-SHA384:ECDHE-RSA-AES256-SHA384 |
   +-----------------+-------------------------+------------------------------------------------------------------------+

Response
^^^^^^^^

.. table:: **Table 5** Response parameters

   +-----------+--------+---------------------------------------------------------+
   | Parameter | Type   | Description                                             |
   +===========+========+=========================================================+
   | listener  | Object | Specifies the listener. For details, see :ref:`sul_t6`. |
   +-----------+--------+---------------------------------------------------------+

.. _sul_t6:
.. table:: **Table 6** **listeners** parameter description

   +-----------------------------+---------+---------------------------------------+
   | Parameter                   | Type    | Description                           |
   +=============================+=========+=======================================+
   | id                          | String  | Specifies the listener ID.            |
   +-----------------------------+---------+---------------------------------------+
   | tenant_id                   | String  | Specifies the ID of the project where |
   |                             |         | the listener is used.                 |
   +-----------------------------+---------+---------------------------------------+
   | name                        | String  | Specifies the listener name.          |
   +-----------------------------+---------+---------------------------------------+
   | description                 | String  | Provides supplementary information    |
   |                             |         | about the listener.                   |
   +-----------------------------+---------+---------------------------------------+
   | protocol                    | String  | Specifies the protocol used by the    |
   |                             |         | listener.                             |
   |                             |         |                                       |
   |                             |         | The value can be **TCP**, **HTTP**,   |
   |                             |         | **UDP**, or **TERMINATED_HTTPS**.     |
   +-----------------------------+---------+---------------------------------------+
   | protocol_port               | Integer | Specifies the port used by the        |
   |                             |         | listener.                             |
   |                             |         |                                       |
   |                             |         | The port number ranges from 1 to      |
   |                             |         | 65535.                                |
   +-----------------------------+---------+---------------------------------------+
   | loadbalancers               | Array   | Specifies the ID of the associated    |
   |                             |         | load balancer. For details, see       |
   |                             |         | :ref:`scl_t6`.                        |
   +-----------------------------+---------+---------------------------------------+
   | connection_limit            | Integer | Specifies the maximum number of       |
   |                             |         | connections.                          |
   |                             |         |                                       |
   |                             |         | The value ranges from **-1** to       |
   |                             |         | **2147483647**. The default value is  |
   |                             |         | **-1**, indicating that there is no   |
   |                             |         | restriction on the maximum number of  |
   |                             |         | connections.                          |
   |                             |         |                                       |
   |                             |         | This parameter is reserved.           |
   +-----------------------------+---------+---------------------------------------+
   | admin_state_up              | Boolean | Specifies the administrative status   |
   |                             |         | of the listener.                      |
   |                             |         |                                       |
   |                             |         | This parameter is reserved. The value |
   |                             |         | can be **true** or **false**.         |
   |                             |         |                                       |
   |                             |         | -  **true**: The load balancer is     |
   |                             |         |    enabled.                           |
   |                             |         | -  **false**: The load balancer is    |
   |                             |         |    disabled.                          |
   +-----------------------------+---------+---------------------------------------+
   | http2_enable                | Boolean | Specifies whether to use HTTP/2.      |
   |                             |         |                                       |
   |                             |         | The value can be **true** or          |
   |                             |         | **false**.                            |
   |                             |         |                                       |
   |                             |         | -  **true**: HTTP/2 is used.          |
   |                             |         | -  **false**: HTTP/2 is not used.     |
   |                             |         |                                       |
   |                             |         | This parameter is valid only when the |
   |                             |         | protocol used by the listener is set  |
   |                             |         | to **TERMINATED_HTTPS**.              |
   +-----------------------------+---------+---------------------------------------+
   | default_pool_id             | String  | Specifies the ID of the associated    |
   |                             |         | backend server group.                 |
   |                             |         |                                       |
   |                             |         | If a request does not match the       |
   |                             |         | forwarding policy, the request is     |
   |                             |         | forwarded to the default backend      |
   |                             |         | server group for processing. If the   |
   |                             |         | value is **null**, the listener has   |
   |                             |         | no default backend server group.      |
   +-----------------------------+---------+---------------------------------------+
   | default_tls_container_ref   | String  | Specifies the ID of the server        |
   |                             |         | certificate used by the listener. For |
   |                             |         | details, see :ref:`scert`.            |
   |                             |         |                                       |
   |                             |         | This parameter is mandatory when      |
   |                             |         | **protocol** is set to                |
   |                             |         | **TERMINATED_HTTPS**.                 |
   +-----------------------------+---------+---------------------------------------+
   | client_ca_tls_container_ref | String  | Specifies the ID of the CA            |
   |                             |         | certificate used by the listener. For |
   |                             |         | details, see :ref:`scert`.            |
   +-----------------------------+---------+---------------------------------------+
   | sni_container_refs          | Array   | Lists the IDs of SNI certificates     |
   |                             |         | (server certificates with a domain    |
   |                             |         | name) used by the listener.           |
   |                             |         |                                       |
   |                             |         | If the parameter value is an empty    |
   |                             |         | list, the SNI feature is disabled.    |
   +-----------------------------+---------+---------------------------------------+
   | tags                        | Array   | Tags the listener.                    |
   +-----------------------------+---------+---------------------------------------+
   | created_at                  | String  | Specifies the time when the listener  |
   |                             |         | was created. The UTC time is in       |
   |                             |         | *YYYY-MM-DDTHH:MM:SS* format.         |
   +-----------------------------+---------+---------------------------------------+
   | updated_at                  | String  | Specifies the time when the listener  |
   |                             |         | was updated. The UTC time is in       |
   |                             |         | *YYYY-MM-DDTHH:MM:SS* format.         |
   +-----------------------------+---------+---------------------------------------+
   | tls_ciphers_policy          | String  | Specifies the security policy used by |
   |                             |         | the listener. This parameter is valid |
   |                             |         | only when the protocol used by the    |
   |                             |         | listener is set to                    |
   |                             |         | **TERMINATED_HTTPS**.                 |
   |                             |         |                                       |
   |                             |         | The value can be **tls-1-0-inherit**, |
   |                             |         | **tls-1-0**, **tls-1-1**,             |
   |                             |         | **tls-1-2**, or **tls-1-2-strict**,   |
   |                             |         | and the default value is **tls-1-0**. |
   |                             |         | For details of cipher suites for each |
   |                             |         | security policy, see :ref:`scl_t3`.   |
   +-----------------------------+---------+---------------------------------------+

.. _sul_t7:
.. table:: **Table 7** **loadbalancers** parameter description

   ========= ====== =================================================
   Parameter Type   Description
   ========= ====== =================================================
   id        String Specifies the ID of the associated load balancer.
   ========= ====== =================================================

Example Request
^^^^^^^^^^^^^^^

-  Example request: Updating a listener

   .. code::

      PUT https://{Endpoint}/v2.0/lbaas/listeners/f622c150-72f5-4263-a47a-e5003c652aa3

      {
          "listener": {
              "description": "my listener",
              "name": "listener-jy-test2",
              "default_pool_id": "c61310de-9a06-4f0c-850c-6f4797b9984c",
              "default_tls_container_ref": "23b58a961a4d4c95be585e98046e657a",
              "client_ca_tls_container_ref": "417a0976969f497db8cbb083bff343ba"
          }
      }

Example Response
^^^^^^^^^^^^^^^^

-  Example response

   .. code:: json

      {
          "listener": {
              "client_ca_tls_container_ref": "417a0976969f497db8cbb083bff343ba",
              "protocol": "TERMINATED_HTTPS",
              "description": "my listener",
              "default_tls_container_ref": "23b58a961a4d4c95be585e98046e657a",
              "admin_state_up": true,
              "http2_enable": false,
              "loadbalancers": [
                  {
                      "id": "165b6a38-5278-4569-b747-b2ee65ea84a4"
                  }
              ],
              "tenant_id": "601240b9c5c94059b63d484c92cfe308",

              "sni_container_refs": [],
              "connection_limit": -1,
              "protocol_port": 443,
              "tags": [],
              "default_pool_id": "c61310de-9a06-4f0c-850c-6f4797b9984c",
              "id": "f622c150-72f5-4263-a47a-e5003c652aa3",
              "name": "listener-jy-test2",
              "tls_ciphers_policy": "tls-1-0",
              "created_at": "2018-07-25T01:54:13",
              "updated_at": "2018-07-25T01:54:14"

          }
      }

Status Code
^^^^^^^^^^^

See :ref:`shared_lb_status_code`.

Deleting a Listener
===================

Function
^^^^^^^^

This API is used to delete a listener by ID.

Constraints
^^^^^^^^^^^

All backend server groups associated with the listener must be deleted before the listener is deleted.

URI
^^^

DELETE /v2.0/lbaas/listeners/{listener_id}

.. table:: **Table 1** Parameter description

   =========== ========= ====== ==========================
   Parameter   Mandatory Type   Description
   =========== ========= ====== ==========================
   listener_id Yes       String Specifies the listener ID.
   =========== ========= ====== ==========================

Request
^^^^^^^

None

Response
^^^^^^^^

None

Example Request
^^^^^^^^^^^^^^^

-  Example request: Deleting a listener

   .. code::

      DELETE https://{Endpoint}/v2.0/lbaas/listeners/35cb8516-1173-4035-8dae-0dae3453f37f

Example Response
^^^^^^^^^^^^^^^^

-  Example response

   None

Status Code
^^^^^^^^^^^

See :ref:`shared_lb_status_code`.

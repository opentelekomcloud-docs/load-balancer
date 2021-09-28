========
Listener
========

Adding a Listener
=================

Function
^^^^^^^^

This API is used to add a listener to a load balancer.

Constraints
^^^^^^^^^^^

Only the administrator can specify **connection_limit**.

-  The listener protocol can be TCP, HTTP, UDP, or HTTPS.

-  For load balancing at Layer 4, the listener protocol can only be TCP or UDP.

-  For load balancing at Layer 7, the listener protocol can only be HTTP or
   HTTPS.

-  For load balancing both at Layer 4 and Layer 7, TCP, UDP, HTTP, and HTTPS
   are supported.

URI
^^^

POST /v3/{project_id}/elb/listeners

.. table:: **Table 1** Path parameters

   ========== ========= ====== =========================
   Parameter  Mandatory Type   Description
   ========== ========= ====== =========================
   project_id Yes       String Specifies the project ID.
   ========== ========= ====== =========================

Request Parameters
^^^^^^^^^^^^^^^^^^

.. table:: **Table 2** Request header parameters

   ============ ========= ====== ================================================
   Parameter    Mandatory Type   Description
   ============ ========= ====== ================================================
   X-Auth-Token Yes       String Specifies the token used for IAM authentication.
   ============ ========= ====== ================================================

.. table:: **Table 3** Request body parameters

   +-----------+-----------+---------------------+-------------------------+
   | Parameter | Mandatory | Type                | Description             |
   +===========+===========+=====================+=========================+
   | listener  | Yes       | :ref:`dlc_o` object | Specifies the listener. |
   +-----------+-----------+---------------------+-------------------------+

.. _dlc_o:
.. table:: **Table 4** CreateListenerOption

   +-----------------------------+-----------+-------------------------+-----------------------------+
   | Parameter                   | Mandatory | Type                    | Description                 |
   +=============================+===========+=========================+=============================+
   | admin_state_up              | No        | Boolean                 | Specifies the               |
   |                             |           |                         | administrative status of    |
   |                             |           |                         | the listener. The value can |
   |                             |           |                         | only be **true**.           |
   |                             |           |                         |                             |
   |                             |           |                         | This parameter is           |
   |                             |           |                         | unsupported. Please do not  |
   |                             |           |                         | use it.                     |
   +-----------------------------+-----------+-------------------------+-----------------------------+
   | client_ca_tls_container_ref | No        | String                  | Specifies the ID of the CA  |
   |                             |           |                         | certificate used by the     |
   |                             |           |                         | listener.                   |
   |                             |           |                         |                             |
   |                             |           |                         | Minimum: **1**              |
   |                             |           |                         |                             |
   |                             |           |                         | Maximum: **128**            |
   +-----------------------------+-----------+-------------------------+-----------------------------+
   | default_pool_id             | No        | String                  | Specifies the ID of the     |
   |                             |           |                         | default backend server      |
   |                             |           |                         | group. If there is no       |
   |                             |           |                         | matched forwarding policy,  |
   |                             |           |                         | requests are forwarded to   |
   |                             |           |                         | the default backend server  |
   |                             |           |                         | for processing.             |
   |                             |           |                         |                             |
   |                             |           |                         | Minimum: **1**              |
   |                             |           |                         |                             |
   |                             |           |                         | Maximum: **36**             |
   +-----------------------------+-----------+-------------------------+-----------------------------+
   | default_tls_container_ref   | No        | String                  | Specifies the ID of the     |
   |                             |           |                         | server certificate used by  |
   |                             |           |                         | the listener.               |
   |                             |           |                         |                             |
   |                             |           |                         | Minimum: **1**              |
   |                             |           |                         |                             |
   |                             |           |                         | Maximum: **128**            |
   +-----------------------------+-----------+-------------------------+-----------------------------+
   | description                 | No        | String                  | Provides supplementary      |
   |                             |           |                         | information about the       |
   |                             |           |                         | listener.                   |
   |                             |           |                         |                             |
   |                             |           |                         | Minimum: **0**              |
   |                             |           |                         |                             |
   |                             |           |                         | Maximum: **255**            |
   +-----------------------------+-----------+-------------------------+-----------------------------+
   | http2_enable                | No        | Boolean                 | Specifies whether to use    |
   |                             |           |                         | HTTP/2. This parameter is   |
   |                             |           |                         | available only for HTTPS    |
   |                             |           |                         | listeners. If you configure |
   |                             |           |                         | this parameter for other    |
   |                             |           |                         | types of listeners, it will |
   |                             |           |                         | not take effect.            |
   |                             |           |                         |                             |
   |                             |           |                         | Enable HTTP/2 if you want   |
   |                             |           |                         | the clients to use HTTP/2   |
   |                             |           |                         | to communicate with the     |
   |                             |           |                         | load balancer. However,     |
   |                             |           |                         | connections between the     |
   |                             |           |                         | load balancer and backend   |
   |                             |           |                         | servers use HTTP/1.x by     |
   |                             |           |                         | default.                    |
   +-----------------------------+-----------+-------------------------+-----------------------------+
   | insert_headers              | No        | :ref:`dlc_ih` object    | Specifies the HTTP header   |
   |                             |           |                         | fields.                     |
   +-----------------------------+-----------+-------------------------+-----------------------------+
   | loadbalancer_id             | Yes       | String                  | Specifies the ID of the     |
   |                             |           |                         | load balancer that the      |
   |                             |           |                         | listener is added to.       |
   |                             |           |                         |                             |
   |                             |           |                         | Minimum: **1**              |
   |                             |           |                         |                             |
   |                             |           |                         | Maximum: **36**             |
   +-----------------------------+-----------+-------------------------+-----------------------------+
   | name                        | No        | String                  | Specifies the listener      |
   |                             |           |                         | name.                       |
   |                             |           |                         |                             |
   |                             |           |                         | Minimum: **0**              |
   |                             |           |                         |                             |
   |                             |           |                         | Maximum: **255**            |
   +-----------------------------+-----------+-------------------------+-----------------------------+
   | project_id                  | No        | String                  | Specifies the project ID.   |
   |                             |           |                         |                             |
   |                             |           |                         | Minimum: **1**              |
   |                             |           |                         |                             |
   |                             |           |                         | Maximum: **32**             |
   +-----------------------------+-----------+-------------------------+-----------------------------+
   | protocol                    | Yes       | String                  | Specifies the protocol used |
   |                             |           |                         | by the listener. The        |
   |                             |           |                         | protocol can be TCP, HTTP,  |
   |                             |           |                         | UDP, or HTTPS.              |
   +-----------------------------+-----------+-------------------------+-----------------------------+
   | protocol_port               | Yes       | Integer                 | Specifies the port used by  |
   |                             |           |                         | the listener.               |
   |                             |           |                         |                             |
   |                             |           |                         | Minimum: **1**              |
   |                             |           |                         |                             |
   |                             |           |                         | Maximum: **65535**          |
   +-----------------------------+-----------+-------------------------+-----------------------------+
   | sni_container_refs          | No        | Array of strings        | Lists the IDs of SNI        |
   |                             |           |                         | certificates (server        |
   |                             |           |                         | certificates with domain    |
   |                             |           |                         | names) used by the          |
   |                             |           |                         | listener.                   |
   |                             |           |                         |                             |
   |                             |           |                         | Each SNI certificate can    |
   |                             |           |                         | have up to 30 domain names, |
   |                             |           |                         | and each domain name in the |
   |                             |           |                         | SNI certificate must be     |
   |                             |           |                         | unique.                     |
   |                             |           |                         |                             |
   |                             |           |                         | This parameter will be      |
   |                             |           |                         | ignored and an empty array  |
   |                             |           |                         | will be returned if the     |
   |                             |           |                         | listener's protocol is not  |
   |                             |           |                         | HTTPS.                      |
   +-----------------------------+-----------+-------------------------+-----------------------------+
   | tags                        | No        | Array of :ref:`dlc_tag` | Lists the tags.             |
   |                             |           | objects                 |                             |
   +-----------------------------+-----------+-------------------------+-----------------------------+
   | tls_ciphers_policy          | No        | String                  | Specifies the security      |
   |                             |           |                         | policy that will be used by |
   |                             |           |                         | the listener.               |
   |                             |           |                         |                             |
   |                             |           |                         | This parameter is available |
   |                             |           |                         | only for HTTPS listeners.   |
   |                             |           |                         | The default value is        |
   |                             |           |                         | **tls-1-0**.                |
   |                             |           |                         |                             |
   |                             |           |                         | An error will be returned   |
   |                             |           |                         | if the protocol of the      |
   |                             |           |                         | listener is not HTTPS.      |
   |                             |           |                         |                             |
   |                             |           |                         | Value options:              |
   |                             |           |                         |                             |
   |                             |           |                         | -  **tls-1-0**              |
   |                             |           |                         |                             |
   |                             |           |                         | -  **tls-1-1**              |
   |                             |           |                         |                             |
   |                             |           |                         | -  **tls-1-2**              |
   |                             |           |                         |                             |
   |                             |           |                         | -  **tls-1-2-strict**       |
   +-----------------------------+-----------+-------------------------+-----------------------------+
   | enable_member_retry         | No        | Boolean                 | Specifies whether to enable |
   |                             |           |                         | health check retries for    |
   |                             |           |                         | backend servers.            |
   |                             |           |                         |                             |
   |                             |           |                         | This parameter is available |
   |                             |           |                         | only for HTTP and HTTPS     |
   |                             |           |                         | listeners.                  |
   |                             |           |                         |                             |
   |                             |           |                         | An error will be returned   |
   |                             |           |                         | if you configure this       |
   |                             |           |                         | parameter for TCP and UDP   |
   |                             |           |                         | listeners.                  |
   |                             |           |                         |                             |
   |                             |           |                         | Default: **true**           |
   +-----------------------------+-----------+-------------------------+-----------------------------+
   | keepalive_timeout           | No        | Integer                 | Specifies the idle timeout  |
   |                             |           |                         | duration, in seconds.       |
   |                             |           |                         |                             |
   |                             |           |                         | -  For TCP listeners, the   |
   |                             |           |                         |    value ranges from **10** |
   |                             |           |                         |    to **4000**, and the     |
   |                             |           |                         |    default value is         |
   |                             |           |                         |    **300**.                 |
   |                             |           |                         |                             |
   |                             |           |                         | -  For HTTP and HTTPS       |
   |                             |           |                         |    listeners, the value     |
   |                             |           |                         |    ranges from **0** to     |
   |                             |           |                         |    **4000**, and the        |
   |                             |           |                         |    default value is **60**. |
   |                             |           |                         |                             |
   |                             |           |                         | -  For UDP listeners, this  |
   |                             |           |                         |    parameter is not         |
   |                             |           |                         |    available. An error will |
   |                             |           |                         |    be returned if you       |
   |                             |           |                         |    configure this parameter |
   |                             |           |                         |    for UDP listeners.       |
   +-----------------------------+-----------+-------------------------+-----------------------------+
   | client_timeout              | No        | Integer                 | Specifies the timeout       |
   |                             |           |                         | duration for waiting for a  |
   |                             |           |                         | request from a client, in   |
   |                             |           |                         | seconds.                    |
   |                             |           |                         |                             |
   |                             |           |                         | This parameter is available |
   |                             |           |                         | only for HTTP and HTTPS     |
   |                             |           |                         | listeners. The value ranges |
   |                             |           |                         | from **1** to **300**, and  |
   |                             |           |                         | the default value is        |
   |                             |           |                         | **60**.                     |
   |                             |           |                         |                             |
   |                             |           |                         | An error will be returned   |
   |                             |           |                         | if you configure this       |
   |                             |           |                         | parameter for TCP and UDP   |
   |                             |           |                         | listeners.                  |
   |                             |           |                         |                             |
   |                             |           |                         | Minimum: **1**              |
   |                             |           |                         |                             |
   |                             |           |                         | Maximum: **300**            |
   |                             |           |                         |                             |
   |                             |           |                         | Default: **60**             |
   +-----------------------------+-----------+-------------------------+-----------------------------+
   | member_timeout              | No        | Integer                 | Specifies the timeout       |
   |                             |           |                         | duration for waiting for a  |
   |                             |           |                         | request from a backend      |
   |                             |           |                         | server, in seconds.         |
   |                             |           |                         |                             |
   |                             |           |                         | This parameter is available |
   |                             |           |                         | only for HTTP and HTTPS     |
   |                             |           |                         | listeners. The value ranges |
   |                             |           |                         | from **1** to **300**, and  |
   |                             |           |                         | the default value is        |
   |                             |           |                         | **60**.                     |
   |                             |           |                         |                             |
   |                             |           |                         | An error will be returned   |
   |                             |           |                         | if you configure this       |
   |                             |           |                         | parameter for TCP and UDP   |
   |                             |           |                         | listeners.                  |
   +-----------------------------+-----------+-------------------------+-----------------------------+
   | ipgroup                     | No        | :ref:`dlc_igo` object   | Specifies the IP address    |
   |                             |           |                         | group associated with the   |
   |                             |           |                         | listener.                   |
   |                             |           |                         |                             |
   |                             |           |                         | The value can be **null**   |
   |                             |           |                         | or an empty JSON structure, |
   |                             |           |                         | indicating that no IP       |
   |                             |           |                         | address group is associated |
   |                             |           |                         | with the listener.          |
   |                             |           |                         |                             |
   |                             |           |                         | **ipgroup_id** is also      |
   |                             |           |                         | required if you want to     |
   |                             |           |                         | associate an IP address     |
   |                             |           |                         | group with the listener.    |
   |                             |           |                         |                             |
   |                             |           |                         | This parameter is           |
   |                             |           |                         | unsupported. Please do not  |
   |                             |           |                         | use it.                     |
   +-----------------------------+-----------+-------------------------+-----------------------------+
   | t                           | No        | Boolean                 | Specifies whether to pass   |
   | ransparent_client_ip_enable |           |                         | source IP addresses of the  |
   |                             |           |                         | clients to backend servers. |
   |                             |           |                         |                             |
   |                             |           |                         | Shared load balancers: The  |
   |                             |           |                         | value can be **true** or    |
   |                             |           |                         | **false**, and the default  |
   |                             |           |                         | value is **false** for TCP  |
   |                             |           |                         | and UDP listeners. The      |
   |                             |           |                         | value can only be **true**  |
   |                             |           |                         | for HTTP and HTTPS          |
   |                             |           |                         | listeners. If this          |
   |                             |           |                         | parameter is not passed,    |
   |                             |           |                         | the default value is        |
   |                             |           |                         | **true**.                   |
   |                             |           |                         |                             |
   |                             |           |                         | Dedicated load balancers:   |
   |                             |           |                         | The value can only be       |
   |                             |           |                         | **true** for all types of   |
   |                             |           |                         | listeners. If this          |
   |                             |           |                         | parameter is not passed,    |
   |                             |           |                         | the default value is        |
   |                             |           |                         | **true**.                   |
   +-----------------------------+-----------+-------------------------+-----------------------------+
   | enhance_l7policy_enable     | No        | Boolean                 | Specifies whether to enable |
   |                             |           |                         | advanced forwarding. The    |
   |                             |           |                         | value can be **true** or    |
   |                             |           |                         | **false** (default).        |
   |                             |           |                         |                             |
   |                             |           |                         | -  **true** indicates that  |
   |                             |           |                         |    advanced forwarding will |
   |                             |           |                         |    be enabled.              |
   |                             |           |                         |                             |
   |                             |           |                         | -  **false** indicates that |
   |                             |           |                         |    advanced forwarding will |
   |                             |           |                         |    not be enabled.          |
   |                             |           |                         |                             |
   |                             |           |                         | The following parameters    |
   |                             |           |                         | will be available only when |
   |                             |           |                         | advanced forwarding is      |
   |                             |           |                         | enabled:                    |
   |                             |           |                         |                             |
   |                             |           |                         | -  **redirect_url_config**  |
   |                             |           |                         |                             |
   |                             |           |                         | -                           |
   |                             |           |                         |   **fixed_response_config** |
   |                             |           |                         |                             |
   |                             |           |                         | -  **priority**             |
   |                             |           |                         |                             |
   |                             |           |                         | -  **conditions**           |
   |                             |           |                         |                             |
   |                             |           |                         | For details, see the        |
   |                             |           |                         | descriptions in the APIs of |
   |                             |           |                         | forwarding policies and     |
   |                             |           |                         | forwarding rules.           |
   |                             |           |                         |                             |
   |                             |           |                         | This parameter is           |
   |                             |           |                         | unsupported. Please do not  |
   |                             |           |                         | use it.                     |
   +-----------------------------+-----------+-------------------------+-----------------------------+

.. _dlc_ih:
.. table:: **Table 5** ListenerInsertHeaders

   +----------------------+-----------+---------+-----------------------------+
   | Parameter            | Mandatory | Type    | Description                 |
   +======================+===========+=========+=============================+
   | X-Forwarded-ELB-IP   | No        | Boolean | Specifies whether to        |
   |                      |           |         | transparently transmit the  |
   |                      |           |         | load balancer EIP to        |
   |                      |           |         | backend servers. If         |
   |                      |           |         | **X-Forwarded-ELB-IP** is   |
   |                      |           |         | set to **true**, the load   |
   |                      |           |         | balancer EIP will be stored |
   |                      |           |         | in the HTTP header and      |
   |                      |           |         | passed to backend servers.  |
   |                      |           |         |                             |
   |                      |           |         | Default: **false**          |
   +----------------------+-----------+---------+-----------------------------+
   | X-Forwarded-Port     | No        | Boolean | Specifies whether to        |
   |                      |           |         | transparently transmit the  |
   |                      |           |         | listening port of the load  |
   |                      |           |         | balancer to backend         |
   |                      |           |         | servers. If                 |
   |                      |           |         | **X-Forwarded-Port** is set |
   |                      |           |         | to **true**, the listening  |
   |                      |           |         | port of the load balancer   |
   |                      |           |         | will be stored in the HTTP  |
   |                      |           |         | header and passed to        |
   |                      |           |         | backend servers.            |
   |                      |           |         |                             |
   |                      |           |         | Default: **false**          |
   +----------------------+-----------+---------+-----------------------------+
   | X-Forwarded-For-Port | No        | Boolean | Specifies whether to        |
   |                      |           |         | transparently transmit the  |
   |                      |           |         | source port of the client   |
   |                      |           |         | to backend servers. If      |
   |                      |           |         | **X-Forwarded-For-Port** is |
   |                      |           |         | set to **true**, the source |
   |                      |           |         | port of the client will be  |
   |                      |           |         | stored in the HTTP header   |
   |                      |           |         | and passed to backend       |
   |                      |           |         | servers.                    |
   |                      |           |         |                             |
   |                      |           |         | Default: **false**          |
   +----------------------+-----------+---------+-----------------------------+
   | X-Forwarded-Host     | Yes       | Boolean | Specifies whether to        |
   |                      |           |         | rewrite the                 |
   |                      |           |         | **X-Forwarded-Host**        |
   |                      |           |         | header. If                  |
   |                      |           |         | **X-Forwarded-Host** is set |
   |                      |           |         | to **true**,                |
   |                      |           |         | **X-Forwarded-Host** in the |
   |                      |           |         | request header from the     |
   |                      |           |         | clients can be set to       |
   |                      |           |         | **Host** in the request     |
   |                      |           |         | header sent from the load   |
   |                      |           |         | balancer to backend         |
   |                      |           |         | servers.                    |
   |                      |           |         |                             |
   |                      |           |         | Default: **true**           |
   +----------------------+-----------+---------+-----------------------------+

.. _dlc_tag:
.. table:: **Table 6** Tag

   ========= ========= ====== ========================
   Parameter Mandatory Type   Description
   ========= ========= ====== ========================
   key       No        String Specifies the tag key.
   value     No        String Specifies the tag value.
   ========= ========= ====== ========================

.. _dlc_igo:
.. table:: **Table 7** CreateListenerIpGroupOption

   +----------------+-----------+---------+-----------------------------+
   | Parameter      | Mandatory | Type    | Description                 |
   +================+===========+=========+=============================+
   | ipgroup_id     | Yes       | String  | Specifies the ID of the IP  |
   |                |           |         | address group associated    |
   |                |           |         | with the listener.          |
   |                |           |         |                             |
   |                |           |         | -  If **ip_list** is set to |
   |                |           |         |    **[]** and **type** to   |
   |                |           |         |    **whitelist**, no IP     |
   |                |           |         |    addresses are allowed to |
   |                |           |         |    access the listener.     |
   |                |           |         |                             |
   |                |           |         | -  If **ip_list** is set to |
   |                |           |         |    **[]** and **type** to   |
   |                |           |         |    **blacklist**, any IP    |
   |                |           |         |    address is allowed to    |
   |                |           |         |    access the listener.     |
   |                |           |         |                             |
   |                |           |         | -  The specified IP address |
   |                |           |         |    group must exist and     |
   |                |           |         |    this parameter cannot be |
   |                |           |         |    set to **null**.         |
   |                |           |         |                             |
   |                |           |         | IP address groups are not   |
   |                |           |         | supported for now.          |
   +----------------+-----------+---------+-----------------------------+
   | enable_ipgroup | No        | Boolean | Specifies whether to enable |
   |                |           |         | access control.             |
   |                |           |         |                             |
   |                |           |         | -  **true** (default):      |
   |                |           |         |    Access control will be   |
   |                |           |         |    enabled.                 |
   |                |           |         |                             |
   |                |           |         | -  **false**: Access        |
   |                |           |         |    control will be          |
   |                |           |         |    disabled.                |
   |                |           |         |                             |
   |                |           |         | A listener with access      |
   |                |           |         | control enabled can be      |
   |                |           |         | directly deleted.           |
   +----------------+-----------+---------+-----------------------------+
   | type           | No        | String  | Specifies how access to the |
   |                |           |         | listener is controlled.     |
   |                |           |         |                             |
   |                |           |         | -  **white** (default): A   |
   |                |           |         |    whitelist will be        |
   |                |           |         |    configured. Only IP      |
   |                |           |         |    addresses in the         |
   |                |           |         |    whitelist can access the |
   |                |           |         |    listener.                |
   |                |           |         |                             |
   |                |           |         | -  **black**: A blacklist   |
   |                |           |         |    will be configured. IP   |
   |                |           |         |    addresses in the         |
   |                |           |         |    blacklist are not        |
   |                |           |         |    allowed to access the    |
   |                |           |         |    listener.                |
   +----------------+-----------+---------+-----------------------------+

Response Parameters
^^^^^^^^^^^^^^^^^^^

**Status code: 201**

.. table:: **Table 8** Response body parameters

   +------------+---------------------+----------------------------------------+
   | Parameter  | Type                | Description                            |
   +============+=====================+========================================+
   | request_id | String              | Specifies the request ID. The value is |
   |            |                     | automatically generated.               |
   +------------+---------------------+----------------------------------------+
   | listener   | :ref:`dlc_l` object | Specifies the listener.                |
   +------------+---------------------+----------------------------------------+

.. _dlc_l:
.. table:: **Table 9** Listener

   +------------------------------+----------------------------------+---------------------------------------+
   | Parameter                    | Type                             | Description                           |
   +==============================+==================================+=======================================+
   | admin_state_up               | Boolean                          | Specifies the administrative status   |
   |                              |                                  | of the listener. And the value can    |
   |                              |                                  | only be **true**.                     |
   |                              |                                  |                                       |
   |                              |                                  | This parameter is unsupported. Please |
   |                              |                                  | do not use it.                        |
   |                              |                                  |                                       |
   |                              |                                  | Default: **true**                     |
   +------------------------------+----------------------------------+---------------------------------------+
   | client_ca_tls_container_ref  | String                           | Specifies the ID of the CA            |
   |                              |                                  | certificate used by the listener.     |
   +------------------------------+----------------------------------+---------------------------------------+
   | connection_limit             | Integer                          | Specifies the maximum number of       |
   |                              |                                  | connections. The default value is     |
   |                              |                                  | **-1**.                               |
   |                              |                                  |                                       |
   |                              |                                  | This parameter is unsupported. Please |
   |                              |                                  | do not use it.                        |
   +------------------------------+----------------------------------+---------------------------------------+
   | created_at                   | String                           | Specifies the time when the listener  |
   |                              |                                  | was created.                          |
   +------------------------------+----------------------------------+---------------------------------------+
   | default_pool_id              | String                           | Specifies the ID of the default       |
   |                              |                                  | backend server group. If there is no  |
   |                              |                                  | matched forwarding policy, requests   |
   |                              |                                  | are forwarded to the default backend  |
   |                              |                                  | server.                               |
   +------------------------------+----------------------------------+---------------------------------------+
   | default_tls_container_ref    | String                           | Specifies the ID of the server        |
   |                              |                                  | certificate used by the listener.     |
   +------------------------------+----------------------------------+---------------------------------------+
   | description                  | String                           | Provides supplementary information    |
   |                              |                                  | about the listener.                   |
   +------------------------------+----------------------------------+---------------------------------------+
   | http2_enable                 | Boolean                          | Specifies whether to use HTTP/2. This |
   |                              |                                  | parameter is available only for HTTPS |
   |                              |                                  | listeners. If you configure this      |
   |                              |                                  | parameter for other types of          |
   |                              |                                  | listeners, it will not take effect.   |
   |                              |                                  |                                       |
   |                              |                                  | Enable HTTP/2 if you want the clients |
   |                              |                                  | to use HTTP/2 to communicate with the |
   |                              |                                  | load balancer. However, connections   |
   |                              |                                  | between the load balancer and backend |
   |                              |                                  | servers use HTTP/1.x by default.      |
   |                              |                                  |                                       |
   |                              |                                  | Default: **true**                     |
   +------------------------------+----------------------------------+---------------------------------------+
   | id                           | String                           | Specifies the listener ID.            |
   +------------------------------+----------------------------------+---------------------------------------+
   | insert_headers               | :ref:`dlc_rih` object            | Specifies the HTTP header fields.     |
   +------------------------------+----------------------------------+---------------------------------------+
   | loadbalancers                | Array of :ref:`dlc_lbr` objects  | Specifies the ID of the load balancer |
   |                              |                                  | that the listener is added to.        |
   +------------------------------+----------------------------------+---------------------------------------+
   | name                         | String                           | Specifies the listener name.          |
   +------------------------------+----------------------------------+---------------------------------------+
   | project_id                   | String                           | Specifies the ID of the project where |
   |                              |                                  | the listener is used.                 |
   +------------------------------+----------------------------------+---------------------------------------+
   | protocol                     | String                           | Specifies the protocol used by the    |
   |                              |                                  | listener.                             |
   +------------------------------+----------------------------------+---------------------------------------+
   | protocol_port                | Integer                          | Specifies the port used by the        |
   |                              |                                  | listener.                             |
   |                              |                                  |                                       |
   |                              |                                  | Minimum: **1**                        |
   |                              |                                  |                                       |
   |                              |                                  | Maximum: **65535**                    |
   +------------------------------+----------------------------------+---------------------------------------+
   | sni_container_refs           | Array of strings                 | Lists the IDs of SNI certificates     |
   |                              |                                  | (server certificates with domain      |
   |                              |                                  | names) used by the listener.          |
   |                              |                                  |                                       |
   |                              |                                  | Each SNI certificate can have up to   |
   |                              |                                  | 30 domain names, and each domain name |
   |                              |                                  | in the SNI certificate must be        |
   |                              |                                  | unique.                               |
   |                              |                                  |                                       |
   |                              |                                  | This parameter will be ignored and an |
   |                              |                                  | empty array will be returned if the   |
   |                              |                                  | listener's protocol is not HTTPS.     |
   +------------------------------+----------------------------------+---------------------------------------+
   | tags                         | Array of :ref:`dlc_rtag` objects | Lists the tags.                       |
   +------------------------------+----------------------------------+---------------------------------------+
   | updated_at                   | String                           | Specifies the time when the listener  |
   |                              |                                  | was updated.                          |
   +------------------------------+----------------------------------+---------------------------------------+
   | tls_ciphers_policy           | String                           | Specifies the security policy used by |
   |                              |                                  | the listener. This parameter is       |
   |                              |                                  | available only for HTTPS listeners.   |
   |                              |                                  |                                       |
   |                              |                                  | The value can be **tls-1-0**,         |
   |                              |                                  | **tls-1-1**, **tls-1-2**, or          |
   |                              |                                  | **tls-1-2-strict**, and the default   |
   |                              |                                  | value is **tls-1-0**.                 |
   +------------------------------+----------------------------------+---------------------------------------+
   | enable_member_retry          | Boolean                          | Specifies whether to enable health    |
   |                              |                                  | check retries for backend servers.    |
   |                              |                                  | This parameter is available only for  |
   |                              |                                  | HTTP and HTTPS listeners.             |
   +------------------------------+----------------------------------+---------------------------------------+
   | keepalive_timeout            | Integer                          | Specifies the idle timeout duration,  |
   |                              |                                  | in seconds.                           |
   |                              |                                  |                                       |
   |                              |                                  | -  For TCP listeners, the value       |
   |                              |                                  |    ranges from **10** to **4000**,    |
   |                              |                                  |    and the default value is **300**.  |
   |                              |                                  |                                       |
   |                              |                                  | -  For HTTP and HTTPS listeners, the  |
   |                              |                                  |    value ranges from **0** to         |
   |                              |                                  |    **4000**, and the default value is |
   |                              |                                  |    **60**.                            |
   |                              |                                  |                                       |
   |                              |                                  | -  For UDP listeners, this parameter  |
   |                              |                                  |    does not take effect.              |
   +------------------------------+----------------------------------+---------------------------------------+
   | client_timeout               | Integer                          | Specifies the timeout duration for    |
   |                              |                                  | waiting for a request from a client,  |
   |                              |                                  | in seconds.                           |
   |                              |                                  |                                       |
   |                              |                                  | This parameter is available only for  |
   |                              |                                  | HTTP and HTTPS listeners. The value   |
   |                              |                                  | ranges from **1** to **300**, and the |
   |                              |                                  | default value is **60**.              |
   +------------------------------+----------------------------------+---------------------------------------+
   | member_timeout               | Integer                          | Specifies the timeout duration for    |
   |                              |                                  | waiting for a request from a backend  |
   |                              |                                  | server, in seconds.                   |
   |                              |                                  |                                       |
   |                              |                                  | This parameter is available only for  |
   |                              |                                  | HTTP and HTTPS listeners. The value   |
   |                              |                                  | ranges from **1** to **300**, and the |
   |                              |                                  | default value is **60**.              |
   +------------------------------+----------------------------------+---------------------------------------+
   | ipgroup                      | :ref`dlc_rig` object             | Specifies the IP address group        |
   |                              |                                  | associated with the listener.         |
   |                              |                                  |                                       |
   |                              |                                  | This parameter is unsupported. Please |
   |                              |                                  | do not use it.                        |
   +------------------------------+----------------------------------+---------------------------------------+
   | transparent_client_ip_enable | Boolean                          | Specifies whether to pass source IP   |
   |                              |                                  | addresses of the clients to backend   |
   |                              |                                  | servers.                              |
   |                              |                                  |                                       |
   |                              |                                  | Shared load balancers: The value can  |
   |                              |                                  | be **true** or **false**, and the     |
   |                              |                                  | default value is **false** for TCP    |
   |                              |                                  | and UDP listeners. The value can only |
   |                              |                                  | be **true** for HTTP and HTTPS        |
   |                              |                                  | listeners. If this parameter is not   |
   |                              |                                  | passed, the default value is          |
   |                              |                                  | **true**.                             |
   |                              |                                  |                                       |
   |                              |                                  | Dedicated load balancers: The value   |
   |                              |                                  | can only be **true** for all types of |
   |                              |                                  | listeners. If this parameter is not   |
   |                              |                                  | passed, the default value is          |
   |                              |                                  | **true**.                             |
   +------------------------------+----------------------------------+---------------------------------------+
   | enhance_l7policy_enable      | Boolean                          | Specifies whether to enable advanced  |
   |                              |                                  | forwarding. The value can be **true** |
   |                              |                                  | or **false** (default).               |
   |                              |                                  |                                       |
   |                              |                                  | -  **true** indicates that advanced   |
   |                              |                                  |    forwarding will be enabled.        |
   |                              |                                  |                                       |
   |                              |                                  | -  **false** indicates that advanced  |
   |                              |                                  |    forwarding will not be enabled.    |
   |                              |                                  |                                       |
   |                              |                                  | The following parameters will be      |
   |                              |                                  | available only when advanced          |
   |                              |                                  | forwarding is enabled:                |
   |                              |                                  |                                       |
   |                              |                                  | -  **redirect_url_config**            |
   |                              |                                  |                                       |
   |                              |                                  | -  **fixed_response_config**          |
   |                              |                                  |                                       |
   |                              |                                  | -  **priority**                       |
   |                              |                                  |                                       |
   |                              |                                  | -  **conditions**                     |
   |                              |                                  |                                       |
   |                              |                                  | For details, see the descriptions in  |
   |                              |                                  | the APIs of forwarding policies and   |
   |                              |                                  | forwarding rules.                     |
   |                              |                                  |                                       |
   |                              |                                  | This parameter is unsupported. Please |
   |                              |                                  | do not use it.                        |
   +------------------------------+----------------------------------+---------------------------------------+

.. _dlc_rih:
.. table:: **Table 10** ListenerInsertHeaders

   +----------------------+---------+---------------------------------------+
   | Parameter            | Type    | Description                           |
   +======================+=========+=======================================+
   | X-Forwarded-ELB-IP   | Boolean | Specifies whether to transparently    |
   |                      |         | transmit the load balancer EIP to     |
   |                      |         | backend servers. If                   |
   |                      |         | **X-Forwarded-ELB-IP** is set to      |
   |                      |         | **true**, the load balancer EIP will  |
   |                      |         | be stored in the HTTP header and      |
   |                      |         | passed to backend servers.            |
   |                      |         |                                       |
   |                      |         | Default: **false**                    |
   +----------------------+---------+---------------------------------------+
   | X-Forwarded-Port     | Boolean | Specifies whether to transparently    |
   |                      |         | transmit the listening port of the    |
   |                      |         | load balancer to backend servers. If  |
   |                      |         | **X-Forwarded-Port** is set to        |
   |                      |         | **true**, the listening port of the   |
   |                      |         | load balancer will be stored in the   |
   |                      |         | HTTP header and passed to backend     |
   |                      |         | servers.                              |
   |                      |         |                                       |
   |                      |         | Default: **false**                    |
   +----------------------+---------+---------------------------------------+
   | X-Forwarded-For-Port | Boolean | Specifies whether to transparently    |
   |                      |         | transmit the source port of the       |
   |                      |         | client to backend servers. If         |
   |                      |         | **X-Forwarded-For-Port** is set to    |
   |                      |         | **true**, the source port of the      |
   |                      |         | client will be stored in the HTTP     |
   |                      |         | header and passed to backend servers. |
   |                      |         |                                       |
   |                      |         | Default: **false**                    |
   +----------------------+---------+---------------------------------------+
   | X-Forwarded-Host     | Boolean | Specifies whether to rewrite the      |
   |                      |         | **X-Forwarded-Host** header. If       |
   |                      |         | **X-Forwarded-Host** is set to        |
   |                      |         | **true**, **X-Forwarded-Host** in the |
   |                      |         | request header from the clients can   |
   |                      |         | be set to **Host** in the request     |
   |                      |         | header sent from the load balancer to |
   |                      |         | backend servers.                      |
   |                      |         |                                       |
   |                      |         | Default: **true**                     |
   +----------------------+---------+---------------------------------------+

.. _dlc_lbr:
.. table:: **Table 11** LoadBalancerRef

   ========= ====== ===============================
   Parameter Type   Description
   ========= ====== ===============================
   id        String Specifies the load balancer ID.
   ========= ====== ===============================

.. _dlc_rtag:
.. table:: **Table 12** Tag

   ========= ====== ========================
   Parameter Type   Description
   ========= ====== ========================
   key       String Specifies the tag key.
   value     String Specifies the tag value.
   ========= ====== ========================

.. _dlc:rig:
.. table:: **Table 13** ListenerIpGroup

   +----------------+---------+---------------------------------------+
   | Parameter      | Type    | Description                           |
   +================+=========+=======================================+
   | ipgroup_id     | String  | Specifies the ID of the IP address    |
   |                |         | group associated with the listener.   |
   |                |         |                                       |
   |                |         | -  If **ip_list** is set to **[]**    |
   |                |         |    and **type** to **whitelist**, no  |
   |                |         |    IP addresses are allowed to access |
   |                |         |    the listener.                      |
   |                |         |                                       |
   |                |         | -  If **ip_list** is set to **[]**    |
   |                |         |    and **type** to **blacklist**, any |
   |                |         |    IP address is allowed to access    |
   |                |         |    the listener.                      |
   |                |         |                                       |
   |                |         | -  The specified IP address group     |
   |                |         |    must exist and this parameter      |
   |                |         |    cannot be set to **null**.         |
   +----------------+---------+---------------------------------------+
   | enable_ipgroup | Boolean | Specifies whether to enable access    |
   |                |         | control.                              |
   |                |         |                                       |
   |                |         | -  **true**: Access control is        |
   |                |         |    enabled.                           |
   |                |         |                                       |
   |                |         | -  **false**: Access control is       |
   |                |         |    disabled.                          |
   |                |         |                                       |
   |                |         | A listener with access control        |
   |                |         | enabled can be directly deleted.      |
   +----------------+---------+---------------------------------------+
   | type           | String  | Specifies how access to the listener  |
   |                |         | is controlled.                        |
   |                |         |                                       |
   |                |         | -  **white**: A whitelist is          |
   |                |         |    configured. Only IP addresses in   |
   |                |         |    the whitelist can access the       |
   |                |         |    listener.                          |
   |                |         |                                       |
   |                |         | -  **black**: A blacklist is          |
   |                |         |    configured. IP addresses in the    |
   |                |         |    blacklist are not allowed to       |
   |                |         |    access the listener.               |
   +----------------+---------+---------------------------------------+

Example Requests
^^^^^^^^^^^^^^^^

-  Example 1: Adding an HTTPS listener

   .. code::

      POST

      https://{elb_endpoint}/v3/99a3fff0d03c428eac3678da6a7d0f24/elb/listeners

      {
        "listener" : {
          "protocol_port" : 90,
          "protocol" : "HTTPS",
          "loadbalancer_id" : "ac82ca77-8be3-4d65-9c4d-155771b463df",
          "name" : "My listener",
          "admin_state_up" : true,
          "default_tls_container_ref" : "4e7761d7c7d141c389479f2641c8bff8"
        }
      }

-  Example 2: Adding a TCP listener

   .. code::

      POST

      https://{elb_endpoint}/v3/99a3fff0d03c428eac3678da6a7d0f24/elb/listeners

      {
        "listener" : {
          "protocol_port" : 80,
          "protocol" : "TCP",
          "loadbalancer_id" : "098b2f68-af1c-41a9-8efd-69958722af62",
          "name" : "My listener",
          "admin_state_up" : true,
          "insert_headers" : {
            "X-Forwarded-ELB-IP" : true
          }
        }
      }

Example Responses
^^^^^^^^^^^^^^^^^

**Status code: 201**

Successful request.

.. code::

   {
     "listener" : {
       "id" : "683cf917-3e51-4c41-830c-bc3a57e090f0",
       "name" : "My listener",
       "protocol_port" : 90,
       "protocol" : "HTTPS",
       "description" : "",
       "default_tls_container_ref" : "4e7761d7c7d141c389479f2641c8bff8",
       "admin_state_up" : true,
       "loadbalancers" : [ {
         "id" : "ac82ca77-8be3-4d65-9c4d-155771b463df"
       } ],
       "project_id" : "060576782980d5762f9ec014dd2f1148",
       "sni_container_refs" : [ ],
       "connection_limit" : -1,
       "tls_ciphers_policy" : "tls-1-0",
       "tags" : [ ],
       "created_at" : "2021-04-02T07:48:38Z",
       "updated_at" : "2021-04-02T07:48:38Z",
       "http2_enable" : false,
       "insert_headers" : {
         "X-Forwarded-ELB-IP" : false,
         "X-Forwarded-Host" : true,
         "X-Forwarded-For-Port" : false,
         "X-Forwarded-Port" : false
       },
       "member_timeout" : 60,
       "client_timeout" : 60,
       "keepalive_timeout" : 60,
       "enable_member_retry" : true,
       "transparent_client_ip_enable" : true,
       "enhance_l7policy_enable" : false
     },
     "request_id" : "830de7c7c38232d925db168bfb3cb0e8"
   }

Status Codes
^^^^^^^^^^^^

=========== ===================
Status Code Description
=========== ===================
201         Successful request.
=========== ===================

Error Codes
^^^^^^^^^^^

See :ref:`dsc`.

Querying Listeners
==================

Function
^^^^^^^^

This API is used to query listeners.

Constraints
^^^^^^^^^^^

Parameters **marker**, **limit**, and **page_reverse** are used for pagination
query.

Parameters **marker** and **page_reverse** take effect only when they are used
together with parameter **limit**.

URI
^^^

GET /v3/{project_id}/elb/listeners

.. table:: **Table 1** Path parameters

   ========== ========= ====== =========================
   Parameter  Mandatory Type   Description
   ========== ========= ====== =========================
   project_id Yes       String Specifies the project ID.
   ========== ========= ====== =========================

.. table:: **Table 2** Query parameters

   +-----------------------------+-----------+---------+-----------------------------+
   | Parameter                   | Mandatory | Type    | Description                 |
   +=============================+===========+=========+=============================+
   | limit                       | No        | Integer | Specifies the number of     |
   |                             |           |         | records on each page.       |
   |                             |           |         |                             |
   |                             |           |         | Minimum: **0**              |
   |                             |           |         |                             |
   |                             |           |         | Maximum: **2000**           |
   +-----------------------------+-----------+---------+-----------------------------+
   | marker                      | No        | String  | Specifies the ID of the     |
   |                             |           |         | last record on the previous |
   |                             |           |         | page.                       |
   |                             |           |         |                             |
   |                             |           |         | Note:                       |
   |                             |           |         |                             |
   |                             |           |         | -  This parameter must be   |
   |                             |           |         |    used together with       |
   |                             |           |         |    **limit**.               |
   |                             |           |         |                             |
   |                             |           |         | -  If this parameter is not |
   |                             |           |         |    specified, the first     |
   |                             |           |         |    page will be queried.    |
   |                             |           |         |                             |
   |                             |           |         | -  This parameter cannot be |
   |                             |           |         |    left blank or set to an  |
   |                             |           |         |    invalid ID.              |
   +-----------------------------+-----------+---------+-----------------------------+
   | page_reverse                | No        | Boolean | Specifies the page          |
   |                             |           |         | direction.                  |
   |                             |           |         |                             |
   |                             |           |         | The value can be **true**   |
   |                             |           |         | or **false**, and the       |
   |                             |           |         | default value is **false**. |
   |                             |           |         |                             |
   |                             |           |         | The last page in the list   |
   |                             |           |         | requested with              |
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
   | protocol_port               | No        | Array   | Specifies the port used by  |
   |                             |           |         | the listener.               |
   |                             |           |         |                             |
   |                             |           |         | Multiple ports can be       |
   |                             |           |         | queried in the format of    |
   |                             |           |         | *protocol_p                 |
   |                             |           |         | ort=xxx&protocol_port=xxx*. |
   +-----------------------------+-----------+---------+-----------------------------+
   | protocol                    | No        | Array   | Specifies the protocol used |
   |                             |           |         | by the listener. The        |
   |                             |           |         | protocol can be UDP, TCP,   |
   |                             |           |         | HTTP, or HTTPS.             |
   |                             |           |         |                             |
   |                             |           |         | Multiple protocols can be   |
   |                             |           |         | queried in the format of    |
   |                             |           |         | *                           |
   |                             |           |         | protocol=xxx&protocol=xxx*. |
   +-----------------------------+-----------+---------+-----------------------------+
   | description                 | No        | Array   | Provides supplementary      |
   |                             |           |         | information about the       |
   |                             |           |         | listener.                   |
   |                             |           |         |                             |
   |                             |           |         | Multiple descriptions can   |
   |                             |           |         | be queried in the format of |
   |                             |           |         | *descri                     |
   |                             |           |         | ption=xxx&description=xxx*. |
   +-----------------------------+-----------+---------+-----------------------------+
   | default_tls_container_ref   | No        | Array   | Specifies the ID of the     |
   |                             |           |         | server certificate used by  |
   |                             |           |         | the listener.               |
   |                             |           |         |                             |
   |                             |           |         | Multiple IDs can be queried |
   |                             |           |         | in the format of            |
   |                             |           |         | *default                    |
   |                             |           |         | _tls_container_ref=xxx&defa |
   |                             |           |         | ult_tls_container_ref=xxx*. |
   +-----------------------------+-----------+---------+-----------------------------+
   | client_ca_tls_container_ref | No        | Array   | Specifies the ID of the CA  |
   |                             |           |         | certificate used by the     |
   |                             |           |         | listener.                   |
   |                             |           |         |                             |
   |                             |           |         | Multiple IDs can be queried |
   |                             |           |         | in the format of            |
   |                             |           |         | *client_ca_t                |
   |                             |           |         | ls_container_ref=xxx&client |
   |                             |           |         | _ca_tls_container_ref=xxx*. |
   +-----------------------------+-----------+---------+-----------------------------+
   | admin_state_up              | No        | Boolean | Specifies the               |
   |                             |           |         | administrative status of    |
   |                             |           |         | the listener. The value can |
   |                             |           |         | only be **true**.           |
   |                             |           |         |                             |
   |                             |           |         | This parameter is           |
   |                             |           |         | unsupported. Please do not  |
   |                             |           |         | use it.                     |
   +-----------------------------+-----------+---------+-----------------------------+
   | connection_limit            | No        | Array   | Specifies the maximum       |
   |                             |           |         | number of connections that  |
   |                             |           |         | the load balancer can       |
   |                             |           |         | handle. The default value   |
   |                             |           |         | is **-1**.                  |
   |                             |           |         |                             |
   |                             |           |         | Multiple values can be      |
   |                             |           |         | queried in the format of    |
   |                             |           |         | *connection_limit           |
   |                             |           |         | =xxx&connection_limit=xxx*. |
   |                             |           |         |                             |
   |                             |           |         | This parameter is           |
   |                             |           |         | unsupported. Please do not  |
   |                             |           |         | use it.                     |
   +-----------------------------+-----------+---------+-----------------------------+
   | default_pool_id             | No        | Array   | Specifies the ID of the     |
   |                             |           |         | default backend server      |
   |                             |           |         | group. If there is no       |
   |                             |           |         | matched forwarding policy,  |
   |                             |           |         | requests will be routed to  |
   |                             |           |         | the default backend server. |
   |                             |           |         |                             |
   |                             |           |         | Multiple IDs can be queried |
   |                             |           |         | in the format of            |
   |                             |           |         | *default_pool_i             |
   |                             |           |         | d=xxx&default_pool_id=xxx*. |
   +-----------------------------+-----------+---------+-----------------------------+
   | id                          | No        | Array   | Specifies the listener ID.  |
   |                             |           |         |                             |
   |                             |           |         | Multiple IDs can be queried |
   |                             |           |         | in the format of            |
   |                             |           |         | *id=xxx&id=xxx*.            |
   +-----------------------------+-----------+---------+-----------------------------+
   | name                        | No        | Array   | Specifies the name of the   |
   |                             |           |         | listener added to the load  |
   |                             |           |         | balancer.                   |
   |                             |           |         |                             |
   |                             |           |         | Multiple names can be       |
   |                             |           |         | queried in the format of    |
   |                             |           |         | *name=xxx&name=xxx*.        |
   +-----------------------------+-----------+---------+-----------------------------+
   | http2_enable                | No        | Boolean | Specifies whether to use    |
   |                             |           |         | HTTP/2. This parameter is   |
   |                             |           |         | available only for HTTPS    |
   |                             |           |         | listeners. If you configure |
   |                             |           |         | this parameter for other    |
   |                             |           |         | types of listeners, it will |
   |                             |           |         | not take effect.            |
   |                             |           |         |                             |
   |                             |           |         | Enable HTTP/2 if you want   |
   |                             |           |         | the clients to use HTTP/2   |
   |                             |           |         | to communicate with the     |
   |                             |           |         | load balancer. However,     |
   |                             |           |         | connections between the     |
   |                             |           |         | load balancer and backend   |
   |                             |           |         | servers use HTTP/1.x by     |
   |                             |           |         | default.                    |
   +-----------------------------+-----------+---------+-----------------------------+
   | loadbalancer_id             | No        | Array   | Specifies the ID of the     |
   |                             |           |         | load balancer that the      |
   |                             |           |         | listener is added to.       |
   |                             |           |         |                             |
   |                             |           |         | Multiple IDs can be queried |
   |                             |           |         | in the format of            |
   |                             |           |         | *loadbalancer_i             |
   |                             |           |         | d=xxx&loadbalancer_id=xxx*. |
   +-----------------------------+-----------+---------+-----------------------------+
   | tls_ciphers_policy          | No        | Array   | Specifies the security      |
   |                             |           |         | policy used by the          |
   |                             |           |         | listener. This parameter is |
   |                             |           |         | available only for HTTPS    |
   |                             |           |         | listeners.                  |
   |                             |           |         |                             |
   |                             |           |         | The value can be            |
   |                             |           |         | **tls-1-0**, **tls-1-1**,   |
   |                             |           |         | **tls-1-2**, or             |
   |                             |           |         | **tls-1-2-strict**, and the |
   |                             |           |         | default value is            |
   |                             |           |         | **tls-1-0**.                |
   |                             |           |         |                             |
   |                             |           |         | Multiple security policies  |
   |                             |           |         | can be queried in the       |
   |                             |           |         | format of                   |
   |                             |           |         | *tls_ciphers_policy=x       |
   |                             |           |         | xx&tls_ciphers_policy=xxx*. |
   +-----------------------------+-----------+---------+-----------------------------+
   | member_address              | No        | Array   | Specifies the private IP    |
   |                             |           |         | address bound to the        |
   |                             |           |         | backend server. This        |
   |                             |           |         | parameter is used only as a |
   |                             |           |         | query condition and is not  |
   |                             |           |         | included in the response.   |
   |                             |           |         |                             |
   |                             |           |         | Multiple IP addresses can   |
   |                             |           |         | be queried in the format of |
   |                             |           |         | *member_addre               |
   |                             |           |         | ss=xxx&member_address=xxx*. |
   +-----------------------------+-----------+---------+-----------------------------+
   | member_device_id            | No        | Array   | Specifies the ID of the     |
   |                             |           |         | cloud server that serves as |
   |                             |           |         | a backend server. This      |
   |                             |           |         | parameter is used only as a |
   |                             |           |         | query condition and is not  |
   |                             |           |         | included in the response.   |
   |                             |           |         |                             |
   |                             |           |         | Multiple IDs can be queried |
   |                             |           |         | in the format of            |
   |                             |           |         | *member_device_id           |
   |                             |           |         | =xxx&member_device_id=xxx*. |
   +-----------------------------+-----------+---------+-----------------------------+
   | enterprise_project_id       | No        | Array   | Specifies the enterprise    |
   |                             |           |         | project ID.                 |
   |                             |           |         |                             |
   |                             |           |         | -  If this parameter is not |
   |                             |           |         |    passed, resources in the |
   |                             |           |         |    default enterprise       |
   |                             |           |         |    project are queried, and |
   |                             |           |         |    authentication is        |
   |                             |           |         |    performed based on the   |
   |                             |           |         |    default enterprise       |
   |                             |           |         |    project.                 |
   |                             |           |         |                             |
   |                             |           |         | -  If this parameter is     |
   |                             |           |         |    passed, its value can be |
   |                             |           |         |    the ID of an existing    |
   |                             |           |         |    enterprise project or    |
   |                             |           |         |    **all_granted_eps**.     |
   |                             |           |         |                             |
   |                             |           |         | If the value is a specific  |
   |                             |           |         | ID, resources in the        |
   |                             |           |         | specific enterprise project |
   |                             |           |         | are required. If the value  |
   |                             |           |         | is **all_granted_eps**,     |
   |                             |           |         | resources in all enterprise |
   |                             |           |         | projects are queried.       |
   |                             |           |         |                             |
   |                             |           |         | Multiple IDs can be queried |
   |                             |           |         | in the format of            |
   |                             |           |         | *enterprise_project_id=xxx& |
   |                             |           |         | enterprise_project_id=xxx*. |
   |                             |           |         |                             |
   |                             |           |         | This parameter is           |
   |                             |           |         | unsupported. Please do not  |
   |                             |           |         | use it.                     |
   +-----------------------------+-----------+---------+-----------------------------+
   | enable_member_retry         | No        | Boolean | Specifies whether to enable |
   |                             |           |         | health check retries for    |
   |                             |           |         | backend servers.            |
   +-----------------------------+-----------+---------+-----------------------------+
   | member_timeout              | No        | Array   | Specifies the timeout       |
   |                             |           |         | duration for waiting for a  |
   |                             |           |         | request from a backend      |
   |                             |           |         | server, in seconds.         |
   |                             |           |         |                             |
   |                             |           |         | This parameter is available |
   |                             |           |         | only for HTTP and HTTPS     |
   |                             |           |         | listeners. The value ranges |
   |                             |           |         | from **1** to **300**.      |
   |                             |           |         |                             |
   |                             |           |         | Multiple durations can be   |
   |                             |           |         | queried in the format of    |
   |                             |           |         | *member_timeo               |
   |                             |           |         | ut=xxx&member_timeout=xxx*. |
   +-----------------------------+-----------+---------+-----------------------------+
   | client_timeout              | No        | Array   | Specifies the timeout       |
   |                             |           |         | duration for waiting for a  |
   |                             |           |         | request from a client, in   |
   |                             |           |         | seconds.                    |
   |                             |           |         |                             |
   |                             |           |         | This parameter is available |
   |                             |           |         | only for HTTP and HTTPS     |
   |                             |           |         | listeners. The value ranges |
   |                             |           |         | from **1** to **300**.      |
   |                             |           |         |                             |
   |                             |           |         | Multiple durations can be   |
   |                             |           |         | queried in the format of    |
   |                             |           |         | *client_timeo               |
   |                             |           |         | ut=xxx&client_timeout=xxx*. |
   +-----------------------------+-----------+---------+-----------------------------+
   | keepalive_timeout           | No        | Array   | Specifies the idle timeout  |
   |                             |           |         | duration, in seconds.       |
   |                             |           |         |                             |
   |                             |           |         | -  For TCP listeners, the   |
   |                             |           |         |    value ranges from **10** |
   |                             |           |         |    to **4000**, and the     |
   |                             |           |         |    default value is         |
   |                             |           |         |    **300**.                 |
   |                             |           |         |                             |
   |                             |           |         | -  For HTTP and HTTPS       |
   |                             |           |         |    listeners, the value     |
   |                             |           |         |    ranges from **0** to     |
   |                             |           |         |    **4000**, and the        |
   |                             |           |         |    default value is **60**. |
   |                             |           |         |                             |
   |                             |           |         | -  For UDP listeners, this  |
   |                             |           |         |    parameter does not take  |
   |                             |           |         |    effect.                  |
   |                             |           |         |                             |
   |                             |           |         | Multiple durations can be   |
   |                             |           |         | queried in the format of    |
   |                             |           |         | *keepalive_timeout=         |
   |                             |           |         | xxx&keepalive_timeout=xxx*. |
   +-----------------------------+-----------+---------+-----------------------------+
   | t                           | No        | Boolean | Specifies whether to pass   |
   | ransparent_client_ip_enable |           |         | source IP addresses of the  |
   |                             |           |         | clients to backend servers. |
   |                             |           |         |                             |
   |                             |           |         | Shared load balancers: The  |
   |                             |           |         | value can be **true** or    |
   |                             |           |         | **false**, and the default  |
   |                             |           |         | value is **false** for TCP  |
   |                             |           |         | and UDP listeners. The      |
   |                             |           |         | value can only be **true**  |
   |                             |           |         | for HTTP and HTTPS          |
   |                             |           |         | listeners. If this          |
   |                             |           |         | parameter is not passed,    |
   |                             |           |         | the default value is        |
   |                             |           |         | **true**.                   |
   |                             |           |         |                             |
   |                             |           |         | Dedicated load balancers:   |
   |                             |           |         | The value can only be       |
   |                             |           |         | **true** for all types of   |
   |                             |           |         | listeners. If this          |
   |                             |           |         | parameter is not passed,    |
   |                             |           |         | the default value is        |
   |                             |           |         | **true**.                   |
   +-----------------------------+-----------+---------+-----------------------------+

Request Parameters
^^^^^^^^^^^^^^^^^^

.. table:: **Table 3** Request header parameters

   ============ ========= ====== ================================================
   Parameter    Mandatory Type   Description
   ============ ========= ====== ================================================
   X-Auth-Token Yes       String Specifies the token used for IAM authentication.
   ============ ========= ====== ================================================

Response Parameters
^^^^^^^^^^^^^^^^^^^

**Status code: 200**

.. table:: **Table 4** Response body parameters

   +------------+-------------------------------+----------------------------------------+
   | Parameter  | Type                          | Description                            |
   +============+===============================+========================================+
   | request_id | String                        | Specifies the request ID. The value is |
   |            |                               | automatically generated.               |
   +------------+-------------------------------+----------------------------------------+
   | page_info  | :ref:`dll_pi` object          | Listener pagination information        |
   +------------+-------------------------------+----------------------------------------+
   | listeners  | Array of :ref:`dll_l` objects | Lists the listeners.                   |
   +------------+-------------------------------+----------------------------------------+

.. _dll_pi:
.. table:: **Table 5** PageInfo

   +-----------------+---------+----------------------------------------------------------------------------------------+
   | Parameter       | Type    | Description                                                                            |
   +=================+=========+========================================================================================+
   | previous_marker | String  | Specifies the ID of the first record in the pagination query result. This parameter    |
   |                 |         | will not be returned if no query result is returned.                                   |
   +-----------------+---------+----------------------------------------------------------------------------------------+
   | next_marker     | String  | Marks the start record on the next page in the pagination query result. This parameter |
   |                 |         | will not be returned if there is no next page.                                         |
   +-----------------+---------+----------------------------------------------------------------------------------------+
   | current_count   | Integer | Specifies the number of records.                                                       |
   +-----------------+---------+----------------------------------------------------------------------------------------+

.. _dll_l:
.. table:: **Table 6** Listener

   +------------------------------+---------------------------------+---------------------------------------+
   | Parameter                    | Type                            | Description                           |
   +==============================+=================================+=======================================+
   | admin_state_up               | Boolean                         | Specifies the administrative status   |
   |                              |                                 | of the listener. And the value can    |
   |                              |                                 | only be **true**.                     |
   |                              |                                 |                                       |
   |                              |                                 | This parameter is unsupported. Please |
   |                              |                                 | do not use it.                        |
   |                              |                                 |                                       |
   |                              |                                 | Default: **true**                     |
   +------------------------------+---------------------------------+---------------------------------------+
   | client_ca_tls_container_ref  | String                          | Specifies the ID of the CA            |
   |                              |                                 | certificate used by the listener.     |
   +------------------------------+---------------------------------+---------------------------------------+
   | connection_limit             | Integer                         | Specifies the maximum number of       |
   |                              |                                 | connections. The default value is     |
   |                              |                                 | **-1**.                               |
   |                              |                                 |                                       |
   |                              |                                 | This parameter is unsupported. Please |
   |                              |                                 | do not use it.                        |
   +------------------------------+---------------------------------+---------------------------------------+
   | created_at                   | String                          | Specifies the time when the listener  |
   |                              |                                 | was created.                          |
   +------------------------------+---------------------------------+---------------------------------------+
   | default_pool_id              | String                          | Specifies the ID of the default       |
   |                              |                                 | backend server group. If there is no  |
   |                              |                                 | matched forwarding policy, requests   |
   |                              |                                 | are forwarded to the default backend  |
   |                              |                                 | server.                               |
   +------------------------------+---------------------------------+---------------------------------------+
   | default_tls_container_ref    | String                          | Specifies the ID of the server        |
   |                              |                                 | certificate used by the listener.     |
   +------------------------------+---------------------------------+---------------------------------------+
   | description                  | String                          | Provides supplementary information    |
   |                              |                                 | about the listener.                   |
   +------------------------------+---------------------------------+---------------------------------------+
   | http2_enable                 | Boolean                         | Specifies whether to use HTTP/2. This |
   |                              |                                 | parameter is available only for HTTPS |
   |                              |                                 | listeners. If you configure this      |
   |                              |                                 | parameter for other types of          |
   |                              |                                 | listeners, it will not take effect.   |
   |                              |                                 |                                       |
   |                              |                                 | Enable HTTP/2 if you want the clients |
   |                              |                                 | to use HTTP/2 to communicate with the |
   |                              |                                 | load balancer. However, connections   |
   |                              |                                 | between the load balancer and backend |
   |                              |                                 | servers use HTTP/1.x by default.      |
   |                              |                                 |                                       |
   |                              |                                 | Default: **true**                     |
   +------------------------------+---------------------------------+---------------------------------------+
   | id                           | String                          | Specifies the listener ID.            |
   +------------------------------+---------------------------------+---------------------------------------+
   | insert_headers               | :ref:`dll_ih` object            | Specifies the HTTP header fields.     |
   +------------------------------+---------------------------------+---------------------------------------+
   | loadbalancers                | Array of :ref:`dll_lbr` objects | Specifies the ID of the load balancer |
   |                              |                                 | that the listener is added to.        |
   +------------------------------+---------------------------------+---------------------------------------+
   | name                         | String                          | Specifies the listener name.          |
   +------------------------------+---------------------------------+---------------------------------------+
   | project_id                   | String                          | Specifies the ID of the project where |
   |                              |                                 | the listener is used.                 |
   +------------------------------+---------------------------------+---------------------------------------+
   | protocol                     | String                          | Specifies the protocol used by the    |
   |                              |                                 | listener.                             |
   +------------------------------+---------------------------------+---------------------------------------+
   | protocol_port                | Integer                         | Specifies the port used by the        |
   |                              |                                 | listener.                             |
   |                              |                                 |                                       |
   |                              |                                 | Minimum: **1**                        |
   |                              |                                 |                                       |
   |                              |                                 | Maximum: **65535**                    |
   +------------------------------+---------------------------------+---------------------------------------+
   | sni_container_refs           | Array of strings                | Lists the IDs of SNI certificates     |
   |                              |                                 | (server certificates with domain      |
   |                              |                                 | names) used by the listener.          |
   |                              |                                 |                                       |
   |                              |                                 | Each SNI certificate can have up to   |
   |                              |                                 | 30 domain names, and each domain name |
   |                              |                                 | in the SNI certificate must be        |
   |                              |                                 | unique.                               |
   |                              |                                 |                                       |
   |                              |                                 | This parameter will be ignored and an |
   |                              |                                 | empty array will be returned if the   |
   |                              |                                 | listener's protocol is not HTTPS.     |
   +------------------------------+---------------------------------+---------------------------------------+
   | tags                         | Array of :ref:`dll_tag` objects | Lists the tags.                       |
   +------------------------------+---------------------------------+---------------------------------------+
   | updated_at                   | String                          | Specifies the time when the listener  |
   |                              |                                 | was updated.                          |
   +------------------------------+---------------------------------+---------------------------------------+
   | tls_ciphers_policy           | String                          | Specifies the security policy used by |
   |                              |                                 | the listener. This parameter is       |
   |                              |                                 | available only for HTTPS listeners.   |
   |                              |                                 |                                       |
   |                              |                                 | The value can be **tls-1-0**,         |
   |                              |                                 | **tls-1-1**, **tls-1-2**, or          |
   |                              |                                 | **tls-1-2-strict**, and the default   |
   |                              |                                 | value is **tls-1-0**.                 |
   +------------------------------+---------------------------------+---------------------------------------+
   | enable_member_retry          | Boolean                         | Specifies whether to enable health    |
   |                              |                                 | check retries for backend servers.    |
   |                              |                                 | This parameter is available only for  |
   |                              |                                 | HTTP and HTTPS listeners.             |
   +------------------------------+---------------------------------+---------------------------------------+
   | keepalive_timeout            | Integer                         | Specifies the idle timeout duration,  |
   |                              |                                 | in seconds.                           |
   |                              |                                 |                                       |
   |                              |                                 | -  For TCP listeners, the value       |
   |                              |                                 |    ranges from **10** to **4000**,    |
   |                              |                                 |    and the default value is **300**.  |
   |                              |                                 |                                       |
   |                              |                                 | -  For HTTP and HTTPS listeners, the  |
   |                              |                                 |    value ranges from **0** to         |
   |                              |                                 |    **4000**, and the default value is |
   |                              |                                 |    **60**.                            |
   |                              |                                 |                                       |
   |                              |                                 | -  For UDP listeners, this parameter  |
   |                              |                                 |    does not take effect.              |
   +------------------------------+---------------------------------+---------------------------------------+
   | client_timeout               | Integer                         | Specifies the timeout duration for    |
   |                              |                                 | waiting for a request from a client,  |
   |                              |                                 | in seconds.                           |
   |                              |                                 |                                       |
   |                              |                                 | This parameter is available only for  |
   |                              |                                 | HTTP and HTTPS listeners. The value   |
   |                              |                                 | ranges from **1** to **300**, and the |
   |                              |                                 | default value is **60**.              |
   +------------------------------+---------------------------------+---------------------------------------+
   | member_timeout               | Integer                         | Specifies the timeout duration for    |
   |                              |                                 | waiting for a request from a backend  |
   |                              |                                 | server, in seconds.                   |
   |                              |                                 |                                       |
   |                              |                                 | This parameter is available only for  |
   |                              |                                 | HTTP and HTTPS listeners. The value   |
   |                              |                                 | ranges from **1** to **300**, and the |
   |                              |                                 | default value is **60**.              |
   +------------------------------+---------------------------------+---------------------------------------+
   | ipgroup                      | :ref:`dll_ig` object            | Specifies the IP address group        |
   |                              |                                 | associated with the listener.         |
   |                              |                                 |                                       |
   |                              |                                 | This parameter is unsupported. Please |
   |                              |                                 | do not use it.                        |
   +------------------------------+---------------------------------+---------------------------------------+
   | transparent_client_ip_enable | Boolean                         | Specifies whether to pass source IP   |
   |                              |                                 | addresses of the clients to backend   |
   |                              |                                 | servers.                              |
   |                              |                                 |                                       |
   |                              |                                 | Shared load balancers: The value can  |
   |                              |                                 | be **true** or **false**, and the     |
   |                              |                                 | default value is **false** for TCP    |
   |                              |                                 | and UDP listeners. The value can only |
   |                              |                                 | be **true** for HTTP and HTTPS        |
   |                              |                                 | listeners. If this parameter is not   |
   |                              |                                 | passed, the default value is          |
   |                              |                                 | **true**.                             |
   |                              |                                 |                                       |
   |                              |                                 | Dedicated load balancers: The value   |
   |                              |                                 | can only be **true** for all types of |
   |                              |                                 | listeners. If this parameter is not   |
   |                              |                                 | passed, the default value is          |
   |                              |                                 | **true**.                             |
   +------------------------------+---------------------------------+---------------------------------------+
   | enhance_l7policy_enable      | Boolean                         | Specifies whether to enable advanced  |
   |                              |                                 | forwarding. The value can be **true** |
   |                              |                                 | or **false** (default).               |
   |                              |                                 |                                       |
   |                              |                                 | -  **true** indicates that advanced   |
   |                              |                                 |    forwarding will be enabled.        |
   |                              |                                 |                                       |
   |                              |                                 | -  **false** indicates that advanced  |
   |                              |                                 |    forwarding will not be enabled.    |
   |                              |                                 |                                       |
   |                              |                                 | The following parameters will be      |
   |                              |                                 | available only when advanced          |
   |                              |                                 | forwarding is enabled:                |
   |                              |                                 |                                       |
   |                              |                                 | -  **redirect_url_config**            |
   |                              |                                 |                                       |
   |                              |                                 | -  **fixed_response_config**          |
   |                              |                                 |                                       |
   |                              |                                 | -  **priority**                       |
   |                              |                                 |                                       |
   |                              |                                 | -  **conditions**                     |
   |                              |                                 |                                       |
   |                              |                                 | For details, see the descriptions in  |
   |                              |                                 | the APIs of forwarding policies and   |
   |                              |                                 | forwarding rules.                     |
   |                              |                                 |                                       |
   |                              |                                 | This parameter is unsupported. Please |
   |                              |                                 | do not use it.                        |
   +------------------------------+---------------------------------+---------------------------------------+

.. _dll_ih:
.. table:: **Table 7** ListenerInsertHeaders

   +----------------------+---------+---------------------------------------+
   | Parameter            | Type    | Description                           |
   +======================+=========+=======================================+
   | X-Forwarded-ELB-IP   | Boolean | Specifies whether to transparently    |
   |                      |         | transmit the load balancer EIP to     |
   |                      |         | backend servers. If                   |
   |                      |         | **X-Forwarded-ELB-IP** is set to      |
   |                      |         | **true**, the load balancer EIP will  |
   |                      |         | be stored in the HTTP header and      |
   |                      |         | passed to backend servers.            |
   |                      |         |                                       |
   |                      |         | Default: **false**                    |
   +----------------------+---------+---------------------------------------+
   | X-Forwarded-Port     | Boolean | Specifies whether to transparently    |
   |                      |         | transmit the listening port of the    |
   |                      |         | load balancer to backend servers. If  |
   |                      |         | **X-Forwarded-Port** is set to        |
   |                      |         | **true**, the listening port of the   |
   |                      |         | load balancer will be stored in the   |
   |                      |         | HTTP header and passed to backend     |
   |                      |         | servers.                              |
   |                      |         |                                       |
   |                      |         | Default: **false**                    |
   +----------------------+---------+---------------------------------------+
   | X-Forwarded-For-Port | Boolean | Specifies whether to transparently    |
   |                      |         | transmit the source port of the       |
   |                      |         | client to backend servers. If         |
   |                      |         | **X-Forwarded-For-Port** is set to    |
   |                      |         | **true**, the source port of the      |
   |                      |         | client will be stored in the HTTP     |
   |                      |         | header and passed to backend servers. |
   |                      |         |                                       |
   |                      |         | Default: **false**                    |
   +----------------------+---------+---------------------------------------+
   | X-Forwarded-Host     | Boolean | Specifies whether to rewrite the      |
   |                      |         | **X-Forwarded-Host** header. If       |
   |                      |         | **X-Forwarded-Host** is set to        |
   |                      |         | **true**, **X-Forwarded-Host** in the |
   |                      |         | request header from the clients can   |
   |                      |         | be set to **Host** in the request     |
   |                      |         | header sent from the load balancer to |
   |                      |         | backend servers.                      |
   |                      |         |                                       |
   |                      |         | Default: **true**                     |
   +----------------------+---------+---------------------------------------+

.. _dll_lbr:
.. table:: **Table 8** LoadBalancerRef

   ========= ====== ===============================
   Parameter Type   Description
   ========= ====== ===============================
   id        String Specifies the load balancer ID.
   ========= ====== ===============================

.. _dll_tag:
.. table:: **Table 9** Tag

   ========= ====== ========================
   Parameter Type   Description
   ========= ====== ========================
   key       String Specifies the tag key.
   value     String Specifies the tag value.
   ========= ====== ========================

.. _dll_ig:
.. table:: **Table 10** ListenerIpGroup

   +----------------+---------+---------------------------------------+
   | Parameter      | Type    | Description                           |
   +================+=========+=======================================+
   | ipgroup_id     | String  | Specifies the ID of the IP address    |
   |                |         | group associated with the listener.   |
   |                |         |                                       |
   |                |         | -  If **ip_list** is set to **[]**    |
   |                |         |    and **type** to **whitelist**, no  |
   |                |         |    IP addresses are allowed to access |
   |                |         |    the listener.                      |
   |                |         |                                       |
   |                |         | -  If **ip_list** is set to **[]**    |
   |                |         |    and **type** to **blacklist**, any |
   |                |         |    IP address is allowed to access    |
   |                |         |    the listener.                      |
   |                |         |                                       |
   |                |         | -  The specified IP address group     |
   |                |         |    must exist and this parameter      |
   |                |         |    cannot be set to **null**.         |
   +----------------+---------+---------------------------------------+
   | enable_ipgroup | Boolean | Specifies whether to enable access    |
   |                |         | control.                              |
   |                |         |                                       |
   |                |         | -  **true**: Access control is        |
   |                |         |    enabled.                           |
   |                |         |                                       |
   |                |         | -  **false**: Access control is       |
   |                |         |    disabled.                          |
   |                |         |                                       |
   |                |         | A listener with access control        |
   |                |         | enabled can be directly deleted.      |
   +----------------+---------+---------------------------------------+
   | type           | String  | Specifies how access to the listener  |
   |                |         | is controlled.                        |
   |                |         |                                       |
   |                |         | -  **white**: A whitelist is          |
   |                |         |    configured. Only IP addresses in   |
   |                |         |    the whitelist can access the       |
   |                |         |    listener.                          |
   |                |         |                                       |
   |                |         | -  **black**: A blacklist is          |
   |                |         |    configured. IP addresses in the    |
   |                |         |    blacklist are not allowed to       |
   |                |         |    access the listener.               |
   +----------------+---------+---------------------------------------+

Example Requests
^^^^^^^^^^^^^^^^

.. code::

   GET

   https://{ELB_Endpoint}/v3/060576782980d5762f9ec014dd2f1148/elb/listeners?limit=2&marker=22e221c4-37c7-45d6-a76a-6e5a3bf485ba

Example Responses
^^^^^^^^^^^^^^^^^

**Status code: 200**

Successful request.

.. code::

   {
     "request_id" : "e77338298c98d52202fd60bdacec0d75",
     "listeners" : [ {
       "id" : "683cf917-3e51-4c41-830c-bc3a57e090f0",
       "name" : "My listener",
       "protocol_port" : 90,
       "protocol" : "HTTPS",
       "description" : "",
       "default_tls_container_ref" : "4e7761d7c7d141c389479f2641c8bff8",
       "admin_state_up" : true,
       "loadbalancers" : [ {
         "id" : "ac82ca77-8be3-4d65-9c4d-155771b463df"
       } ],
       "project_id" : "060576782980d5762f9ec014dd2f1148",
       "sni_container_refs" : [ ],
       "connection_limit" : -1,
       "tls_ciphers_policy" : "tls-1-0",
       "tags" : [ ],
       "created_at" : "2021-04-02T07:48:38Z",
       "updated_at" : "2021-04-02T07:48:38Z",
       "http2_enable" : false,
       "insert_headers" : {
         "X-Forwarded-ELB-IP" : false,
         "X-Forwarded-Host" : true,
         "X-Forwarded-For-Port" : false,
         "X-Forwarded-Port" : false
       },
       "member_timeout" : 60,
       "client_timeout" : 60,
       "keepalive_timeout" : 60,
       "enable_member_retry" : true,
       "transparent_client_ip_enable" : true,
       "enhance_l7policy_enable" : false
     }, {
       "id" : "1173360b-5911-4aa9-a1ec-05e9f714370c",
       "name" : "listener-sshd",
       "protocol_port" : 22,
       "protocol" : "TCP",
       "description" : "",
       "admin_state_up" : true,
       "loadbalancers" : [ {
         "id" : "4d196846-d63c-4e7b-9875-2c4f04a48661"
       } ],
       "project_id" : "060576782980d5762f9ec014dd2f1148",
       "sni_container_refs" : [ ],
       "connection_limit" : -1,
       "default_pool_id" : "6350052f-e060-4f80-b92f-f21255dba4c4",
       "tags" : [ ],
       "created_at" : "2021-04-01T08:21:15Z",
       "updated_at" : "2021-04-01T08:21:15Z",
       "http2_enable" : false,
       "insert_headers" : {
         "X-Forwarded-ELB-IP" : false,
         "X-Forwarded-Host" : true,
         "X-Forwarded-For-Port" : false,
         "X-Forwarded-Port" : false
       },
       "keepalive_timeout" : 4000,
       "enable_member_retry" : true,
       "transparent_client_ip_enable" : true,
       "enhance_l7policy_enable" : false
     } ],
     "page_info" : {
       "next_marker" : "1173360b-5911-4aa9-a1ec-05e9f714370c",
       "previous_marker" : "683cf917-3e51-4c41-830c-bc3a57e090f0",
       "current_count" : 2
     }
   }

Status Codes
^^^^^^^^^^^^

=========== ===================
Status Code Description
=========== ===================
200         Successful request.
=========== ===================

Error Codes
^^^^^^^^^^^

See :ref:`dsc`.

Viewing Details of a Listener
=============================

Function
^^^^^^^^

This API is used to view details of a listener.

URI
^^^

GET /v3/{project_id}/elb/listeners/{listener_id}

.. table:: **Table 1** Path parameters

   =========== ========= ====== ==========================
   Parameter   Mandatory Type   Description
   =========== ========= ====== ==========================
   project_id  Yes       String Specifies the project ID.
   listener_id Yes       String Specifies the listener ID.
   =========== ========= ====== ==========================

Request Parameters
^^^^^^^^^^^^^^^^^^

.. table:: **Table 2** Request header parameters

   ============ ========= ====== ================================================
   Parameter    Mandatory Type   Description
   ============ ========= ====== ================================================
   X-Auth-Token Yes       String Specifies the token used for IAM authentication.
   ============ ========= ====== ================================================

Response Parameters
^^^^^^^^^^^^^^^^^^^

**Status code: 200**

.. table:: **Table 3** Response body parameters

   +------------+---------------------+----------------------------------------+
   | Parameter  | Type                | Description                            |
   +============+=====================+========================================+
   | request_id | String              | Specifies the request ID. The value is |
   |            |                     | automatically generated.               |
   +------------+---------------------+----------------------------------------+
   | listener   | :ref:`dls_l` object | Specifies the listener.                |
   +------------+---------------------+----------------------------------------+

.. _dls_l:
.. table:: **Table 4** Listener

   +------------------------------+-------------------------+---------------------------------------+
   | Parameter                    | Type                    | Description                           |
   +==============================+=========================+=======================================+
   | admin_state_up               | Boolean                 | Specifies the administrative status   |
   |                              |                         | of the listener. And the value can    |
   |                              |                         | only be **true**.                     |
   |                              |                         |                                       |
   |                              |                         | This parameter is unsupported. Please |
   |                              |                         | do not use it.                        |
   |                              |                         |                                       |
   |                              |                         | Default: **true**                     |
   +------------------------------+-------------------------+---------------------------------------+
   | client_ca_tls_container_ref  | String                  | Specifies the ID of the CA            |
   |                              |                         | certificate used by the listener.     |
   +------------------------------+-------------------------+---------------------------------------+
   | connection_limit             | Integer                 | Specifies the maximum number of       |
   |                              |                         | connections. The default value is     |
   |                              |                         | **-1**.                               |
   |                              |                         |                                       |
   |                              |                         | This parameter is unsupported. Please |
   |                              |                         | do not use it.                        |
   +------------------------------+-------------------------+---------------------------------------+
   | created_at                   | String                  | Specifies the time when the listener  |
   |                              |                         | was created.                          |
   +------------------------------+-------------------------+---------------------------------------+
   | default_pool_id              | String                  | Specifies the ID of the default       |
   |                              |                         | backend server group. If there is no  |
   |                              |                         | matched forwarding policy, requests   |
   |                              |                         | are forwarded to the default backend  |
   |                              |                         | server.                               |
   +------------------------------+-------------------------+---------------------------------------+
   | default_tls_container_ref    | String                  | Specifies the ID of the server        |
   |                              |                         | certificate used by the listener.     |
   +------------------------------+-------------------------+---------------------------------------+
   | description                  | String                  | Provides supplementary information    |
   |                              |                         | about the listener.                   |
   +------------------------------+-------------------------+---------------------------------------+
   | http2_enable                 | Boolean                 | Specifies whether to use HTTP/2. This |
   |                              |                         | parameter is available only for HTTPS |
   |                              |                         | listeners. If you configure this      |
   |                              |                         | parameter for other types of          |
   |                              |                         | listeners, it will not take effect.   |
   |                              |                         |                                       |
   |                              |                         | Enable HTTP/2 if you want the clients |
   |                              |                         | to use HTTP/2 to communicate with the |
   |                              |                         | load balancer. However, connections   |
   |                              |                         | between the load balancer and backend |
   |                              |                         | servers use HTTP/1.x by default.      |
   |                              |                         |                                       |
   |                              |                         | Default: **true**                     |
   +------------------------------+-------------------------+---------------------------------------+
   | id                           | String                  | Specifies the listener ID.            |
   +------------------------------+-------------------------+---------------------------------------+
   | insert_headers               | :ref:`dls_ih` object    | Specifies the HTTP header fields.     |
   +------------------------------+-------------------------+---------------------------------------+
   | loadbalancers                | Array of :ref:`dls_lbr` | Specifies the ID of the load balancer |
   |                              | objects                 | that the listener is added to.        |
   +------------------------------+-------------------------+---------------------------------------+
   | name                         | String                  | Specifies the listener name.          |
   +------------------------------+-------------------------+---------------------------------------+
   | project_id                   | String                  | Specifies the ID of the project where |
   |                              |                         | the listener is used.                 |
   +------------------------------+-------------------------+---------------------------------------+
   | protocol                     | String                  | Specifies the protocol used by the    |
   |                              |                         | listener.                             |
   +------------------------------+-------------------------+---------------------------------------+
   | protocol_port                | Integer                 | Specifies the port used by the        |
   |                              |                         | listener.                             |
   |                              |                         |                                       |
   |                              |                         | Minimum: **1**                        |
   |                              |                         |                                       |
   |                              |                         | Maximum: **65535**                    |
   +------------------------------+-------------------------+---------------------------------------+
   | sni_container_refs           | Array of strings        | Lists the IDs of SNI certificates     |
   |                              |                         | (server certificates with domain      |
   |                              |                         | names) used by the listener.          |
   |                              |                         |                                       |
   |                              |                         | Each SNI certificate can have up to   |
   |                              |                         | 30 domain names, and each domain name |
   |                              |                         | in the SNI certificate must be        |
   |                              |                         | unique.                               |
   |                              |                         |                                       |
   |                              |                         | This parameter will be ignored and an |
   |                              |                         | empty array will be returned if the   |
   |                              |                         | listener's protocol is not HTTPS.     |
   +------------------------------+-------------------------+---------------------------------------+
   | tags                         | Array of :ref:`dls_tag` | Lists the tags.                       |
   |                              | objects                 |                                       |
   +------------------------------+-------------------------+---------------------------------------+
   | updated_at                   | String                  | Specifies the time when the listener  |
   |                              |                         | was updated.                          |
   +------------------------------+-------------------------+---------------------------------------+
   | tls_ciphers_policy           | String                  | Specifies the security policy used by |
   |                              |                         | the listener. This parameter is       |
   |                              |                         | available only for HTTPS listeners.   |
   |                              |                         |                                       |
   |                              |                         | The value can be **tls-1-0**,         |
   |                              |                         | **tls-1-1**, **tls-1-2**, or          |
   |                              |                         | **tls-1-2-strict**, and the default   |
   |                              |                         | value is **tls-1-0**.                 |
   +------------------------------+-------------------------+---------------------------------------+
   | enable_member_retry          | Boolean                 | Specifies whether to enable health    |
   |                              |                         | check retries for backend servers.    |
   |                              |                         | This parameter is available only for  |
   |                              |                         | HTTP and HTTPS listeners.             |
   +------------------------------+-------------------------+---------------------------------------+
   | keepalive_timeout            | Integer                 | Specifies the idle timeout duration,  |
   |                              |                         | in seconds.                           |
   |                              |                         |                                       |
   |                              |                         | -  For TCP listeners, the value       |
   |                              |                         |    ranges from **10** to **4000**,    |
   |                              |                         |    and the default value is **300**.  |
   |                              |                         |                                       |
   |                              |                         | -  For HTTP and HTTPS listeners, the  |
   |                              |                         |    value ranges from **0** to         |
   |                              |                         |    **4000**, and the default value is |
   |                              |                         |    **60**.                            |
   |                              |                         |                                       |
   |                              |                         | -  For UDP listeners, this parameter  |
   |                              |                         |    does not take effect.              |
   +------------------------------+-------------------------+---------------------------------------+
   | client_timeout               | Integer                 | Specifies the timeout duration for    |
   |                              |                         | waiting for a request from a client,  |
   |                              |                         | in seconds.                           |
   |                              |                         |                                       |
   |                              |                         | This parameter is available only for  |
   |                              |                         | HTTP and HTTPS listeners. The value   |
   |                              |                         | ranges from **1** to **300**, and the |
   |                              |                         | default value is **60**.              |
   +------------------------------+-------------------------+---------------------------------------+
   | member_timeout               | Integer                 | Specifies the timeout duration for    |
   |                              |                         | waiting for a request from a backend  |
   |                              |                         | server, in seconds.                   |
   |                              |                         |                                       |
   |                              |                         | This parameter is available only for  |
   |                              |                         | HTTP and HTTPS listeners. The value   |
   |                              |                         | ranges from **1** to **300**, and the |
   |                              |                         | default value is **60**.              |
   +------------------------------+-------------------------+---------------------------------------+
   | ipgroup                      | :ref:`dls_ig` object    | Specifies the IP address group        |
   |                              |                         | associated with the listener.         |
   |                              |                         |                                       |
   |                              |                         | This parameter is unsupported. Please |
   |                              |                         | do not use it.                        |
   +------------------------------+-------------------------+---------------------------------------+
   | transparent_client_ip_enable | Boolean                 | Specifies whether to pass source IP   |
   |                              |                         | addresses of the clients to backend   |
   |                              |                         | servers.                              |
   |                              |                         |                                       |
   |                              |                         | Shared load balancers: The value can  |
   |                              |                         | be **true** or **false**, and the     |
   |                              |                         | default value is **false** for TCP    |
   |                              |                         | and UDP listeners. The value can only |
   |                              |                         | be **true** for HTTP and HTTPS        |
   |                              |                         | listeners. If this parameter is not   |
   |                              |                         | passed, the default value is          |
   |                              |                         | **true**.                             |
   |                              |                         |                                       |
   |                              |                         | Dedicated load balancers: The value   |
   |                              |                         | can only be **true** for all types of |
   |                              |                         | listeners. If this parameter is not   |
   |                              |                         | passed, the default value is          |
   |                              |                         | **true**.                             |
   +------------------------------+-------------------------+---------------------------------------+
   | enhance_l7policy_enable      | Boolean                 | Specifies whether to enable advanced  |
   |                              |                         | forwarding. The value can be **true** |
   |                              |                         | or **false** (default).               |
   |                              |                         |                                       |
   |                              |                         | -  **true** indicates that advanced   |
   |                              |                         |    forwarding will be enabled.        |
   |                              |                         |                                       |
   |                              |                         | -  **false** indicates that advanced  |
   |                              |                         |    forwarding will not be enabled.    |
   |                              |                         |                                       |
   |                              |                         | The following parameters will be      |
   |                              |                         | available only when advanced          |
   |                              |                         | forwarding is enabled:                |
   |                              |                         |                                       |
   |                              |                         | -  **redirect_url_config**            |
   |                              |                         |                                       |
   |                              |                         | -  **fixed_response_config**          |
   |                              |                         |                                       |
   |                              |                         | -  **priority**                       |
   |                              |                         |                                       |
   |                              |                         | -  **conditions**                     |
   |                              |                         |                                       |
   |                              |                         | For details, see the descriptions in  |
   |                              |                         | the APIs of forwarding policies and   |
   |                              |                         | forwarding rules.                     |
   |                              |                         |                                       |
   |                              |                         | This parameter is unsupported. Please |
   |                              |                         | do not use it.                        |
   +------------------------------+-------------------------+---------------------------------------+

.. _dls_ih:
.. table:: **Table 5** ListenerInsertHeaders

   +----------------------+---------+---------------------------------------+
   | Parameter            | Type    | Description                           |
   +======================+=========+=======================================+
   | X-Forwarded-ELB-IP   | Boolean | Specifies whether to transparently    |
   |                      |         | transmit the load balancer EIP to     |
   |                      |         | backend servers. If                   |
   |                      |         | **X-Forwarded-ELB-IP** is set to      |
   |                      |         | **true**, the load balancer EIP will  |
   |                      |         | be stored in the HTTP header and      |
   |                      |         | passed to backend servers.            |
   |                      |         |                                       |
   |                      |         | Default: **false**                    |
   +----------------------+---------+---------------------------------------+
   | X-Forwarded-Port     | Boolean | Specifies whether to transparently    |
   |                      |         | transmit the listening port of the    |
   |                      |         | load balancer to backend servers. If  |
   |                      |         | **X-Forwarded-Port** is set to        |
   |                      |         | **true**, the listening port of the   |
   |                      |         | load balancer will be stored in the   |
   |                      |         | HTTP header and passed to backend     |
   |                      |         | servers.                              |
   |                      |         |                                       |
   |                      |         | Default: **false**                    |
   +----------------------+---------+---------------------------------------+
   | X-Forwarded-For-Port | Boolean | Specifies whether to transparently    |
   |                      |         | transmit the source port of the       |
   |                      |         | client to backend servers. If         |
   |                      |         | **X-Forwarded-For-Port** is set to    |
   |                      |         | **true**, the source port of the      |
   |                      |         | client will be stored in the HTTP     |
   |                      |         | header and passed to backend servers. |
   |                      |         |                                       |
   |                      |         | Default: **false**                    |
   +----------------------+---------+---------------------------------------+
   | X-Forwarded-Host     | Boolean | Specifies whether to rewrite the      |
   |                      |         | **X-Forwarded-Host** header. If       |
   |                      |         | **X-Forwarded-Host** is set to        |
   |                      |         | **true**, **X-Forwarded-Host** in the |
   |                      |         | request header from the clients can   |
   |                      |         | be set to **Host** in the request     |
   |                      |         | header sent from the load balancer to |
   |                      |         | backend servers.                      |
   |                      |         |                                       |
   |                      |         | Default: **true**                     |
   +----------------------+---------+---------------------------------------+

.. _dls_lbr:
.. table:: **Table 6** LoadBalancerRef

   ========= ====== ===============================
   Parameter Type   Description
   ========= ====== ===============================
   id        String Specifies the load balancer ID.
   ========= ====== ===============================

.. _dls_tag:
.. table:: **Table 7** Tag

   ========= ====== ========================
   Parameter Type   Description
   ========= ====== ========================
   key       String Specifies the tag key.
   value     String Specifies the tag value.
   ========= ====== ========================

.. _dls_ig:
.. table:: **Table 8** ListenerIpGroup

   +----------------+---------+---------------------------------------+
   | Parameter      | Type    | Description                           |
   +================+=========+=======================================+
   | ipgroup_id     | String  | Specifies the ID of the IP address    |
   |                |         | group associated with the listener.   |
   |                |         |                                       |
   |                |         | -  If **ip_list** is set to **[]**    |
   |                |         |    and **type** to **whitelist**, no  |
   |                |         |    IP addresses are allowed to access |
   |                |         |    the listener.                      |
   |                |         |                                       |
   |                |         | -  If **ip_list** is set to **[]**    |
   |                |         |    and **type** to **blacklist**, any |
   |                |         |    IP address is allowed to access    |
   |                |         |    the listener.                      |
   |                |         |                                       |
   |                |         | -  The specified IP address group     |
   |                |         |    must exist and this parameter      |
   |                |         |    cannot be set to **null**.         |
   +----------------+---------+---------------------------------------+
   | enable_ipgroup | Boolean | Specifies whether to enable access    |
   |                |         | control.                              |
   |                |         |                                       |
   |                |         | -  **true**: Access control is        |
   |                |         |    enabled.                           |
   |                |         |                                       |
   |                |         | -  **false**: Access control is       |
   |                |         |    disabled.                          |
   |                |         |                                       |
   |                |         | A listener with access control        |
   |                |         | enabled can be directly deleted.      |
   +----------------+---------+---------------------------------------+
   | type           | String  | Specifies how access to the listener  |
   |                |         | is controlled.                        |
   |                |         |                                       |
   |                |         | -  **white**: A whitelist is          |
   |                |         |    configured. Only IP addresses in   |
   |                |         |    the whitelist can access the       |
   |                |         |    listener.                          |
   |                |         |                                       |
   |                |         | -  **black**: A blacklist is          |
   |                |         |    configured. IP addresses in the    |
   |                |         |    blacklist are not allowed to       |
   |                |         |    access the listener.               |
   +----------------+---------+---------------------------------------+

Example Requests
^^^^^^^^^^^^^^^^

.. code::

   GET

   https://{ELB_Endpoint}/v3/060576782980d5762f9ec014dd2f1148/elb/listeners/683cf917-3e51-4c41-830c-bc3a57e090f0

Example Responses
^^^^^^^^^^^^^^^^^

**Status code: 200**

Successful request.

.. code::

   {
     "listener" : {
       "id" : "683cf917-3e51-4c41-830c-bc3a57e090f0",
       "name" : "My listener",
       "protocol_port" : 90,
       "protocol" : "HTTPS",
       "description" : "",
       "default_tls_container_ref" : "4e7761d7c7d141c389479f2641c8bff8",
       "admin_state_up" : true,
       "loadbalancers" : [ {
         "id" : "ac82ca77-8be3-4d65-9c4d-155771b463df"
       } ],
       "project_id" : "060576782980d5762f9ec014dd2f1148",
       "sni_container_refs" : [ ],
       "connection_limit" : -1,
       "tls_ciphers_policy" : "tls-1-0",
       "tags" : [ ],
       "created_at" : "2021-04-02T07:48:38Z",
       "updated_at" : "2021-04-02T07:48:38Z",
       "http2_enable" : false,
       "insert_headers" : {
         "X-Forwarded-ELB-IP" : false,
         "X-Forwarded-Host" : true,
         "X-Forwarded-For-Port" : false,
         "X-Forwarded-Port" : false
       },
       "member_timeout" : 60,
       "client_timeout" : 60,
       "keepalive_timeout" : 60,
       "enable_member_retry" : true,
       "transparent_client_ip_enable" : true,
       "enhance_l7policy_enable" : false
     },
     "request_id" : "830de7c7c38232d925db168bfb3cb0e8"
   }

Status Codes
^^^^^^^^^^^^

=========== ===================
Status Code Description
=========== ===================
200         Successful request.
=========== ===================

Error Codes
^^^^^^^^^^^

See :ref:`dsc`.

Updating a Listener
===================

Function
^^^^^^^^

This API is used to update a listener.

Constraints
^^^^^^^^^^^

If the provisioning status of the load balancer that the listener is added to
is not **ACTIVE**, the listener cannot be updated. Only the administrator can
specify **connection_limit**.

URI
^^^

PUT /v3/{project_id}/elb/listeners/{listener_id}

.. table:: **Table 1** Path parameters

   =========== ========= ====== ==========================
   Parameter   Mandatory Type   Description
   =========== ========= ====== ==========================
   listener_id Yes       String Specifies the listener ID.
   project_id  Yes       String Specifies the tenant ID.
   =========== ========= ====== ==========================

Request Parameters
^^^^^^^^^^^^^^^^^^

.. table:: **Table 2** Request header parameters

   ============ ========= ====== ================================================
   Parameter    Mandatory Type   Description
   ============ ========= ====== ================================================
   X-Auth-Token Yes       String Specifies the token used for IAM authentication.
   ============ ========= ====== ================================================

.. table:: **Table 3** Request body parameters

   +-----------+-----------+----------------------+-------------------------+
   | Parameter | Mandatory | Type                 | Description             |
   +===========+===========+======================+=========================+
   | listener  | Yes       | :ref:`dlu_lo` object | Specifies the listener. |
   +-----------+-----------+----------------------+-------------------------+

.. _dlu_lo:
.. table:: **Table 4** UpdateListenerOption

   +-----------------------------+-----------+-----------------------+-----------------------------+
   | Parameter                   | Mandatory | Type                  | Description                 |
   +=============================+===========+=======================+=============================+
   | admin_state_up              | No        | Boolean               | Specifies the               |
   |                             |           |                       | administrative status of    |
   |                             |           |                       | the listener. And the value |
   |                             |           |                       | can only be **true**.       |
   |                             |           |                       |                             |
   |                             |           |                       | This parameter is           |
   |                             |           |                       | unsupported. Please do not  |
   |                             |           |                       | use it.                     |
   +-----------------------------+-----------+-----------------------+-----------------------------+
   | client_ca_tls_container_ref | No        | String                | Specifies the ID of the CA  |
   |                             |           |                       | certificate used by the     |
   |                             |           |                       | listener.                   |
   +-----------------------------+-----------+-----------------------+-----------------------------+
   | default_pool_id             | No        | String                | Specifies the ID of the     |
   |                             |           |                       | default backend server      |
   |                             |           |                       | group. If there is no       |
   |                             |           |                       | matched forwarding policy,  |
   |                             |           |                       | requests are forwarded to   |
   |                             |           |                       | the default backend server. |
   |                             |           |                       |                             |
   |                             |           |                       | Minimum: **1**              |
   |                             |           |                       |                             |
   |                             |           |                       | Maximum: **36**             |
   +-----------------------------+-----------+-----------------------+-----------------------------+
   | default_tls_container_ref   | No        | String                | Specifies the ID of the     |
   |                             |           |                       | server certificate used by  |
   |                             |           |                       | the listener.               |
   +-----------------------------+-----------+-----------------------+-----------------------------+
   | description                 | No        | String                | Provides supplementary      |
   |                             |           |                       | information about the       |
   |                             |           |                       | listener.                   |
   |                             |           |                       |                             |
   |                             |           |                       | Minimum: **1**              |
   |                             |           |                       |                             |
   |                             |           |                       | Maximum: **255**            |
   +-----------------------------+-----------+-----------------------+-----------------------------+
   | http2_enable                | No        | Boolean               | Specifies whether to use    |
   |                             |           |                       | HTTP/2. This parameter is   |
   |                             |           |                       | available only for HTTPS    |
   |                             |           |                       | listeners. If you configure |
   |                             |           |                       | this parameter for other    |
   |                             |           |                       | types of listeners, it will |
   |                             |           |                       | not take effect.            |
   |                             |           |                       |                             |
   |                             |           |                       | Enable HTTP/2 if you want   |
   |                             |           |                       | the clients to use HTTP/2   |
   |                             |           |                       | to communicate with the     |
   |                             |           |                       | load balancer. However,     |
   |                             |           |                       | connections between the     |
   |                             |           |                       | load balancer and backend   |
   |                             |           |                       | servers use HTTP/1.x by     |
   |                             |           |                       | default.                    |
   |                             |           |                       |                             |
   |                             |           |                       | Default: **true**           |
   +-----------------------------+-----------+-----------------------+-----------------------------+
   | insert_headers              | No        | :ref:`dlu_ih` object  | Specifies the HTTP header   |
   |                             |           |                       | fields.                     |
   +-----------------------------+-----------+-----------------------+-----------------------------+
   | name                        | No        | String                | Specifies the listener      |
   |                             |           |                       | name.                       |
   |                             |           |                       |                             |
   |                             |           |                       | Minimum: **1**              |
   |                             |           |                       |                             |
   |                             |           |                       | Maximum: **255**            |
   +-----------------------------+-----------+-----------------------+-----------------------------+
   | sni_container_refs          | No        | Array of strings      | Lists the IDs of SNI        |
   |                             |           |                       | certificates (server        |
   |                             |           |                       | certificates with domain    |
   |                             |           |                       | names) used by the          |
   |                             |           |                       | listener.                   |
   |                             |           |                       |                             |
   |                             |           |                       | Each SNI certificate can    |
   |                             |           |                       | have up to 30 domain names, |
   |                             |           |                       | and each domain name in the |
   |                             |           |                       | SNI certificate must be     |
   |                             |           |                       | unique.                     |
   |                             |           |                       |                             |
   |                             |           |                       | This parameter will be      |
   |                             |           |                       | ignored and an empty array  |
   |                             |           |                       | will be returned if the     |
   |                             |           |                       | listener's protocol is not  |
   |                             |           |                       | HTTPS.                      |
   +-----------------------------+-----------+-----------------------+-----------------------------+
   | tls_ciphers_policy          | No        | String                | Specifies the security      |
   |                             |           |                       | policy used by the          |
   |                             |           |                       | listener.                   |
   |                             |           |                       |                             |
   |                             |           |                       | This parameter is available |
   |                             |           |                       | only for HTTPS listeners.   |
   |                             |           |                       | The default value is        |
   |                             |           |                       | **tls-1-0**.                |
   |                             |           |                       |                             |
   |                             |           |                       | An error will be returned   |
   |                             |           |                       | if the protocol of the      |
   |                             |           |                       | listener is not HTTPS.      |
   |                             |           |                       |                             |
   |                             |           |                       | Value options:              |
   |                             |           |                       |                             |
   |                             |           |                       | -  **tls-1-0**              |
   |                             |           |                       |                             |
   |                             |           |                       | -  **tls-1-1**              |
   |                             |           |                       |                             |
   |                             |           |                       | -  **tls-1-2**              |
   |                             |           |                       |                             |
   |                             |           |                       | -  **tls-1-2-strict**       |
   +-----------------------------+-----------+-----------------------+-----------------------------+
   | enable_member_retry         | No        | Boolean               | Specifies whether to enable |
   |                             |           |                       | health check retries for    |
   |                             |           |                       | backend servers. This       |
   |                             |           |                       | parameter is available only |
   |                             |           |                       | for HTTP and HTTPS          |
   |                             |           |                       | listeners of Shared load    |
   |                             |           |                       | balancers.                  |
   |                             |           |                       |                             |
   |                             |           |                       | Default: **false**          |
   +-----------------------------+-----------+-----------------------+-----------------------------+
   | member_timeout              | No        | Integer               | Specifies the timeout       |
   |                             |           |                       | duration for waiting for a  |
   |                             |           |                       | request from a backend      |
   |                             |           |                       | server, in seconds.         |
   |                             |           |                       |                             |
   |                             |           |                       | This parameter is available |
   |                             |           |                       | only for HTTP and HTTPS     |
   |                             |           |                       | listeners. The value ranges |
   |                             |           |                       | from **1** to **300**, and  |
   |                             |           |                       | the default value is        |
   |                             |           |                       | **60**.                     |
   +-----------------------------+-----------+-----------------------+-----------------------------+
   | client_timeout              | No        | Integer               | Specifies the timeout       |
   |                             |           |                       | duration for waiting for a  |
   |                             |           |                       | request from a client, in   |
   |                             |           |                       | seconds.                    |
   |                             |           |                       |                             |
   |                             |           |                       | This parameter is available |
   |                             |           |                       | only for HTTP and HTTPS     |
   |                             |           |                       | listeners. The value ranges |
   |                             |           |                       | from **1** to **300**, and  |
   |                             |           |                       | the default value is        |
   |                             |           |                       | **60**.                     |
   +-----------------------------+-----------+-----------------------+-----------------------------+
   | keepalive_timeout           | No        | Integer               | Specifies the idle timeout  |
   |                             |           |                       | duration, in seconds.       |
   |                             |           |                       |                             |
   |                             |           |                       | -  For TCP listeners, the   |
   |                             |           |                       |    value ranges from **10** |
   |                             |           |                       |    to **4000**, and the     |
   |                             |           |                       |    default value is         |
   |                             |           |                       |    **300**.                 |
   |                             |           |                       |                             |
   |                             |           |                       | -  For HTTP and HTTPS       |
   |                             |           |                       |    listeners, the value     |
   |                             |           |                       |    ranges from **0** to     |
   |                             |           |                       |    **4000**, and the        |
   |                             |           |                       |    default value is **60**. |
   |                             |           |                       |                             |
   |                             |           |                       | -  For UDP listeners, this  |
   |                             |           |                       |    parameter is invalid.    |
   +-----------------------------+-----------+-----------------------+-----------------------------+
   | ipgroup                     | No        | :ref:`dlu_igo` object | Specifies the IP address    |
   |                             |           |                       | group associated with the   |
   |                             |           |                       | listener.                   |
   |                             |           |                       |                             |
   |                             |           |                       | The value can be **null**   |
   |                             |           |                       | or an empty JSON structure, |
   |                             |           |                       | indicating that no IP       |
   |                             |           |                       | address group is associated |
   |                             |           |                       | with the listener.          |
   |                             |           |                       |                             |
   |                             |           |                       | **ipgroup_id** is also      |
   |                             |           |                       | required if you want to     |
   |                             |           |                       | associate an IP address     |
   |                             |           |                       | group with the listener.    |
   |                             |           |                       |                             |
   |                             |           |                       | This parameter is           |
   |                             |           |                       | unsupported. Please do not  |
   |                             |           |                       | use it.                     |
   +-----------------------------+-----------+-----------------------+-----------------------------+
   | t                           | No        | Boolean               | Specifies whether to pass   |
   | ransparent_client_ip_enable |           |                       | source IP addresses of the  |
   |                             |           |                       | clients to backend servers. |
   |                             |           |                       |                             |
   |                             |           |                       | Shared load balancers: The  |
   |                             |           |                       | value can be **true** or    |
   |                             |           |                       | **false**, and the default  |
   |                             |           |                       | value is **false** for TCP  |
   |                             |           |                       | and UDP listeners. The      |
   |                             |           |                       | value can only be **true**  |
   |                             |           |                       | for HTTP and HTTPS          |
   |                             |           |                       | listeners. If this          |
   |                             |           |                       | parameter is not passed,    |
   |                             |           |                       | the default value is        |
   |                             |           |                       | **true**.                   |
   |                             |           |                       |                             |
   |                             |           |                       | Dedicated load balancers:   |
   |                             |           |                       | The value can only be       |
   |                             |           |                       | **true** for all types of   |
   |                             |           |                       | listeners. If this          |
   |                             |           |                       | parameter is not passed,    |
   |                             |           |                       | the default value is        |
   |                             |           |                       | **true**.                   |
   +-----------------------------+-----------+-----------------------+-----------------------------+
   | enhance_l7policy_enable     | No        | Boolean               | Specifies whether to enable |
   |                             |           |                       | advanced forwarding. The    |
   |                             |           |                       | value can be **true** or    |
   |                             |           |                       | **false** (default).        |
   |                             |           |                       |                             |
   |                             |           |                       | -  **true** indicates that  |
   |                             |           |                       |    advanced forwarding will |
   |                             |           |                       |    be enabled. Advanced     |
   |                             |           |                       |    forwarding cannot be     |
   |                             |           |                       |    disabled once it is      |
   |                             |           |                       |    enabled.                 |
   |                             |           |                       |                             |
   |                             |           |                       | -  **false** indicates that |
   |                             |           |                       |    advanced forwarding will |
   |                             |           |                       |    not be enabled.          |
   |                             |           |                       |                             |
   |                             |           |                       | The following parameters    |
   |                             |           |                       | will be available only when |
   |                             |           |                       | advanced forwarding is      |
   |                             |           |                       | enabled:                    |
   |                             |           |                       |                             |
   |                             |           |                       | -  **redirect_url_config**  |
   |                             |           |                       |                             |
   |                             |           |                       | -                           |
   |                             |           |                       |   **fixed_response_config** |
   |                             |           |                       |                             |
   |                             |           |                       | -  **priority**             |
   |                             |           |                       |                             |
   |                             |           |                       | -  **conditions**           |
   |                             |           |                       |                             |
   |                             |           |                       | For details, see the        |
   |                             |           |                       | descriptions in the APIs of |
   |                             |           |                       | forwarding policies and     |
   |                             |           |                       | forwarding rules.           |
   |                             |           |                       |                             |
   |                             |           |                       | This parameter is           |
   |                             |           |                       | unsupported. Please do not  |
   |                             |           |                       | use it.                     |
   +-----------------------------+-----------+-----------------------+-----------------------------+

.. _dlu_ih:
.. table:: **Table 5** ListenerInsertHeaders

   +----------------------+-----------+---------+-----------------------------+
   | Parameter            | Mandatory | Type    | Description                 |
   +======================+===========+=========+=============================+
   | X-Forwarded-ELB-IP   | No        | Boolean | Specifies whether to        |
   |                      |           |         | transparently transmit the  |
   |                      |           |         | load balancer EIP to        |
   |                      |           |         | backend servers. If         |
   |                      |           |         | **X-Forwarded-ELB-IP** is   |
   |                      |           |         | set to **true**, the load   |
   |                      |           |         | balancer EIP will be stored |
   |                      |           |         | in the HTTP header and      |
   |                      |           |         | passed to backend servers.  |
   |                      |           |         |                             |
   |                      |           |         | Default: **false**          |
   +----------------------+-----------+---------+-----------------------------+
   | X-Forwarded-Port     | No        | Boolean | Specifies whether to        |
   |                      |           |         | transparently transmit the  |
   |                      |           |         | listening port of the load  |
   |                      |           |         | balancer to backend         |
   |                      |           |         | servers. If                 |
   |                      |           |         | **X-Forwarded-Port** is set |
   |                      |           |         | to **true**, the listening  |
   |                      |           |         | port of the load balancer   |
   |                      |           |         | will be stored in the HTTP  |
   |                      |           |         | header and passed to        |
   |                      |           |         | backend servers.            |
   |                      |           |         |                             |
   |                      |           |         | Default: **false**          |
   +----------------------+-----------+---------+-----------------------------+
   | X-Forwarded-For-Port | No        | Boolean | Specifies whether to        |
   |                      |           |         | transparently transmit the  |
   |                      |           |         | source port of the client   |
   |                      |           |         | to backend servers. If      |
   |                      |           |         | **X-Forwarded-For-Port** is |
   |                      |           |         | set to **true**, the source |
   |                      |           |         | port of the client will be  |
   |                      |           |         | stored in the HTTP header   |
   |                      |           |         | and passed to backend       |
   |                      |           |         | servers.                    |
   |                      |           |         |                             |
   |                      |           |         | Default: **false**          |
   +----------------------+-----------+---------+-----------------------------+
   | X-Forwarded-Host     | Yes       | Boolean | Specifies whether to        |
   |                      |           |         | rewrite the                 |
   |                      |           |         | **X-Forwarded-Host**        |
   |                      |           |         | header. If                  |
   |                      |           |         | **X-Forwarded-Host** is set |
   |                      |           |         | to **true**,                |
   |                      |           |         | **X-Forwarded-Host** in the |
   |                      |           |         | request header from the     |
   |                      |           |         | clients can be set to       |
   |                      |           |         | **Host** in the request     |
   |                      |           |         | header sent from the load   |
   |                      |           |         | balancer to backend         |
   |                      |           |         | servers.                    |
   |                      |           |         |                             |
   |                      |           |         | Default: **true**           |
   +----------------------+-----------+---------+-----------------------------+

.. _dlu_igo:
.. table:: **Table 6** UpdateListenerIpGroupOption

   +----------------+-----------+---------+-----------------------------+
   | Parameter      | Mandatory | Type    | Description                 |
   +================+===========+=========+=============================+
   | ipgroup_id     | No        | String  | Specifies the ID of the IP  |
   |                |           |         | address group associated    |
   |                |           |         | with the listener.          |
   |                |           |         |                             |
   |                |           |         | -  If **ip_list** is set to |
   |                |           |         |    **[]** and **type** to   |
   |                |           |         |    **whitelist**, no IP     |
   |                |           |         |    addresses are allowed to |
   |                |           |         |    access the listener.     |
   |                |           |         |                             |
   |                |           |         | -  If **ip_list** is set to |
   |                |           |         |    **[]** and **type** to   |
   |                |           |         |    **blacklist**, any IP    |
   |                |           |         |    address is allowed to    |
   |                |           |         |    access the listener.     |
   |                |           |         |                             |
   |                |           |         | -  The specified IP address |
   |                |           |         |    group must exist and     |
   |                |           |         |    this parameter cannot be |
   |                |           |         |    set to **null**.         |
   |                |           |         |                             |
   |                |           |         | IP address groups are not   |
   |                |           |         | supported for now.          |
   +----------------+-----------+---------+-----------------------------+
   | enable_ipgroup | No        | Boolean | Specifies whether access    |
   |                |           |         | control is enabled.         |
   |                |           |         |                             |
   |                |           |         | -  **true**: Access control |
   |                |           |         |    is enabled.              |
   |                |           |         |                             |
   |                |           |         | -  **false**: Access        |
   |                |           |         |    control is disabled.     |
   |                |           |         |                             |
   |                |           |         | A listener with access      |
   |                |           |         | control enabled can be      |
   |                |           |         | directly deleted.           |
   +----------------+-----------+---------+-----------------------------+
   | type           | No        | String  | Specifies how access to the |
   |                |           |         | listener is controlled.     |
   |                |           |         |                             |
   |                |           |         | -  **white**: A whitelist   |
   |                |           |         |    is configured. Only IP   |
   |                |           |         |    addresses in the         |
   |                |           |         |    whitelist can access the |
   |                |           |         |    listener.                |
   |                |           |         |                             |
   |                |           |         | -  **black**: A blacklist   |
   |                |           |         |    is configured. IP        |
   |                |           |         |    addresses in the         |
   |                |           |         |    blacklist are not        |
   |                |           |         |    allowed to access the    |
   |                |           |         |    listener.                |
   +----------------+-----------+---------+-----------------------------+

Response Parameters
^^^^^^^^^^^^^^^^^^^

**Status code: 200**

.. table:: **Table 7** Response body parameters

   +------------+----------------------+----------------------------------------+
   | Parameter  | Type                 | Description                            |
   +============+======================+========================================+
   | request_id | String               | Specifies the request ID. The value is |
   |            |                      | automatically generated.               |
   +------------+----------------------+----------------------------------------+
   | listener   | :ref:`dlu_rl` object | Specifies the listener.                |
   +------------+----------------------+----------------------------------------+

.. _dlu_rl:
.. table:: **Table 8** Listener

   +------------------------------+----------------------------------+---------------------------------------+
   | Parameter                    | Type                             | Description                           |
   +==============================+==================================+=======================================+
   | admin_state_up               | Boolean                          | Specifies the administrative status   |
   |                              |                                  | of the listener. And the value can    |
   |                              |                                  | only be **true**.                     |
   |                              |                                  |                                       |
   |                              |                                  | This parameter is unsupported. Please |
   |                              |                                  | do not use it.                        |
   |                              |                                  |                                       |
   |                              |                                  | Default: **true**                     |
   +------------------------------+----------------------------------+---------------------------------------+
   | client_ca_tls_container_ref  | String                           | Specifies the ID of the CA            |
   |                              |                                  | certificate used by the listener.     |
   +------------------------------+----------------------------------+---------------------------------------+
   | connection_limit             | Integer                          | Specifies the maximum number of       |
   |                              |                                  | connections. The default value is     |
   |                              |                                  | **-1**.                               |
   |                              |                                  |                                       |
   |                              |                                  | This parameter is unsupported. Please |
   |                              |                                  | do not use it.                        |
   +------------------------------+----------------------------------+---------------------------------------+
   | created_at                   | String                           | Specifies the time when the listener  |
   |                              |                                  | was created.                          |
   +------------------------------+----------------------------------+---------------------------------------+
   | default_pool_id              | String                           | Specifies the ID of the default       |
   |                              |                                  | backend server group. If there is no  |
   |                              |                                  | matched forwarding policy, requests   |
   |                              |                                  | are forwarded to the default backend  |
   |                              |                                  | server.                               |
   +------------------------------+----------------------------------+---------------------------------------+
   | default_tls_container_ref    | String                           | Specifies the ID of the server        |
   |                              |                                  | certificate used by the listener.     |
   +------------------------------+----------------------------------+---------------------------------------+
   | description                  | String                           | Provides supplementary information    |
   |                              |                                  | about the listener.                   |
   +------------------------------+----------------------------------+---------------------------------------+
   | http2_enable                 | Boolean                          | Specifies whether to use HTTP/2. This |
   |                              |                                  | parameter is available only for HTTPS |
   |                              |                                  | listeners. If you configure this      |
   |                              |                                  | parameter for other types of          |
   |                              |                                  | listeners, it will not take effect.   |
   |                              |                                  |                                       |
   |                              |                                  | Enable HTTP/2 if you want the clients |
   |                              |                                  | to use HTTP/2 to communicate with the |
   |                              |                                  | load balancer. However, connections   |
   |                              |                                  | between the load balancer and backend |
   |                              |                                  | servers use HTTP/1.x by default.      |
   |                              |                                  |                                       |
   |                              |                                  | Default: **true**                     |
   +------------------------------+----------------------------------+---------------------------------------+
   | id                           | String                           | Specifies the listener ID.            |
   +------------------------------+----------------------------------+---------------------------------------+
   | insert_headers               | :ref:`dlu_rih` object            | Specifies the HTTP header fields.     |
   +------------------------------+----------------------------------+---------------------------------------+
   | loadbalancers                | Array of :ref:`dlu_lbr` objects  | Specifies the ID of the load balancer |
   |                              |                                  | that the listener is added to.        |
   +------------------------------+----------------------------------+---------------------------------------+
   | name                         | String                           | Specifies the listener name.          |
   +------------------------------+----------------------------------+---------------------------------------+
   | project_id                   | String                           | Specifies the ID of the project where |
   |                              |                                  | the listener is used.                 |
   +------------------------------+----------------------------------+---------------------------------------+
   | protocol                     | String                           | Specifies the protocol used by the    |
   |                              |                                  | listener.                             |
   +------------------------------+----------------------------------+---------------------------------------+
   | protocol_port                | Integer                          | Specifies the port used by the        |
   |                              |                                  | listener.                             |
   |                              |                                  |                                       |
   |                              |                                  | Minimum: **1**                        |
   |                              |                                  |                                       |
   |                              |                                  | Maximum: **65535**                    |
   +------------------------------+----------------------------------+---------------------------------------+
   | sni_container_refs           | Array of strings                 | Lists the IDs of SNI certificates     |
   |                              |                                  | (server certificates with domain      |
   |                              |                                  | names) used by the listener.          |
   |                              |                                  |                                       |
   |                              |                                  | Each SNI certificate can have up to   |
   |                              |                                  | 30 domain names, and each domain name |
   |                              |                                  | in the SNI certificate must be        |
   |                              |                                  | unique.                               |
   |                              |                                  |                                       |
   |                              |                                  | This parameter will be ignored and an |
   |                              |                                  | empty array will be returned if the   |
   |                              |                                  | listener's protocol is not HTTPS.     |
   +------------------------------+----------------------------------+---------------------------------------+
   | tags                         | Array of :ref:`dlu_rtag` objects | Lists the tags.                       |
   +------------------------------+----------------------------------+---------------------------------------+
   | updated_at                   | String                           | Specifies the time when the listener  |
   |                              |                                  | was updated.                          |
   +------------------------------+----------------------------------+---------------------------------------+
   | tls_ciphers_policy           | String                           | Specifies the security policy used by |
   |                              |                                  | the listener. This parameter is       |
   |                              |                                  | available only for HTTPS listeners.   |
   |                              |                                  |                                       |
   |                              |                                  | The value can be **tls-1-0**,         |
   |                              |                                  | **tls-1-1**, **tls-1-2**, or          |
   |                              |                                  | **tls-1-2-strict**, and the default   |
   |                              |                                  | value is **tls-1-0**.                 |
   +------------------------------+----------------------------------+---------------------------------------+
   | enable_member_retry          | Boolean                          | Specifies whether to enable health    |
   |                              |                                  | check retries for backend servers.    |
   |                              |                                  | This parameter is available only for  |
   |                              |                                  | HTTP and HTTPS listeners.             |
   +------------------------------+----------------------------------+---------------------------------------+
   | keepalive_timeout            | Integer                          | Specifies the idle timeout duration,  |
   |                              |                                  | in seconds.                           |
   |                              |                                  |                                       |
   |                              |                                  | -  For TCP listeners, the value       |
   |                              |                                  |    ranges from **10** to **4000**,    |
   |                              |                                  |    and the default value is **300**.  |
   |                              |                                  |                                       |
   |                              |                                  | -  For HTTP and HTTPS listeners, the  |
   |                              |                                  |    value ranges from **0** to         |
   |                              |                                  |    **4000**, and the default value is |
   |                              |                                  |    **60**.                            |
   |                              |                                  |                                       |
   |                              |                                  | -  For UDP listeners, this parameter  |
   |                              |                                  |    does not take effect.              |
   +------------------------------+----------------------------------+---------------------------------------+
   | client_timeout               | Integer                          | Specifies the timeout duration for    |
   |                              |                                  | waiting for a request from a client,  |
   |                              |                                  | in seconds.                           |
   |                              |                                  |                                       |
   |                              |                                  | This parameter is available only for  |
   |                              |                                  | HTTP and HTTPS listeners. The value   |
   |                              |                                  | ranges from **1** to **300**, and the |
   |                              |                                  | default value is **60**.              |
   +------------------------------+----------------------------------+---------------------------------------+
   | member_timeout               | Integer                          | Specifies the timeout duration for    |
   |                              |                                  | waiting for a request from a backend  |
   |                              |                                  | server, in seconds.                   |
   |                              |                                  |                                       |
   |                              |                                  | This parameter is available only for  |
   |                              |                                  | HTTP and HTTPS listeners. The value   |
   |                              |                                  | ranges from **1** to **300**, and the |
   |                              |                                  | default value is **60**.              |
   +------------------------------+----------------------------------+---------------------------------------+
   | ipgroup                      | :ref:`dlu_rig` object            | Specifies the IP address group        |
   |                              |                                  | associated with the listener.         |
   |                              |                                  |                                       |
   |                              |                                  | This parameter is unsupported. Please |
   |                              |                                  | do not use it.                        |
   +------------------------------+----------------------------------+---------------------------------------+
   | transparent_client_ip_enable | Boolean                          | Specifies whether to pass source IP   |
   |                              |                                  | addresses of the clients to backend   |
   |                              |                                  | servers.                              |
   |                              |                                  |                                       |
   |                              |                                  | Shared load balancers: The value can  |
   |                              |                                  | be **true** or **false**, and the     |
   |                              |                                  | default value is **false** for TCP    |
   |                              |                                  | and UDP listeners. The value can only |
   |                              |                                  | be **true** for HTTP and HTTPS        |
   |                              |                                  | listeners. If this parameter is not   |
   |                              |                                  | passed, the default value is          |
   |                              |                                  | **true**.                             |
   |                              |                                  |                                       |
   |                              |                                  | Dedicated load balancers: The value   |
   |                              |                                  | can only be **true** for all types of |
   |                              |                                  | listeners. If this parameter is not   |
   |                              |                                  | passed, the default value is          |
   |                              |                                  | **true**.                             |
   +------------------------------+----------------------------------+---------------------------------------+
   | enhance_l7policy_enable      | Boolean                          | Specifies whether to enable advanced  |
   |                              |                                  | forwarding. The value can be **true** |
   |                              |                                  | or **false** (default).               |
   |                              |                                  |                                       |
   |                              |                                  | -  **true** indicates that advanced   |
   |                              |                                  |    forwarding will be enabled.        |
   |                              |                                  |                                       |
   |                              |                                  | -  **false** indicates that advanced  |
   |                              |                                  |    forwarding will not be enabled.    |
   |                              |                                  |                                       |
   |                              |                                  | The following parameters will be      |
   |                              |                                  | available only when advanced          |
   |                              |                                  | forwarding is enabled:                |
   |                              |                                  |                                       |
   |                              |                                  | -  **redirect_url_config**            |
   |                              |                                  |                                       |
   |                              |                                  | -  **fixed_response_config**          |
   |                              |                                  |                                       |
   |                              |                                  | -  **priority**                       |
   |                              |                                  |                                       |
   |                              |                                  | -  **conditions**                     |
   |                              |                                  |                                       |
   |                              |                                  | For details, see the descriptions in  |
   |                              |                                  | the APIs of forwarding policies and   |
   |                              |                                  | forwarding rules.                     |
   |                              |                                  |                                       |
   |                              |                                  | This parameter is unsupported. Please |
   |                              |                                  | do not use it.                        |
   +------------------------------+----------------------------------+---------------------------------------+

.. _dlu_rih:
.. table:: **Table 9** ListenerInsertHeaders

   +----------------------+---------+---------------------------------------+
   | Parameter            | Type    | Description                           |
   +======================+=========+=======================================+
   | X-Forwarded-ELB-IP   | Boolean | Specifies whether to transparently    |
   |                      |         | transmit the load balancer EIP to     |
   |                      |         | backend servers. If                   |
   |                      |         | **X-Forwarded-ELB-IP** is set to      |
   |                      |         | **true**, the load balancer EIP will  |
   |                      |         | be stored in the HTTP header and      |
   |                      |         | passed to backend servers.            |
   |                      |         |                                       |
   |                      |         | Default: **false**                    |
   +----------------------+---------+---------------------------------------+
   | X-Forwarded-Port     | Boolean | Specifies whether to transparently    |
   |                      |         | transmit the listening port of the    |
   |                      |         | load balancer to backend servers. If  |
   |                      |         | **X-Forwarded-Port** is set to        |
   |                      |         | **true**, the listening port of the   |
   |                      |         | load balancer will be stored in the   |
   |                      |         | HTTP header and passed to backend     |
   |                      |         | servers.                              |
   |                      |         |                                       |
   |                      |         | Default: **false**                    |
   +----------------------+---------+---------------------------------------+
   | X-Forwarded-For-Port | Boolean | Specifies whether to transparently    |
   |                      |         | transmit the source port of the       |
   |                      |         | client to backend servers. If         |
   |                      |         | **X-Forwarded-For-Port** is set to    |
   |                      |         | **true**, the source port of the      |
   |                      |         | client will be stored in the HTTP     |
   |                      |         | header and passed to backend servers. |
   |                      |         |                                       |
   |                      |         | Default: **false**                    |
   +----------------------+---------+---------------------------------------+
   | X-Forwarded-Host     | Boolean | Specifies whether to rewrite the      |
   |                      |         | **X-Forwarded-Host** header. If       |
   |                      |         | **X-Forwarded-Host** is set to        |
   |                      |         | **true**, **X-Forwarded-Host** in the |
   |                      |         | request header from the clients can   |
   |                      |         | be set to **Host** in the request     |
   |                      |         | header sent from the load balancer to |
   |                      |         | backend servers.                      |
   |                      |         |                                       |
   |                      |         | Default: **true**                     |
   +----------------------+---------+---------------------------------------+

.. _dlu_lbr:
.. table:: **Table 10** LoadBalancerRef

   ========= ====== ===============================
   Parameter Type   Description
   ========= ====== ===============================
   id        String Specifies the load balancer ID.
   ========= ====== ===============================

.. _dlu_rtag:
.. table:: **Table 11** Tag

   ========= ====== ========================
   Parameter Type   Description
   ========= ====== ========================
   key       String Specifies the tag key.
   value     String Specifies the tag value.
   ========= ====== ========================

.. _dlu_rig:
.. table:: **Table 12** ListenerIpGroup

   +----------------+---------+---------------------------------------+
   | Parameter      | Type    | Description                           |
   +================+=========+=======================================+
   | ipgroup_id     | String  | Specifies the ID of the IP address    |
   |                |         | group associated with the listener.   |
   |                |         |                                       |
   |                |         | -  If **ip_list** is set to **[]**    |
   |                |         |    and **type** to **whitelist**, no  |
   |                |         |    IP addresses are allowed to access |
   |                |         |    the listener.                      |
   |                |         |                                       |
   |                |         | -  If **ip_list** is set to **[]**    |
   |                |         |    and **type** to **blacklist**, any |
   |                |         |    IP address is allowed to access    |
   |                |         |    the listener.                      |
   |                |         |                                       |
   |                |         | -  The specified IP address group     |
   |                |         |    must exist and this parameter      |
   |                |         |    cannot be set to **null**.         |
   +----------------+---------+---------------------------------------+
   | enable_ipgroup | Boolean | Specifies whether to enable access    |
   |                |         | control.                              |
   |                |         |                                       |
   |                |         | -  **true**: Access control is        |
   |                |         |    enabled.                           |
   |                |         |                                       |
   |                |         | -  **false**: Access control is       |
   |                |         |    disabled.                          |
   |                |         |                                       |
   |                |         | A listener with access control        |
   |                |         | enabled can be directly deleted.      |
   +----------------+---------+---------------------------------------+
   | type           | String  | Specifies how access to the listener  |
   |                |         | is controlled.                        |
   |                |         |                                       |
   |                |         | -  **white**: A whitelist is          |
   |                |         |    configured. Only IP addresses in   |
   |                |         |    the whitelist can access the       |
   |                |         |    listener.                          |
   |                |         |                                       |
   |                |         | -  **black**: A blacklist is          |
   |                |         |    configured. IP addresses in the    |
   |                |         |    blacklist are not allowed to       |
   |                |         |    access the listener.               |
   +----------------+---------+---------------------------------------+

Example Requests
^^^^^^^^^^^^^^^^

.. code::

   PUT

   https://{elb_endpoint}/v3/99a3fff0d03c428eac3678da6a7d0f24/elb/listeners/0b11747a-b139-492f-9692-2df0b1c87193

   {
     "listener" : {
       "description" : "My listener update.",
       "name" : "listener-1",
       "http2_enable" : true
     }
   }

Example Responses
^^^^^^^^^^^^^^^^^

**Status code: 200**

Successful request.

.. code::

   {
     "listener" : {
       "id" : "e2baad06-8095-4159-a14e-d1f0137bac06",
       "name" : "listener-1",
       "protocol_port" : 77,
       "protocol" : "HTTP",
       "description" : "My listener update.",
       "admin_state_up" : true,
       "loadbalancers" : [ {
         "id" : "c285bc7b-56d5-43bd-9589-075ee0a5c777"
       } ],
       "project_id" : "060576782980d5762f9ec014dd2f1148",
       "sni_container_refs" : [ ],
       "connection_limit" : -1,
       "default_pool_id" : "61609d20-5230-4b72-8274-46212bbf317c",
       "tags" : [ ],
       "created_at" : "2020-07-28T11:35:21Z",
       "updated_at" : "2020-07-28T11:35:21Z",
       "http2_enable" : true,
       "insert_headers" : {
         "X-Forwarded-ELB-IP" : false,
         "X-Forwarded-Host" : true,
         "X-Forwarded-For-Port" : false,
         "X-Forwarded-Port" : false
       },
       "member_timeout" : 60,
       "client_timeout" : 60,
       "keepalive_timeout" : 60,
       "enable_member_retry" : true,
       "transparent_client_ip_enable" : true,
       "enhance_l7policy_enable" : false
     },
     "request_id" : "619dc40f7ec73c0f13b5b5127904b71e"
   }

Status Codes
^^^^^^^^^^^^

=========== ===================
Status Code Description
=========== ===================
200         Successful request.
=========== ===================

Error Codes
^^^^^^^^^^^

See :ref:`dsc`.

Deleting a Listener
===================

Function
^^^^^^^^

This API is used to delete a listener.

Constraints
^^^^^^^^^^^

Before you delete a listener, delete the associated backend server group or
disassociate the backend server group from the listener, and then delete all
forwarding policies.

URI
^^^

DELETE /v3/{project_id}/elb/listeners/{listener_id}

.. table:: **Table 1** Path parameters

   =========== ========= ====== ==========================
   Parameter   Mandatory Type   Description
   =========== ========= ====== ==========================
   project_id  Yes       String Specifies the project ID.
   listener_id Yes       String Specifies the listener ID.
   =========== ========= ====== ==========================

Request Parameters
^^^^^^^^^^^^^^^^^^

.. table:: **Table 2** Request header parameters

   ============ ========= ====== ================================================
   Parameter    Mandatory Type   Description
   ============ ========= ====== ================================================
   X-Auth-Token Yes       String Specifies the token used for IAM authentication.
   ============ ========= ====== ================================================

Response Parameters
^^^^^^^^^^^^^^^^^^^

None

Example Requests
^^^^^^^^^^^^^^^^

.. code::

   DELETE
   https://{elb_endpoint}/v3/{project_id}/elb/listeners/{listener_id}

Example Responses
^^^^^^^^^^^^^^^^^

None

Status Codes
^^^^^^^^^^^^

=========== ===================
Status Code Description
=========== ===================
204         Successful request.
=========== ===================

Error Codes
^^^^^^^^^^^

See :ref:`dsc`.

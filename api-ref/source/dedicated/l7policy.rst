=================
Forwarding Policy
=================

Adding a Forwarding Policy
==========================

Function
^^^^^^^^

This API is used to add a forwarding policy.

Constraints
^^^^^^^^^^^

The protocol of the listener to which requests are redirected can only be
HTTPS.

The listener associated with the forwarding policy cannot be any listener added
to other load balancers.

URI
^^^

POST /v3/{project_id}/elb/l7policies

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

   +-----------+-----------+----------------------+----------------------------------+
   | Parameter | Mandatory | Type                 | Description                      |
   +===========+===========+======================+==================================+
   | l7policy  | Yes       | :ref:dl7pc_o` object | Specifies the forwarding policy. |
   +-----------+-----------+----------------------+----------------------------------+

.. _dl7pc_o:
.. table:: **Table 4** CreateL7PolicyOption

   +-----------------------+-----------+------------------+-----------------------------------+
   | Parameter             | Mandatory | Type             | Description                       |
   +=======================+===========+==================+===================================+
   | action                | Yes       | String           | Specifies where requests          |
   |                       |           |                  | will be forwarded. The            |
   |                       |           |                  | value can be one of the           |
   |                       |           |                  | following:                        |
   |                       |           |                  |                                   |
   |                       |           |                  | - **REDIRECT_TO_POOL**:           |
   |                       |           |                  |   Requests will be                |
   |                       |           |                  |   forwarded to another            |
   |                       |           |                  |   backend server group.           |
   |                       |           |                  |                                   |
   |                       |           |                  | - **REDIRECT_TO_LISTENER**:       |
   |                       |           |                  |   Requests will be                |
   |                       |           |                  |   redirected to an HTTPS          |
   |                       |           |                  |   listener.                       |
   |                       |           |                  |                                   |
   |                       |           |                  | **REDIRECT_TO_LISTENER**          |
   |                       |           |                  | has the highest priority.         |
   |                       |           |                  | If requests are to be             |
   |                       |           |                  | redirected to an HTTPS            |
   |                       |           |                  | listener, other forwarding        |
   |                       |           |                  | policies of the listener          |
   |                       |           |                  | will become invalid.              |
   |                       |           |                  |                                   |
   |                       |           |                  | Minimum: **1**                    |
   |                       |           |                  | Maximum: **255**                  |
   +-----------------------+-----------+------------------+-----------------------------------+
   | admin_state_up        | No        | Boolean          | Specifies the                     |
   |                       |           |                  | administrative status of          |
   |                       |           |                  | the forwarding policy. The        |
   |                       |           |                  | default value is **true**.        |
   |                       |           |                  |                                   |
   |                       |           |                  | This parameter is                 |
   |                       |           |                  | unsupported. Please do not        |
   |                       |           |                  | use it.                           |
   +-----------------------+-----------+------------------+-----------------------------------+
   | description           | No        | String           | Provides supplementary            |
   |                       |           |                  | information about the             |
   |                       |           |                  | forwarding policy.                |
   |                       |           |                  |                                   |
   |                       |           |                  | Minimum: **0**                    |
   |                       |           |                  | Maximum: **255**                  |
   +-----------------------+-----------+------------------+-----------------------------------+
   | listener_id           | Yes       | String           | Specifies the ID of the           |
   |                       |           |                  | listener to which the             |
   |                       |           |                  | forwarding policy is added.       |
   |                       |           |                  |                                   |
   |                       |           |                  | - If **action** is set to         |
   |                       |           |                  |   **REDIRECT_TO_POOL**,           |
   |                       |           |                  |   the forwarding policy           |
   |                       |           |                  |   can be added to an HTTP         |
   |                       |           |                  |   or HTTPS listener.              |
   |                       |           |                  |                                   |
   |                       |           |                  | - If **action** is set to         |
   |                       |           |                  |   **REDIRECT_TO_LISTENER**,       |
   |                       |           |                  |   the forwarding policy           |
   |                       |           |                  |   can be added to an HTTP         |
   |                       |           |                  |   listener.                       |
   +-----------------------+-----------+------------------+-----------------------------------+
   | name                  | No        | String           | Specifies the forwarding          |
   |                       |           |                  | policy name.                      |
   |                       |           |                  |                                   |
   |                       |           |                  | Minimum: **0**                    |
   |                       |           |                  | Maximum: **255**                  |
   +-----------------------+-----------+------------------+-----------------------------------+
   | position              | No        | Integer          | Specifies the forwarding          |
   |                       |           |                  | policy priority. The value        |
   |                       |           |                  | cannot be updated.                |
   |                       |           |                  |                                   |
   |                       |           |                  | This parameter is                 |
   |                       |           |                  | unsupported. Please do not        |
   |                       |           |                  | use it.                           |
   |                       |           |                  |                                   |
   |                       |           |                  | Minimum: **1**                    |
   |                       |           |                  | Maximum: **100**                  |
   +-----------------------+-----------+------------------+-----------------------------------+
   | project_id            | No        | String           | Specifies the ID of the           |
   |                       |           |                  | project where the                 |
   |                       |           |                  | forwarding policy is used.        |
   |                       |           |                  |                                   |
   |                       |           |                  | Minimum: **1**                    |
   |                       |           |                  | Maximum: **32**                   |
   +-----------------------+-----------+------------------+-----------------------------------+
   | redirect_listener_id  | No        | String           | Specifies the ID of the           |
   |                       |           |                  | listener to which requests        |
   |                       |           |                  | are redirected. This              |
   |                       |           |                  | parameter is mandatory when       |
   |                       |           |                  | **action** is set to              |
   |                       |           |                  | **REDIRECT_TO_LISTENER**.         |
   |                       |           |                  |                                   |
   |                       |           |                  | For shared load balancers,        |
   |                       |           |                  | this parameter is not             |
   |                       |           |                  | supported. If it is passed,       |
   |                       |           |                  | an error will be returned.        |
   +-----------------------+-----------+------------------+-----------------------------------+
   | redirect_pool_id      | No        | String           | Specifies the ID of the           |
   |                       |           |                  | backend server group that         |
   |                       |           |                  | requests are forwarded to.        |
   |                       |           |                  |                                   |
   |                       |           |                  | This parameter is valid and       |
   |                       |           |                  | mandatory only when               |
   |                       |           |                  | **action** is set to              |
   |                       |           |                  | **REDIRECT_TO_POOL**. The         |
   |                       |           |                  | specified backend server          |
   |                       |           |                  | group cannot be the default       |
   |                       |           |                  | one associated with the           |
   |                       |           |                  | listener, or any backend          |
   |                       |           |                  | server group associated           |
   |                       |           |                  | with the forwarding               |
   |                       |           |                  | policies of other                 |
   |                       |           |                  | listeners.                        |
   |                       |           |                  |                                   |
   |                       |           |                  | This parameter cannot be          |
   |                       |           |                  | specified when **action**         |
   |                       |           |                  | is set to                         |
   |                       |           |                  | **REDIRECT_TO_LISTENER**.         |
   +-----------------------+-----------+------------------+-----------------------------------+
   | redirect_url          | No        | String           | Specifies the URL to which        |
   |                       |           |                  | requests are forwarded.           |
   |                       |           |                  |                                   |
   |                       |           |                  | Format:                           |
   |                       |           |                  | *protocol://host:port/path?query* |
   |                       |           |                  |                                   |
   |                       |           |                  | This parameter is                 |
   |                       |           |                  | unsupported. Please do not        |
   |                       |           |                  | use it.                           |
   |                       |           |                  |                                   |
   |                       |           |                  | Minimum: **1**                    |
   |                       |           |                  | Maximum: **255**                  |
   +-----------------------+-----------+------------------+-----------------------------------+
   | rules                 | No        | Array of         | Lists the forwarding rules        |
   |                       |           | :ref:`dl7pc_ro`  | in the forwarding policy.         |
   |                       |           | objects          |                                   |
   |                       |           |                  | The list can contain a            |
   |                       |           |                  | maximum of 10 forwarding          |
   |                       |           |                  | rules (if **conditions** is       |
   |                       |           |                  | specified, a condition is         |
   |                       |           |                  | considered as a rule).            |
   |                       |           |                  |                                   |
   |                       |           |                  | If **type** is set to             |
   |                       |           |                  | **HOST_NAME**, **PATH**,          |
   |                       |           |                  | **METHOD**, or                    |
   |                       |           |                  | **SOURCE_IP**, only one           |
   |                       |           |                  | forwarding rule can be            |
   |                       |           |                  | created for each type.            |
   |                       |           |                  |                                   |
   |                       |           |                  | The entire list will be           |
   |                       |           |                  | replaced if you update it.        |
   +-----------------------+-----------+------------------+-----------------------------------+
   | priority              | No        | Integer          | Specifies the forwarding          |
   |                       |           |                  | policy priority. This             |
   |                       |           |                  | parameter is available only       |
   |                       |           |                  | for dedicated load                |
   |                       |           |                  | balancers and will take           |
   |                       |           |                  | effect when                       |
   |                       |           |                  | **enhance_l7policy_enable**       |
   |                       |           |                  | is set to **true**. If this       |
   |                       |           |                  | parameter is passed and           |
   |                       |           |                  | **enhance_l7policy_enable**       |
   |                       |           |                  | is set to **false**, an           |
   |                       |           |                  | error will be returned. For       |
   |                       |           |                  | shared load balancers, this       |
   |                       |           |                  | parameter is not supported.       |
   |                       |           |                  | If it is passed, an error         |
   |                       |           |                  | will be returned.                 |
   |                       |           |                  |                                   |
   |                       |           |                  | A smaller value indicates a       |
   |                       |           |                  | higher priority. The value        |
   |                       |           |                  | must be unique for each           |
   |                       |           |                  | forwarding policy of the          |
   |                       |           |                  | same listener.                    |
   |                       |           |                  |                                   |
   |                       |           |                  | If **action** is set to           |
   |                       |           |                  | **REDIRECT_TO_LISTENER**,         |
   |                       |           |                  | the value can only be             |
   |                       |           |                  | **0**, indicating that            |
   |                       |           |                  | **REDIRECT_TO_LISTENER**          |
   |                       |           |                  | has the highest priority.         |
   |                       |           |                  |                                   |
   |                       |           |                  | - If **enhance_l7policy_enable**  |
   |                       |           |                  |   is set to **false**,            |
   |                       |           |                  |   forwarding policies are         |
   |                       |           |                  |   automatically                   |
   |                       |           |                  |   prioritized based on the        |
   |                       |           |                  |   original sorting logic.         |
   |                       |           |                  |   Forwarding policy               |
   |                       |           |                  |   priorities are                  |
   |                       |           |                  |   independent of each             |
   |                       |           |                  |   other regardless of             |
   |                       |           |                  |   domain names. If                |
   |                       |           |                  |   forwarding policies use         |
   |                       |           |                  |   the same domain name,           |
   |                       |           |                  |   their priorities follow         |
   |                       |           |                  |   the order of exact match        |
   |                       |           |                  |   (**EQUAL_TO**), prefix          |
   |                       |           |                  |   match (**STARTS_WITH**),        |
   |                       |           |                  |   and regular expression          |
   |                       |           |                  |   match (**REGEX**). If           |
   |                       |           |                  |   prefix match is used for        |
   |                       |           |                  |   matching, the longer the        |
   |                       |           |                  |   path, the higher the            |
   |                       |           |                  |   priority. If a                  |
   |                       |           |                  |   forwarding policy               |
   |                       |           |                  |   contains only a domain          |
   |                       |           |                  |   name without a path             |
   |                       |           |                  |   specified, the path is          |
   |                       |           |                  |   **/**, and prefix match         |
   |                       |           |                  |   is used by default.             |
   |                       |           |                  |                                   |
   |                       |           |                  | - If **enhance_l7policy_enable**  |
   |                       |           |                  |   is set to **true** and          |
   |                       |           |                  |   this parameter is not           |
   |                       |           |                  |   passed, the priority            |
   |                       |           |                  |   will set to a sum of 1          |
   |                       |           |                  |   and the highest priority        |
   |                       |           |                  |   of existing forwarding          |
   |                       |           |                  |   policy in the same              |
   |                       |           |                  |   listener by default.            |
   |                       |           |                  |   There will be two cases:        |
   |                       |           |                  |   a) If the highest               |
   |                       |           |                  |   priority of existing            |
   |                       |           |                  |   forwarding policies is          |
   |                       |           |                  |   the maximum (10,000),           |
   |                       |           |                  |   the forwarding policy           |
   |                       |           |                  |   will fail to create             |
   |                       |           |                  |   because the final               |
   |                       |           |                  |   priority for creating           |
   |                       |           |                  |   the forwarding policy is        |
   |                       |           |                  |   the sum of 1 and 10,000,        |
   |                       |           |                  |   which exceeds the               |
   |                       |           |                  |   maximum. In this case,          |
   |                       |           |                  |   please specify a value          |
   |                       |           |                  |   or adjust the priorities        |
   |                       |           |                  |   of existing forwarding          |
   |                       |           |                  |   policies. b) If no              |
   |                       |           |                  |   forwarding policies             |
   |                       |           |                  |   exist, the highest              |
   |                       |           |                  |   priority of existing            |
   |                       |           |                  |   forwarding policies will        |
   |                       |           |                  |   set to 1 by default.            |
   |                       |           |                  |                                   |
   |                       |           |                  | This parameter is                 |
   |                       |           |                  | unsupported. Please do not        |
   |                       |           |                  | use it.                           |
   |                       |           |                  |                                   |
   |                       |           |                  | Minimum: **0**                    |
   |                       |           |                  | Maximum: **10000**                |
   +-----------------------+-----------+------------------+-----------------------------------+
   | redirect_url_config   | No        | :ref:`dl7pc_ruc` | Specifies the URL to which        |
   |                       |           | object           | requests are forwarded.           |
   |                       |           |                  |                                   |
   |                       |           |                  | For shared load balancers,        |
   |                       |           |                  | this parameter is not             |
   |                       |           |                  | supported. If it is passed,       |
   |                       |           |                  | an error will be returned.        |
   |                       |           |                  |                                   |
   |                       |           |                  | For dedicated load                |
   |                       |           |                  | balancers, this parameter         |
   |                       |           |                  | will take effect only when        |
   |                       |           |                  | advanced forwarding is            |
   |                       |           |                  | enabled                           |
   |                       |           |                  | (                                 |
   |                       |           |                  | **enhance_l7policy_enable**       |
   |                       |           |                  | is set to **true**). If it        |
   |                       |           |                  | is passed when                    |
   |                       |           |                  | **enhance_l7policy_enable**       |
   |                       |           |                  | is set to **false**, an           |
   |                       |           |                  | error will be returned.           |
   |                       |           |                  |                                   |
   |                       |           |                  | Format:                           |
   |                       |           |                  | *protocol://host:port/path?query* |
   |                       |           |                  |                                   |
   |                       |           |                  | At least one of the four          |
   |                       |           |                  | parameters (**protocol**,         |
   |                       |           |                  | **host**, **port**, and           |
   |                       |           |                  | **path**) must be passed,         |
   |                       |           |                  | or their values cannot be         |
   |                       |           |                  | set to **${xxx}** at the          |
   |                       |           |                  | same time. (**${xxx}**            |
   |                       |           |                  | indicates that the value in       |
   |                       |           |                  | the request will be               |
   |                       |           |                  | inherited. For example,           |
   |                       |           |                  | **${host}** indicates the         |
   |                       |           |                  | host in the URL to be             |
   |                       |           |                  | redirected.)                      |
   |                       |           |                  |                                   |
   |                       |           |                  | The values of **protocol**        |
   |                       |           |                  | and **port** cannot be the        |
   |                       |           |                  | same as those of the              |
   |                       |           |                  | associated listener, and          |
   |                       |           |                  | either **host** or **path**       |
   |                       |           |                  | must be passed or their           |
   |                       |           |                  | values cannot be **${xxx}**       |
   |                       |           |                  | at the same time.                 |
   |                       |           |                  |                                   |
   |                       |           |                  | This parameter is                 |
   |                       |           |                  | unsupported. Please do not        |
   |                       |           |                  | use it.                           |
   +-----------------------+-----------+------------------+-----------------------------------+
   | fixed_response_config | No        | :ref:`dl7pc_frc` | Specifies the configuration       |
   |                       |           | object           | of the page that will be          |
   |                       |           |                  | returned. This parameter          |
   |                       |           |                  | will take effect when             |
   |                       |           |                  | **enhance_l7policy_enable**       |
   |                       |           |                  | is set to **true**. If this       |
   |                       |           |                  | parameter is passed and           |
   |                       |           |                  | **enhance_l7policy_enable**       |
   |                       |           |                  | is set to **false**, an           |
   |                       |           |                  | error will be returned. For       |
   |                       |           |                  | shared load balancers, this       |
   |                       |           |                  | parameter is not supported.       |
   |                       |           |                  | If it is passed, an error         |
   |                       |           |                  | will be returned.                 |
   |                       |           |                  |                                   |
   |                       |           |                  | This parameter is                 |
   |                       |           |                  | unsupported. Please do not        |
   |                       |           |                  | use it.                           |
   +-----------------------+-----------+------------------+-----------------------------------+

.. _dl7pc_ro:
.. table:: **Table 5** CreateL7PolicyRuleOption

   +----------------+-----------+------------------+--------------------------------------+
   | Parameter      | Mandatory | Type             | Description                          |
   +================+===========+==================+======================================+
   | admin_state_up | No        | Boolean          | Specifies the                        |
   |                |           |                  | administrative status of             |
   |                |           |                  | the forwarding rule. The             |
   |                |           |                  | value can be **true** or             |
   |                |           |                  | **false**, and the default           |
   |                |           |                  | value is **true**.                   |
   |                |           |                  |                                      |
   |                |           |                  | This parameter is                    |
   |                |           |                  | unsupported. Please do not           |
   |                |           |                  | use it.                              |
   |                |           |                  |                                      |
   |                |           |                  | Default: **true**                    |
   +----------------+-----------+------------------+--------------------------------------+
   | type           | Yes       | String           | Specifies the match                  |
   |                |           |                  | content. The value can be            |
   |                |           |                  | one of the following:                |
   |                |           |                  |                                      |
   |                |           |                  | - **HOST_NAME**: A domain            |
   |                |           |                  |   name will be used for              |
   |                |           |                  |   matching.                          |
   |                |           |                  |                                      |
   |                |           |                  | - **PATH**: A URL will be            |
   |                |           |                  |   used for matching.                 |
   |                |           |                  |                                      |
   |                |           |                  | If **type** is set to                |
   |                |           |                  | **HOST_NAME**, **PATH**,             |
   |                |           |                  | **METHOD**, or                       |
   |                |           |                  | **SOURCE_IP**, only one              |
   |                |           |                  | forwarding rule can be               |
   |                |           |                  | created for each type.               |
   +----------------+-----------+------------------+--------------------------------------+
   | compare_type   | Yes       | String           | Specifies how requests are           |
   |                |           |                  | matched with the domain              |
   |                |           |                  | name or URL.                         |
   |                |           |                  |                                      |
   |                |           |                  | If **type** is set to                |
   |                |           |                  | **HOST_NAME**, this                  |
   |                |           |                  | parameter can only be set            |
   |                |           |                  | to **EQUAL_TO** (exact               |
   |                |           |                  | match).                              |
   |                |           |                  |                                      |
   |                |           |                  | If **type** is set to                |
   |                |           |                  | **PATH**, this parameter             |
   |                |           |                  | can be set to **REGEX**              |
   |                |           |                  | (regular expression match),          |
   |                |           |                  | **STARTS_WITH** (prefix              |
   |                |           |                  | match), or **EQUAL_TO**              |
   |                |           |                  | (exact match).                       |
   +----------------+-----------+------------------+--------------------------------------+
   | invert         | No        | Boolean          | Specifies whether reverse            |
   |                |           |                  | matching is supported. The           |
   |                |           |                  | value can be **true** or             |
   |                |           |                  | **false**, and the default           |
   |                |           |                  | value is **false**.                  |
   |                |           |                  |                                      |
   |                |           |                  | This parameter is                    |
   |                |           |                  | unsupported. Please do not           |
   |                |           |                  | use it.                              |
   |                |           |                  |                                      |
   |                |           |                  | Default: **false**                   |
   +----------------+-----------+------------------+--------------------------------------+
   | key            | No        | String           | Specifies the key of the             |
   |                |           |                  | match item. For example, if          |
   |                |           |                  | an HTTP header is used for           |
   |                |           |                  | matching, **key** is the             |
   |                |           |                  | name of the HTTP header              |
   |                |           |                  | parameter.                           |
   |                |           |                  |                                      |
   |                |           |                  | This parameter is                    |
   |                |           |                  | unsupported. Please do not           |
   |                |           |                  | use it.                              |
   |                |           |                  |                                      |
   |                |           |                  | Minimum: **1**                       |
   |                |           |                  | Maximum: **255**                     |
   +----------------+-----------+------------------+--------------------------------------+
   | value          | Yes       | String           | Specifies the value of the           |
   |                |           |                  | match item. For example, if          |
   |                |           |                  | a domain name is used for            |
   |                |           |                  | matching, **value** is the           |
   |                |           |                  | domain name.                         |
   |                |           |                  |                                      |
   |                |           |                  | - If **type** is set to              |
   |                |           |                  |   **HOST_NAME**, the value           |
   |                |           |                  |   can contain letters,               |
   |                |           |                  |   digits, hyphens (-), and           |
   |                |           |                  |   periods (.) and must               |
   |                |           |                  |   start with a letter or             |
   |                |           |                  |   digit. If you want to              |
   |                |           |                  |   use a wildcard domain              |
   |                |           |                  |   name, enter an asterisk            |
   |                |           |                  |   (*) as the leftmost                |
   |                |           |                  |   label of the domain                |
   |                |           |                  |   name.                              |
   |                |           |                  |                                      |
   |                |           |                  | - If **type** is set to              |
   |                |           |                  |   **PATH** and                       |
   |                |           |                  |   **compare_type** to                |
   |                |           |                  |   **STARTS_WITH** or                 |
   |                |           |                  |   **EQUAL_TO**, the value            |
   |                |           |                  |   must start with a slash            |
   |                |           |                  |   (/) and can contain only           |
   |                |           |                  |   letters, digits, and               |
   |                |           |                  |   special characters                 |
   |                |           |                  |   \ _~';@^-%#&$.*+?,=!:&vert;/()[]{} |
   |                |           |                  |                                      |
   |                |           |                  | Minimum: **1**                       |
   |                |           |                  | Maximum: **128**                     |
   +----------------+-----------+------------------+--------------------------------------+
   | conditions     | No        | Array of         | Specifies the conditions             |
   |                |           | :ref:`dl7pc_crc` | contained in a forwarding            |
   |                |           | objects          | rule. This parameter will            |
   |                |           |                  | take effect when                     |
   |                |           |                  | **enhance_l7policy_enable**          |
   |                |           |                  | is set to **true**.                  |
   |                |           |                  |                                      |
   |                |           |                  | If **conditions** is                 |
   |                |           |                  | specified, **key** and               |
   |                |           |                  | **value** will not take              |
   |                |           |                  | effect, and the value of             |
   |                |           |                  | this parameter will contain          |
   |                |           |                  | all conditions configured            |
   |                |           |                  | for the forwarding rule.             |
   |                |           |                  | The keys in the list must            |
   |                |           |                  | be the same, whereas each            |
   |                |           |                  | value must be unique.                |
   |                |           |                  |                                      |
   |                |           |                  | This parameter is                    |
   |                |           |                  | unsupported. Please do not           |
   |                |           |                  | use it.                              |
   +----------------+-----------+------------------+--------------------------------------+

.. _dl7pc_crc:
.. table:: **Table 6** CreateRuleCondition

   +-----------+-----------+--------+-------------------------------------+
   | Parameter | Mandatory | Type   | Description                         |
   +===========+===========+========+=====================================+
   | key       | No        | String | Specifies the key of match          |
   |           |           |        | item. This parameter is             |
   |           |           |        | left blank.                         |
   |           |           |        |                                     |
   |           |           |        | Minimum: **1**                      |
   |           |           |        | Maximum: **128**                    |
   +-----------+-----------+--------+-------------------------------------+
   | value     | Yes       | String | Specifies the value of the          |
   |           |           |        | match item.                         |
   |           |           |        |                                     |
   |           |           |        | - If **type** is set to             |
   |           |           |        |   **HOST_NAME**, **key**            |
   |           |           |        |   is left blank, and                |
   |           |           |        |   **value** indicates the           |
   |           |           |        |   domain name, which can            |
   |           |           |        |   contain 1 to 128                  |
   |           |           |        |   characters, including             |
   |           |           |        |   letters, digits, hyphens          |
   |           |           |        |   (-), periods (.), and             |
   |           |           |        |   asterisks (*), and must           |
   |           |           |        |   start with a letter,              |
   |           |           |        |   digit, or asterisk (*).           |
   |           |           |        |   If you want to use a              |
   |           |           |        |   wildcard domain name,             |
   |           |           |        |   enter an asterisk (*) as          |
   |           |           |        |   the leftmost label of             |
   |           |           |        |   the domain name.                  |
   |           |           |        |                                     |
   |           |           |        | - If **type** is set to             |
   |           |           |        |   **PATH**, **key** is              |
   |           |           |        |   left blank, and                   |
   |           |           |        |   **value** indicates the           |
   |           |           |        |   request path, which can           |
   |           |           |        |   contain 1 to 128                  |
   |           |           |        |   characters. If                    |
   |           |           |        |   **compare_type** is set           |
   |           |           |        |   to **STARTS_WITH** or             |
   |           |           |        |   **EQUAL_TO** for the              |
   |           |           |        |   forwarding rule, the              |
   |           |           |        |   value must start with a           |
   |           |           |        |   slash (/) and can                 |
   |           |           |        |   contain only letters,             |
   |           |           |        |   digits, and special               |
   |           |           |        |   characters                        |
   |           |           |        |   \_~';@^-%#&$.*+?,=!:&vert;/()[]{} |
   |           |           |        |                                     |
   +-----------+-----------+--------+-------------------------------------+

.. _dl7pc_ruc:
.. table:: **Table 7** CreateRedirectUrlConfig

   +-------------+-----------+--------+-----------------------------+
   | Parameter   | Mandatory | Type   | Description                 |
   +=============+===========+========+=============================+
   | protocol    | No        | String | Specifies the protocol for  |
   |             |           |        | redirection. The default    |
   |             |           |        | value is **${protocol}**,   |
   |             |           |        | indicating that the         |
   |             |           |        | protocol of the request     |
   |             |           |        | will be used.               |
   |             |           |        |                             |
   |             |           |        | Value options:              |
   |             |           |        |                             |
   |             |           |        | -  **HTTP**                 |
   |             |           |        | -  **HTTPS**                |
   |             |           |        | -  **${protocol}**          |
   |             |           |        |                             |
   |             |           |        | Default: **${protocol}**    |
   |             |           |        | Minimum: **1**              |
   |             |           |        | Maximum: **36**             |
   +-------------+-----------+--------+-----------------------------+
   | host        | No        | String | Specifies the host name     |
   |             |           |        | that requests are           |
   |             |           |        | redirected to. The value    |
   |             |           |        | can contain only letters,   |
   |             |           |        | digits, hyphens (-), and    |
   |             |           |        | periods (.) and must start  |
   |             |           |        | with a letter or digit. The |
   |             |           |        | default value is            |
   |             |           |        | **${host}**, indicating     |
   |             |           |        | that the host of the        |
   |             |           |        | request will be used.       |
   |             |           |        |                             |
   |             |           |        | Default: **${host}**        |
   |             |           |        | Minimum: **1**              |
   |             |           |        | Maximum: **128**            |
   +-------------+-----------+--------+-----------------------------+
   | port        | No        | String | Specifies the port that     |
   |             |           |        | requests are redirected to. |
   |             |           |        | The default value is        |
   |             |           |        | **${port}**, indicating     |
   |             |           |        | that the port of the        |
   |             |           |        | request will be used.       |
   |             |           |        |                             |
   |             |           |        | Default: **${port}**        |
   |             |           |        | Minimum: **1**              |
   |             |           |        | Maximum: **16**             |
   +-------------+-----------+--------+-----------------------------+
   | path        | No        | String | Specifies the path that     |
   |             |           |        | requests are redirected to. |
   |             |           |        | The default value is        |
   |             |           |        | **${path}**, indicating     |
   |             |           |        | that the path of the        |
   |             |           |        | request will be used.       |
   |             |           |        |                             |
   |             |           |        | The value can contain only  |
   |             |           |        | letters, digits, and        |
   |             |           |        | special characters \_-';@^- |
   |             |           |        | %#&$.*+?,=!:&vert;/()[]{}   |
   |             |           |        | must start with a slash     |
   |             |           |        | (/).                        |
   |             |           |        |                             |
   |             |           |        | Default: **${path}**        |
   |             |           |        | Minimum: **1**              |
   |             |           |        | Maximum: **128**            |
   +-------------+-----------+--------+-----------------------------+
   | query       | No        | String | Specifies the query string  |
   |             |           |        | set in the URL for          |
   |             |           |        | redirection. The default    |
   |             |           |        | value is **${query}**,      |
   |             |           |        | indicating that the query   |
   |             |           |        | string of the request will  |
   |             |           |        | be used.                    |
   |             |           |        |                             |
   |             |           |        | For example, in the URL     |
   |             |           |        | **https://www.xxx.com:80    |
   |             |           |        | 80/elb?type=loadbalancer**, |
   |             |           |        | **${query}** indicates      |
   |             |           |        | **type=loadbalancer**. If   |
   |             |           |        | this parameter is set to    |
   |             |           |        | **${query}&name=my_name**,  |
   |             |           |        | the URL will be redirected  |
   |             |           |        | to                          |
   |             |           |        | **https://                  |
   |             |           |        | www.xxx.com:8080/elb?type=l |
   |             |           |        | oadbalancer&name=my_name**. |
   |             |           |        |                             |
   |             |           |        | The value is case-sensitive |
   |             |           |        | and can contain only        |
   |             |           |        | letters, digits, and        |
   |             |           |        | special characters          |
   |             |           |        | !$&'()*+,-./:;=?@^_\`       |
   |             |           |        |                             |
   |             |           |        | Default: **${query}**       |
   |             |           |        | Minimum: **0**              |
   |             |           |        | Maximum: **128**            |
   +-------------+-----------+--------+-----------------------------+
   | status_code | Yes       | String | Specifies the status code   |
   |             |           |        | returned after the requests |
   |             |           |        | are redirected.             |
   |             |           |        |                             |
   |             |           |        | Value options:              |
   |             |           |        |                             |
   |             |           |        | -  **301**                  |
   |             |           |        | -  **302**                  |
   |             |           |        | -  **303**                  |
   |             |           |        | -  **307**                  |
   |             |           |        | -  **308**                  |
   |             |           |        |                             |
   |             |           |        | Minimum: **1**              |
   |             |           |        | Maximum: **16**             |
   +-------------+-----------+--------+-----------------------------+

.. _dl7pc_frc:
.. table:: **Table 8** CreateFixtedResponseConfig

   +--------------+-----------+--------+------------------------------+
   | Parameter    | Mandatory | Type   | Description                  |
   +==============+===========+========+==============================+
   | status_code  | Yes       | String | Specifies the fixed HTTP     |
   |              |           |        | status code configured in    |
   |              |           |        | the forwarding rule. The     |
   |              |           |        | value can be any integer in  |
   |              |           |        | the range of 200–299,        |
   |              |           |        | 400–499, or 500–599.         |
   |              |           |        |                              |
   |              |           |        | Minimum: **1**               |
   |              |           |        | Maximum: **16**              |
   +--------------+-----------+--------+------------------------------+
   | content_type | No        | String | Specifies the format of the  |
   |              |           |        | response body.               |
   |              |           |        |                              |
   |              |           |        | Value options:               |
   |              |           |        |                              |
   |              |           |        | - **text/plain**             |
   |              |           |        | - **text/css**               |
   |              |           |        | - **text/html**              |
   |              |           |        | - **application/javascript** |
   |              |           |        | - **application/json**       |
   |              |           |        |                              |
   |              |           |        | Minimum: **0**               |
   |              |           |        | Maximum: **32**              |
   +--------------+-----------+--------+------------------------------+
   | message_body | No        | String | Specifies the content of     |
   |              |           |        | the response body.           |
   |              |           |        |                              |
   |              |           |        | Minimum: **0**               |
   |              |           |        |                              |
   |              |           |        | Maximum: **1024**            |
   +--------------+-----------+--------+------------------------------+

Response Parameters
^^^^^^^^^^^^^^^^^^^

**Status code: 201**

.. table:: **Table 9** Response body parameters

   +------------+-----------------------+----------------------------------------+
   | Parameter  | Type                  | Description                            |
   +============+=======================+========================================+
   | request_id | String                | Specifies the request ID. The value is |
   |            |                       | automatically generated.               |
   +------------+-----------------------+----------------------------------------+
   | l7policy   | :ref:`dl7pc_p` object | Specifies the forwarding policy.       |
   +------------+-----------------------+----------------------------------------+

.. _dl7pc_p:
.. table:: **Table 10** L7Policy

   +-----------------------+--------------------------+---------------------------------------+
   | Parameter             | Type                     | Description                           |
   +=======================+==========================+=======================================+
   | action                | String                   | Specifies where requests will be      |
   |                       |                          | forwarded. The value can be one of    |
   |                       |                          | the following:                        |
   |                       |                          |                                       |
   |                       |                          | - **REDIRECT_TO_POOL**: Requests      |
   |                       |                          |   will be forwarded to another        |
   |                       |                          |   backend server group.               |
   |                       |                          |                                       |
   |                       |                          | - **REDIRECT_TO_LISTENER**: Requests  |
   |                       |                          |   will be redirected to an HTTPS      |
   |                       |                          |   listener.                           |
   |                       |                          |                                       |
   |                       |                          | **REDIRECT_TO_LISTENER** has the      |
   |                       |                          | highest priority. If requests are to  |
   |                       |                          | be redirected to an HTTPS listener,   |
   |                       |                          | other forwarding policies of the      |
   |                       |                          | listener will become invalid.         |
   +-----------------------+--------------------------+---------------------------------------+
   | admin_state_up        | Boolean                  | Specifies the administrative status   |
   |                       |                          | of the forwarding policy. The default |
   |                       |                          | value is **true**.                    |
   |                       |                          |                                       |
   |                       |                          | This parameter is unsupported. Please |
   |                       |                          | do not use it.                        |
   |                       |                          |                                       |
   |                       |                          | Default: **true**                     |
   +-----------------------+--------------------------+---------------------------------------+
   | description           | String                   | Provides supplementary information    |
   |                       |                          | about the forwarding policy.          |
   +-----------------------+--------------------------+---------------------------------------+
   | id                    | String                   | Specifies the forwarding policy ID.   |
   +-----------------------+--------------------------+---------------------------------------+
   | listener_id           | String                   | Specifies the ID of the listener to   |
   |                       |                          | which the forwarding policy is added. |
   |                       |                          |                                       |
   |                       |                          | - If **action** is set to             |
   |                       |                          |   **REDIRECT_TO_POOL**, the           |
   |                       |                          |   forwarding policy can be added to   |
   |                       |                          |   an HTTP or HTTPS listener.          |
   |                       |                          |                                       |
   |                       |                          | - If **action** is set to             |
   |                       |                          |   **REDIRECT_TO_LISTENER**, the       |
   |                       |                          |   forwarding policy can be added to   |
   |                       |                          |   an HTTP listener.                   |
   +-----------------------+--------------------------+---------------------------------------+
   | name                  | String                   | Specifies the forwarding policy name. |
   |                       |                          |                                       |
   |                       |                          | Minimum: **1**                        |
   |                       |                          | Maximum: **255**                      |
   +-----------------------+--------------------------+---------------------------------------+
   | position              | Integer                  | Specifies the forwarding policy       |
   |                       |                          | priority. This parameter cannot be    |
   |                       |                          | updated.                              |
   |                       |                          |                                       |
   |                       |                          | This parameter is unsupported. Please |
   |                       |                          | do not use it.                        |
   |                       |                          |                                       |
   |                       |                          | Minimum: **1**                        |
   |                       |                          | Maximum: **100**                      |
   +-----------------------+--------------------------+---------------------------------------+
   | project_id            | String                   | Specifies the project ID of the       |
   |                       |                          | forwarding policy.                    |
   +-----------------------+--------------------------+---------------------------------------+
   | provisioning_status   | String                   | Specifies the provisioning status of  |
   |                       |                          | the forwarding policy.                |
   |                       |                          |                                       |
   |                       |                          | The value can only be **ACTIVE**.     |
   |                       |                          |                                       |
   |                       |                          | Default: **ACTIVE**                   |
   +-----------------------+--------------------------+---------------------------------------+
   | redirect_listener_id  | String                   | Specifies the ID of the listener that |
   |                       |                          | requests are redirected to.           |
   |                       |                          |                                       |
   |                       |                          | This parameter is valid and mandatory |
   |                       |                          | only when **action** is set to        |
   |                       |                          | **REDIRECT_TO_LISTENER**.             |
   |                       |                          |                                       |
   |                       |                          | Only HTTPS listeners are supported,   |
   |                       |                          | and the listener cannot be any        |
   |                       |                          | listener added to other load          |
   |                       |                          | balancers.                            |
   +-----------------------+--------------------------+---------------------------------------+
   | redirect_pool_id      | String                   | Specifies the ID of the backend       |
   |                       |                          | server group that requests are        |
   |                       |                          | forwarded to.                         |
   |                       |                          |                                       |
   |                       |                          | This parameter is valid and mandatory |
   |                       |                          | only when **action** is set to        |
   |                       |                          | **REDIRECT_TO_POOL**.                 |
   |                       |                          |                                       |
   |                       |                          | The specified backend server group    |
   |                       |                          | cannot be the default one associated  |
   |                       |                          | with the listener, or any backend     |
   |                       |                          | server group associated with the      |
   |                       |                          | forwarding policies of other          |
   |                       |                          | listeners.                            |
   |                       |                          |                                       |
   |                       |                          | This parameter cannot be specified    |
   |                       |                          | when **action** is set to             |
   |                       |                          | **REDIRECT_TO_LISTENER**.             |
   +-----------------------+--------------------------+---------------------------------------+
   | redirect_url          | String                   | Specifies the URL to which requests   |
   |                       |                          | are forwarded.                        |
   |                       |                          |                                       |
   |                       |                          | Format:                               |
   |                       |                          | *protocol://host:port/path?query*     |
   |                       |                          |                                       |
   |                       |                          | This parameter is unsupported. Please |
   |                       |                          | do not use it.                        |
   +-----------------------+--------------------------+---------------------------------------+
   | rules                 | Array of :ref:`dl7pc_rr` | Lists the forwarding rules in the     |
   |                       | objects                  | forwarding policy.                    |
   +-----------------------+--------------------------+---------------------------------------+
   | redirect_url_config   | :ref:`dl7pc_rruc` object | Specifies the URL to which requests   |
   |                       |                          | are forwarded.                        |
   |                       |                          |                                       |
   |                       |                          | For shared load balancers, this       |
   |                       |                          | parameter is not supported. If it is  |
   |                       |                          | passed, an error will be returned.    |
   |                       |                          |                                       |
   |                       |                          | For dedicated load balancers, this    |
   |                       |                          | parameter will take effect only when  |
   |                       |                          | advanced forwarding is enabled        |
   |                       |                          | (**enhance_l7policy_enable** is set   |
   |                       |                          | to **true**). If it is passed when    |
   |                       |                          | **enhance_l7policy_enable** is set to |
   |                       |                          | **false**, an error will be returned. |
   |                       |                          |                                       |
   |                       |                          | Format:                               |
   |                       |                          | *protocol://host:port/path?query*     |
   |                       |                          |                                       |
   |                       |                          | At least one of the four parameters   |
   |                       |                          | (**protocol**, **host**, **port**,    |
   |                       |                          | and **path**) must be passed, or      |
   |                       |                          | their values cannot be set to         |
   |                       |                          | **${xxx}** at the same time.          |
   |                       |                          | (**${xxx}** indicates that the value  |
   |                       |                          | in the request will be inherited. For |
   |                       |                          | example, **${host}** indicates the    |
   |                       |                          | host in the URL to be redirected.)    |
   |                       |                          |                                       |
   |                       |                          | The values of **protocol** and        |
   |                       |                          | **port** cannot be the same as those  |
   |                       |                          | of the associated listener, and       |
   |                       |                          | either **host** or **path** must be   |
   |                       |                          | passed or their values cannot be      |
   |                       |                          | **${xxx}** at the same time.          |
   |                       |                          |                                       |
   |                       |                          | This parameter is unsupported. Please |
   |                       |                          | do not use it.                        |
   +-----------------------+--------------------------+---------------------------------------+
   | fixed_response_config | :ref:`dl7pc_rfrc` object | Specifies the configuration of the    |
   |                       |                          | page that will be returned. This      |
   |                       |                          | parameter will take effect when       |
   |                       |                          | **enhance_l7policy_enable** is set to |
   |                       |                          | **true**. If this parameter is passed |
   |                       |                          | and **enhance_l7policy_enable** is    |
   |                       |                          | set to **false**, an error will be    |
   |                       |                          | returned. For shared load balancers,  |
   |                       |                          | this parameter is not supported. If   |
   |                       |                          | it is passed, an error will be        |
   |                       |                          | returned.                             |
   |                       |                          |                                       |
   |                       |                          | This parameter is unsupported. Please |
   |                       |                          | do not use it.                        |
   +-----------------------+--------------------------+---------------------------------------+
   | priority              | Integer                  | Specifies the forwarding policy       |
   |                       |                          | priority. This parameter is available |
   |                       |                          | only for dedicated load balancers and |
   |                       |                          | will take effect when                 |
   |                       |                          | **enhance_l7policy_enable** is set to |
   |                       |                          | **true**.                             |
   |                       |                          |                                       |
   |                       |                          | A smaller value indicates a higher    |
   |                       |                          | priority. The value must be unique    |
   |                       |                          | for each forwarding policy of the     |
   |                       |                          | same listener.                        |
   |                       |                          |                                       |
   |                       |                          | If **action** is set to               |
   |                       |                          | **REDIRECT_TO_LISTENER**, the value   |
   |                       |                          | can only be **0**, indicating that    |
   |                       |                          | **REDIRECT_TO_LISTENER** has the      |
   |                       |                          | highest priority.                     |
   |                       |                          |                                       |
   |                       |                          | - If **enhance_l7policy_enable** is   |
   |                       |                          |   set to **false**, forwarding        |
   |                       |                          |   policies are automatically          |
   |                       |                          |   prioritized based on the original   |
   |                       |                          |   sorting logic. Forwarding policy    |
   |                       |                          |   priorities are independent of each  |
   |                       |                          |   other regardless of domain names.   |
   |                       |                          |   If forwarding policies use the      |
   |                       |                          |   same domain name, their priorities  |
   |                       |                          |   follow the order of exact match     |
   |                       |                          |   (**EQUAL_TO**), prefix match        |
   |                       |                          |   (**STARTS_WITH**), and regular      |
   |                       |                          |   expression match (**REGEX**). If    |
   |                       |                          |   prefix match is used for matching,  |
   |                       |                          |   the longer the path, the higher     |
   |                       |                          |   the priority. If a forwarding       |
   |                       |                          |   policy contains only a domain name  |
   |                       |                          |   without a path specified, the path  |
   |                       |                          |   is **/**, and prefix match is used  |
   |                       |                          |   by default.                         |
   |                       |                          |                                       |
   |                       |                          | - If **enhance_l7policy_enable** is   |
   |                       |                          |   set to **true** and this parameter  |
   |                       |                          |   is not passed, the priority will    |
   |                       |                          |   set to a sum of 1 and the highest   |
   |                       |                          |   priority of existing forwarding     |
   |                       |                          |   policy in the same listener by      |
   |                       |                          |   default. There will be two cases:   |
   |                       |                          |   a) If the highest priority of       |
   |                       |                          |   existing forwarding policies is     |
   |                       |                          |   the maximum (10,000), the           |
   |                       |                          |   forwarding policy will fail to      |
   |                       |                          |   create because the final priority   |
   |                       |                          |   for creating the forwarding policy  |
   |                       |                          |   is the sum of 1 and 10,000, which   |
   |                       |                          |   exceeds the maximum. In this case,  |
   |                       |                          |   please specify a value or adjust    |
   |                       |                          |   the priorities of existing          |
   |                       |                          |   forwarding policies. b) If no       |
   |                       |                          |   forwarding policies exist, the      |
   |                       |                          |   highest priority of existing        |
   |                       |                          |   forwarding policies will set to 1   |
   |                       |                          |   by default.                         |
   |                       |                          |                                       |
   |                       |                          | This parameter is unsupported. Please |
   |                       |                          | do not use it.                        |
   |                       |                          |                                       |
   |                       |                          | Minimum: **0**                        |
   |                       |                          | Maximum: **10000**                    |
   +-----------------------+--------------------------+---------------------------------------+

.. _dl7pc_rr:
.. table:: **Table 11** RuleRef

   ========= ====== =================================
   Parameter Type   Description
   ========= ====== =================================
   id        String Specifies the forwarding rule ID.
   ========= ====== =================================

.. _dl7pc_rruc:
.. table:: **Table 12** RedirectUrlConfig

   +-------------+--------+---------------------------------------+
   | Parameter   | Type   | Description                           |
   +=============+========+=======================================+
   | protocol    | String | Specifies the protocol for            |
   |             |        | redirection. The default value is     |
   |             |        | **${protocol}**, indicating that the  |
   |             |        | protocol of the request will be used. |
   |             |        |                                       |
   |             |        | Value options:                        |
   |             |        |                                       |
   |             |        | -  **HTTP**                           |
   |             |        | -  **HTTPS**                          |
   |             |        | -  **${protocol}**                    |
   |             |        |                                       |
   |             |        | Minimum: **1**                        |
   |             |        | Maximum: **36**                       |
   +-------------+--------+---------------------------------------+
   | host        | String | Specifies the host name that requests |
   |             |        | are redirected to. The value can      |
   |             |        | contain only letters, digits, hyphens |
   |             |        | (-), and periods (.) and must start   |
   |             |        | with a letter or digit. The default   |
   |             |        | value is **${host}**, indicating that |
   |             |        | the host of the request will be used. |
   |             |        |                                       |
   |             |        | Default: **${host}**                  |
   |             |        | Minimum: **1**                        |
   |             |        | Maximum: **128**                      |
   +-------------+--------+---------------------------------------+
   | port        | String | Specifies the port that requests are  |
   |             |        | redirected to. The default value is   |
   |             |        | **${port}**, indicating that the port |
   |             |        | of the request will be used.          |
   |             |        |                                       |
   |             |        | Default: **${port}**                  |
   |             |        | Minimum: **1**                        |
   |             |        | Maximum: **16**                       |
   +-------------+--------+---------------------------------------+
   | path        | String | Specifies the path that requests are  |
   |             |        | redirected to. The default value is   |
   |             |        | **${path}**, indicating that the path |
   |             |        | of the request will be used. The      |
   |             |        | value can contain only letters,       |
   |             |        | digits, and special characters        |
   |             |        | \_-';@^- %#&$.*+?,=!:&vert;/()[]{}    |
   |             |        | must start with a slash (/).          |
   |             |        |                                       |
   |             |        | Default: **${path}**                  |
   |             |        | Minimum: **1**                        |
   |             |        | Maximum: **128**                      |
   +-------------+--------+---------------------------------------+
   | query       | String | Specifies the query string set in the |
   |             |        | URL for redirection. The default      |
   |             |        | value is **${query}**, indicating     |
   |             |        | that the query string of the request  |
   |             |        | will be used.                         |
   |             |        |                                       |
   |             |        | For example, in the URL               |
   |             |        | **https://www.                        |
   |             |        | xxx.com:8080/elb?type=loadbalancer**, |
   |             |        | **${query}** indicates                |
   |             |        | **type=loadbalancer**. If this        |
   |             |        | parameter is set to                   |
   |             |        | **${query}&name=my_name**, the URL    |
   |             |        | will be redirected to                 |
   |             |        | **https://www.xxx.com:8080/           |
   |             |        | elb?type=loadbalancer&name=my_name**. |
   |             |        |                                       |
   |             |        | The value is case-sensitive and can   |
   |             |        | contain only letters, digits, and     |
   |             |        | special characters                    |
   |             |        | !$&'()*+,-./:;=?@^_\`                 |
   |             |        |                                       |
   |             |        | Default: **${query}**                 |
   |             |        | Minimum: **0**                        |
   |             |        | Maximum: **128**                      |
   +-------------+--------+---------------------------------------+
   | status_code | String | Specifies the status code returned    |
   |             |        | after the requests are redirected.    |
   |             |        |                                       |
   |             |        | Value options:                        |
   |             |        |                                       |
   |             |        | -  **301**                            |
   |             |        | -  **302**                            |
   |             |        | -  **303**                            |
   |             |        | -  **307**                            |
   |             |        | -  **308**                            |
   |             |        |                                       |
   |             |        | Minimum: **1**                        |
   |             |        | Maximum: **16**                       |
   +-------------+--------+---------------------------------------+

.. _dl7pc_rfrc:
.. table:: **Table 13** FixtedResponseConfig

   +--------------+--------+---------------------------------------+
   | Parameter    | Type   | Description                           |
   +==============+========+=======================================+
   | status_code  | String | Specifies the HTTP status code        |
   |              |        | configured in the forwarding policy.  |
   |              |        | The value can be any integer in the   |
   |              |        | range of 200–299, 400–499, or         |
   |              |        | 500–599.                              |
   |              |        |                                       |
   |              |        | Minimum: **1**                        |
   |              |        | Maximum: **16**                       |
   +--------------+--------+---------------------------------------+
   | content_type | String | Specifies the format of the response  |
   |              |        | body.                                 |
   |              |        |                                       |
   |              |        | Value options:                        |
   |              |        |                                       |
   |              |        | -  **text/plain**                     |
   |              |        | -  **text/css**                       |
   |              |        | -  **text/html**                      |
   |              |        | -  **application/javascript**         |
   |              |        | -  **application/json**               |
   |              |        |                                       |
   |              |        | Minimum: **0**                        |
   |              |        | Maximum: **32**                       |
   +--------------+--------+---------------------------------------+
   | message_body | String | Specifies the content of the response |
   |              |        | body.                                 |
   |              |        |                                       |
   |              |        | Minimum: **0**                        |
   |              |        | Maximum: **1024**                     |
   +--------------+--------+---------------------------------------+

Example Requests
^^^^^^^^^^^^^^^^

Creating a redirection for a listener

.. code::

   POST

   https://{elb_endpoint}/v3/99a3fff0d03c428eac3678da6a7d0f24/elb/l7policies

   {
     "l7policy" : {
       "action" : "REDIRECT_TO_LISTENER",
       "listener_id" : "e2220d2a-3faf-44f3-8cd6-0c42952bd0ab",
       "redirect_listener_id" : "48a97732-449e-4aab-b561-828d29e45050"
     }
   }

Example Responses
^^^^^^^^^^^^^^^^^

**Status code: 201**

Successful request.

.. code::

   {
     "request_id" : "b60d1d9a-5263-45b0-b1d6-2810ac7c52a1",
     "l7policy" : {
       "description" : "",
       "admin_state_up" : true,
       "rules" : [ ],
       "project_id" : "99a3fff0d03c428eac3678da6a7d0f24",
       "listener_id" : "e2220d2a-3faf-44f3-8cd6-0c42952bd0ab",
       "redirect_listener_id" : "48a97732-449e-4aab-b561-828d29e45050",
       "action" : "REDIRECT_TO_LISTENER",
       "position" : 100,
       "provisioning_status" : "ACTIVE",
       "id" : "cf4360fd-8631-41ff-a6f5-b72c35da74be",
       "name" : ""
     }
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

Querying Forwarding Policies
============================

Function
^^^^^^^^

This API is used to query all forwarding policies.

Constraints
^^^^^^^^^^^

Parameters **marker**, **limit**, and **page_reverse** are used for pagination
query.

Parameters **marker** and **page_reverse** take effect only when they are used
together with parameter **limit**.

URI
^^^

GET /v3/{project_id}/elb/l7policies

.. table:: **Table 1** Path parameters

   ========== ========= ====== =========================
   Parameter  Mandatory Type   Description
   ========== ========= ====== =========================
   project_id Yes       String Specifies the project ID.
   ========== ========= ====== =========================

.. table:: **Table 2** Query parameters

   +-----------------------+-----------+---------+------------------------------------------------------+
   | Parameter             | Mandatory | Type    | Description                                          |
   +=======================+===========+=========+======================================================+
   | marker                | No        | String  | Specifies the ID of the                              |
   |                       |           |         | last record on the previous                          |
   |                       |           |         | page.                                                |
   |                       |           |         |                                                      |
   |                       |           |         | Note:                                                |
   |                       |           |         |                                                      |
   |                       |           |         | - This parameter must be                             |
   |                       |           |         |   used together with                                 |
   |                       |           |         |   **limit**.                                         |
   |                       |           |         |                                                      |
   |                       |           |         | - If this parameter is not                           |
   |                       |           |         |   specified, the first                               |
   |                       |           |         |   page will be queried.                              |
   |                       |           |         |                                                      |
   |                       |           |         | - This parameter cannot be                           |
   |                       |           |         |   left blank or set to an                            |
   |                       |           |         |   invalid ID.                                        |
   +-----------------------+-----------+---------+------------------------------------------------------+
   | limit                 | No        | Integer | Specifies the number of                              |
   |                       |           |         | records on each page.                                |
   |                       |           |         |                                                      |
   |                       |           |         | Minimum: **0**                                       |
   |                       |           |         | Maximum: **2000**                                    |
   +-----------------------+-----------+---------+------------------------------------------------------+
   | page_reverse          | No        | Boolean | Specifies the page                                   |
   |                       |           |         | direction.                                           |
   |                       |           |         |                                                      |
   |                       |           |         | The value can be **true**                            |
   |                       |           |         | or **false**, and the                                |
   |                       |           |         | default value is **false**.                          |
   |                       |           |         |                                                      |
   |                       |           |         | The last page in the list                            |
   |                       |           |         | requested with                                       |
   |                       |           |         | **page_reverse** set to                              |
   |                       |           |         | **false** will not contain                           |
   |                       |           |         | the "next" link, and the                             |
   |                       |           |         | last page in the list                                |
   |                       |           |         | requested with                                       |
   |                       |           |         | **page_reverse** set to                              |
   |                       |           |         | **true** will not contain                            |
   |                       |           |         | the "previous" link.                                 |
   |                       |           |         |                                                      |
   |                       |           |         | This parameter must be used                          |
   |                       |           |         | together with **limit**.                             |
   +-----------------------+-----------+---------+------------------------------------------------------+
   | enterprise_project_id | No        | Array   | Specifies the enterprise                             |
   |                       |           |         | project ID.                                          |
   |                       |           |         |                                                      |
   |                       |           |         | - If this parameter is not                           |
   |                       |           |         |   passed, resources in the                           |
   |                       |           |         |   default enterprise                                 |
   |                       |           |         |   project are queried, and                           |
   |                       |           |         |   authentication is                                  |
   |                       |           |         |   performed based on the                             |
   |                       |           |         |   default enterprise                                 |
   |                       |           |         |   project.                                           |
   |                       |           |         |                                                      |
   |                       |           |         | - If this parameter is                               |
   |                       |           |         |   passed, its value can be                           |
   |                       |           |         |   the ID of an existing                              |
   |                       |           |         |   enterprise project or                              |
   |                       |           |         |   **all_granted_eps**.                               |
   |                       |           |         |                                                      |
   |                       |           |         | If the value is a specific                           |
   |                       |           |         | ID, resources in the                                 |
   |                       |           |         | specific enterprise project                          |
   |                       |           |         | are required. If the value                           |
   |                       |           |         | is **all_granted_eps**,                              |
   |                       |           |         | resources in all enterprise                          |
   |                       |           |         | projects are queried.                                |
   |                       |           |         |                                                      |
   |                       |           |         | Multiple IDs can be queried                          |
   |                       |           |         | in the format of                                     |
   |                       |           |         | *enterprise_project_id=xxx&                          |
   |                       |           |         | enterprise_project_id=xxx*.                          |
   |                       |           |         |                                                      |
   |                       |           |         | This parameter is                                    |
   |                       |           |         | unsupported. Please do not                           |
   |                       |           |         | use it.                                              |
   +-----------------------+-----------+---------+------------------------------------------------------+
   | id                    | No        | Array   | Specifies the forwarding                             |
   |                       |           |         | policy ID.                                           |
   |                       |           |         |                                                      |
   |                       |           |         | Multiple IDs can be queried                          |
   |                       |           |         | in the format of                                     |
   |                       |           |         | *id=xxx&id=xxx*.                                     |
   +-----------------------+-----------+---------+------------------------------------------------------+
   | name                  | No        | Array   | Specifies the forwarding                             |
   |                       |           |         | policy name.                                         |
   |                       |           |         |                                                      |
   |                       |           |         | Multiple names can be                                |
   |                       |           |         | queried in the format of                             |
   |                       |           |         | *name=xxx&name=xxx*.                                 |
   +-----------------------+-----------+---------+------------------------------------------------------+
   | description           | No        | Array   | Provides supplementary                               |
   |                       |           |         | information about the                                |
   |                       |           |         | forwarding policy.                                   |
   |                       |           |         |                                                      |
   |                       |           |         | Multiple descriptions can                            |
   |                       |           |         | be queried in the format of                          |
   |                       |           |         | *descri                                              |
   |                       |           |         | ption=xxx&description=xxx*.                          |
   +-----------------------+-----------+---------+------------------------------------------------------+
   | admin_state_up        | No        | Boolean | Specifies the                                        |
   |                       |           |         | administrative status of                             |
   |                       |           |         | the forwarding policy. The                           |
   |                       |           |         | default value is **true**.                           |
   |                       |           |         |                                                      |
   |                       |           |         | This parameter is                                    |
   |                       |           |         | unsupported. Please do not                           |
   |                       |           |         | use it.                                              |
   +-----------------------+-----------+---------+------------------------------------------------------+
   | listener_id           | No        | Array   | Specifies the ID of the                              |
   |                       |           |         | listener to which the                                |
   |                       |           |         | forwarding policy is added.                          |
   |                       |           |         |                                                      |
   |                       |           |         | - If **action** is set to                            |
   |                       |           |         |   **REDIRECT_TO_POOL**,                              |
   |                       |           |         |   the forwarding policy                              |
   |                       |           |         |   can be added to an HTTP                            |
   |                       |           |         |   or HTTPS listener.                                 |
   |                       |           |         |                                                      |
   |                       |           |         | - If **action** is set to                            |
   |                       |           |         |   **REDIRECT_TO_LISTENER**,                          |
   |                       |           |         |   the forwarding policy                              |
   |                       |           |         |   can be added to an HTTP                            |
   |                       |           |         |   listener.                                          |
   |                       |           |         |                                                      |
   |                       |           |         | Multiple IDs can be queried                          |
   |                       |           |         | in the format of                                     |
   |                       |           |         | *listener_id=xxx&listener_id=xxx*.                   |
   +-----------------------+-----------+---------+------------------------------------------------------+
   | position              | No        | Array   | Specifies the forwarding                             |
   |                       |           |         | policy priority.                                     |
   |                       |           |         |                                                      |
   |                       |           |         | Multiple priorities can be                           |
   |                       |           |         | queried in the format of                             |
   |                       |           |         | *position=xxx&position=xxx*.                         |
   |                       |           |         |                                                      |
   |                       |           |         | This parameter is                                    |
   |                       |           |         | unsupported. Please do not                           |
   |                       |           |         | use it.                                              |
   +-----------------------+-----------+---------+------------------------------------------------------+
   | action                | No        | Array   | Specifies where requests                             |
   |                       |           |         | will be forwarded. The                               |
   |                       |           |         | value can be one of the                              |
   |                       |           |         | following:                                           |
   |                       |           |         |                                                      |
   |                       |           |         | - **REDIRECT_TO_POOL**:                              |
   |                       |           |         |   Requests will be                                   |
   |                       |           |         |   forwarded to another                               |
   |                       |           |         |   backend server group.                              |
   |                       |           |         |                                                      |
   |                       |           |         | - **REDIRECT_TO_LISTENER**:                          |
   |                       |           |         |   Requests will be                                   |
   |                       |           |         |   redirected to an HTTPS                             |
   |                       |           |         |   listener.                                          |
   |                       |           |         |                                                      |
   |                       |           |         | Multiple values can be                               |
   |                       |           |         | queried in the format of                             |
   |                       |           |         | *action=xxx&action=xxx*.                             |
   +-----------------------+-----------+---------+------------------------------------------------------+
   | redirect_url          | No        | Array   | Specifies the URL to which                           |
   |                       |           |         | requests are forwarded.                              |
   |                       |           |         |                                                      |
   |                       |           |         | Multiple URLs can be                                 |
   |                       |           |         | queried in the format of                             |
   |                       |           |         | *redirect_url=xxx&redirect_url=xxx*.                 |
   |                       |           |         |                                                      |
   |                       |           |         | This parameter is                                    |
   |                       |           |         | unsupported. Please do not                           |
   |                       |           |         | use it.                                              |
   +-----------------------+-----------+---------+------------------------------------------------------+
   | redirect_pool_id      | No        | Array   | Specifies the ID of the                              |
   |                       |           |         | backend server group to                              |
   |                       |           |         | which requests are                                   |
   |                       |           |         | forwarded. This parameter                            |
   |                       |           |         | will take effect and is                              |
   |                       |           |         | mandatory when **action**                            |
   |                       |           |         | is set to                                            |
   |                       |           |         | **REDIRECT_TO_POOL**.                                |
   |                       |           |         |                                                      |
   |                       |           |         | Multiple IDs can be queried                          |
   |                       |           |         | in the format of                                     |
   |                       |           |         | *redirect_pool_id=xxx&redirect_pool_id=xxx*.         |
   +-----------------------+-----------+---------+------------------------------------------------------+
   | redirect_listener_id  | No        | Array   | Specifies the ID of the                              |
   |                       |           |         | listener to which requests                           |
   |                       |           |         | are redirected. This                                 |
   |                       |           |         | parameter will take effect                           |
   |                       |           |         | and is mandatory when                                |
   |                       |           |         | **action** is set to                                 |
   |                       |           |         | **REDIRECT_TO_LISTENER**.                            |
   |                       |           |         |                                                      |
   |                       |           |         | Multiple IDs can be queried                          |
   |                       |           |         | in the format of                                     |
   |                       |           |         | *redirect_listener_id=xxx&redirect_listener_id=xxx*. |
   +-----------------------+-----------+---------+------------------------------------------------------+
   | provisioning_status   | No        | Array   | Specifies the provisioning                           |
   |                       |           |         | status of the forwarding                             |
   |                       |           |         | policy. The value can only                           |
   |                       |           |         | be **ACTIVE**, indicating                            |
   |                       |           |         | that the forwarding policy                           |
   |                       |           |         | is provisioned                                       |
   |                       |           |         | successfully.                                        |
   |                       |           |         |                                                      |
   |                       |           |         | Multiple provisioning                                |
   |                       |           |         | statuses can be queried in                           |
   |                       |           |         | the format of                                        |
   |                       |           |         | *provisioning_status=xxx&provisioning_status=xxx*.   |
   +-----------------------+-----------+---------+------------------------------------------------------+
   | display_all_rules     | No        | Boolean | Specifies whether to                                 |
   |                       |           |         | display all information                              |
   |                       |           |         | about the forwarding rule                            |
   |                       |           |         | in the forwarding policy.                            |
   |                       |           |         | The value can be **true**                            |
   |                       |           |         | or **false**.                                        |
   |                       |           |         |                                                      |
   |                       |           |         | - **true** indicates all                             |
   |                       |           |         |   information about the                              |
   |                       |           |         |   forwarding rule is                                 |
   |                       |           |         |   displayed.                                         |
   |                       |           |         |                                                      |
   |                       |           |         | - **false** indicates that                           |
   |                       |           |         |   only the rule ID is                                |
   |                       |           |         |   displayed.                                         |
   +-----------------------+-----------+---------+------------------------------------------------------+
   | priority              | No        | Array   | Specifies the forwarding                             |
   |                       |           |         | policy priority. A smaller                           |
   |                       |           |         | value indicates a higher                             |
   |                       |           |         | priority.                                            |
   |                       |           |         |                                                      |
   |                       |           |         | Multiple priorities can be                           |
   |                       |           |         | queried in the format of                             |
   |                       |           |         | *position=xxx&position=xxx*.                         |
   |                       |           |         |                                                      |
   |                       |           |         | This parameter is                                    |
   |                       |           |         | unsupported. Please do not                           |
   |                       |           |         | use it.                                              |
   +-----------------------+-----------+---------+------------------------------------------------------+

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

   +------------+---------------------------------+----------------------------------------+
   | Parameter  | Type                            | Description                            |
   +============+=================================+========================================+
   | request_id | String                          | Specifies the request ID. The value is |
   |            |                                 | automatically generated.               |
   +------------+---------------------------------+----------------------------------------+
   | page_info  | :ref:`dl7pl_pi` object          | Shows pagination information.          |
   +------------+---------------------------------+----------------------------------------+
   | l7policies | Array of :ref:`dl7pl_p` objects | Lists the forwarding policies.         |
   +------------+---------------------------------+----------------------------------------+

.. _dl7pl_pi:
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

.. _dl7pl_p:
.. table:: **Table 6** L7Policy

   +-----------------------+------------------+---------------------------------------+
   | Parameter             | Type             | Description                           |
   +=======================+==================+=======================================+
   | action                | String           | Specifies where requests will be      |
   |                       |                  | forwarded. The value can be one of    |
   |                       |                  | the following:                        |
   |                       |                  |                                       |
   |                       |                  | -  **REDIRECT_TO_POOL**: Requests     |
   |                       |                  |    will be forwarded to another       |
   |                       |                  |    backend server group.              |
   |                       |                  |                                       |
   |                       |                  | -  **REDIRECT_TO_LISTENER**: Requests |
   |                       |                  |    will be redirected to an HTTPS     |
   |                       |                  |    listener.                          |
   |                       |                  |                                       |
   |                       |                  | **REDIRECT_TO_LISTENER** has the      |
   |                       |                  | highest priority. If requests are to  |
   |                       |                  | be redirected to an HTTPS listener,   |
   |                       |                  | other forwarding policies of the      |
   |                       |                  | listener will become invalid.         |
   +-----------------------+------------------+---------------------------------------+
   | admin_state_up        | Boolean          | Specifies the administrative status   |
   |                       |                  | of the forwarding policy. The default |
   |                       |                  | value is **true**.                    |
   |                       |                  |                                       |
   |                       |                  | This parameter is unsupported. Please |
   |                       |                  | do not use it.                        |
   |                       |                  |                                       |
   |                       |                  | Default: **true**                     |
   +-----------------------+------------------+---------------------------------------+
   | description           | String           | Provides supplementary information    |
   |                       |                  | about the forwarding policy.          |
   +-----------------------+------------------+---------------------------------------+
   | id                    | String           | Specifies the forwarding policy ID.   |
   +-----------------------+------------------+---------------------------------------+
   | listener_id           | String           | Specifies the ID of the listener to   |
   |                       |                  | which the forwarding policy is added. |
   |                       |                  |                                       |
   |                       |                  | - If **action** is set to             |
   |                       |                  |   **REDIRECT_TO_POOL**, the           |
   |                       |                  |   forwarding policy can be added to   |
   |                       |                  |   an HTTP or HTTPS listener.          |
   |                       |                  |                                       |
   |                       |                  | - If **action** is set to             |
   |                       |                  |   **REDIRECT_TO_LISTENER**, the       |
   |                       |                  |   forwarding policy can be added to   |
   |                       |                  |   an HTTP listener.                   |
   +-----------------------+------------------+---------------------------------------+
   | name                  | String           | Specifies the forwarding policy name. |
   |                       |                  |                                       |
   |                       |                  | Minimum: **1**                        |
   |                       |                  | Maximum: **255**                      |
   +-----------------------+------------------+---------------------------------------+
   | position              | Integer          | Specifies the forwarding policy       |
   |                       |                  | priority. This parameter cannot be    |
   |                       |                  | updated.                              |
   |                       |                  |                                       |
   |                       |                  | This parameter is unsupported. Please |
   |                       |                  | do not use it.                        |
   |                       |                  |                                       |
   |                       |                  | Minimum: **1**                        |
   |                       |                  | Maximum: **100**                      |
   +-----------------------+------------------+---------------------------------------+
   | project_id            | String           | Specifies the project ID of the       |
   |                       |                  | forwarding policy.                    |
   +-----------------------+------------------+---------------------------------------+
   | provisioning_status   | String           | Specifies the provisioning status of  |
   |                       |                  | the forwarding policy.                |
   |                       |                  |                                       |
   |                       |                  | The value can only be **ACTIVE**.     |
   |                       |                  |                                       |
   |                       |                  | Default: **ACTIVE**                   |
   +-----------------------+------------------+---------------------------------------+
   | redirect_listener_id  | String           | Specifies the ID of the listener that |
   |                       |                  | requests are redirected to.           |
   |                       |                  |                                       |
   |                       |                  | This parameter is valid and mandatory |
   |                       |                  | only when **action** is set to        |
   |                       |                  | **REDIRECT_TO_LISTENER**.             |
   |                       |                  |                                       |
   |                       |                  | Only HTTPS listeners are supported,   |
   |                       |                  | and the listener cannot be any        |
   |                       |                  | listener added to other load          |
   |                       |                  | balancers.                            |
   +-----------------------+------------------+---------------------------------------+
   | redirect_pool_id      | String           | Specifies the ID of the backend       |
   |                       |                  | server group that requests are        |
   |                       |                  | forwarded to.                         |
   |                       |                  |                                       |
   |                       |                  | This parameter is valid and mandatory |
   |                       |                  | only when **action** is set to        |
   |                       |                  | **REDIRECT_TO_POOL**.                 |
   |                       |                  |                                       |
   |                       |                  | The specified backend server group    |
   |                       |                  | cannot be the default one associated  |
   |                       |                  | with the listener, or any backend     |
   |                       |                  | server group associated with the      |
   |                       |                  | forwarding policies of other          |
   |                       |                  | listeners.                            |
   |                       |                  |                                       |
   |                       |                  | This parameter cannot be specified    |
   |                       |                  | when **action** is set to             |
   |                       |                  | **REDIRECT_TO_LISTENER**.             |
   +-----------------------+------------------+---------------------------------------+
   | redirect_url          | String           | Specifies the URL to which requests   |
   |                       |                  | are forwarded.                        |
   |                       |                  |                                       |
   |                       |                  | Format:                               |
   |                       |                  | *protocol://host:port/path?query*     |
   |                       |                  |                                       |
   |                       |                  | This parameter is unsupported. Please |
   |                       |                  | do not use it.                        |
   +-----------------------+------------------+---------------------------------------+
   | rules                 | Array of         | Lists the forwarding rules in the     |
   |                       | :ref:`dl7pl_rr`  | forwarding policy.                    |
   |                       | objects          |                                       |
   +-----------------------+------------------+---------------------------------------+
   | redirect_url_config   | :ref:`dl7pl_ruc` | Specifies the URL to which requests   |
   |                       | object           | are forwarded.                        |
   |                       |                  |                                       |
   |                       |                  | For shared load balancers, this       |
   |                       |                  | parameter is not supported. If it is  |
   |                       |                  | passed, an error will be returned.    |
   |                       |                  |                                       |
   |                       |                  | For dedicated load balancers, this    |
   |                       |                  | parameter will take effect only when  |
   |                       |                  | advanced forwarding is enabled        |
   |                       |                  | (**enhance_l7policy_enable** is set   |
   |                       |                  | to **true**). If it is passed when    |
   |                       |                  | **enhance_l7policy_enable** is set to |
   |                       |                  | **false**, an error will be returned. |
   |                       |                  |                                       |
   |                       |                  | Format:                               |
   |                       |                  | *protocol://host:port/path?query*     |
   |                       |                  |                                       |
   |                       |                  | At least one of the four parameters   |
   |                       |                  | (**protocol**, **host**, **port**,    |
   |                       |                  | and **path**) must be passed, or      |
   |                       |                  | their values cannot be set to         |
   |                       |                  | **${xxx}** at the same time.          |
   |                       |                  | (**${xxx}** indicates that the value  |
   |                       |                  | in the request will be inherited. For |
   |                       |                  | example, **${host}** indicates the    |
   |                       |                  | host in the URL to be redirected.)    |
   |                       |                  |                                       |
   |                       |                  | The values of **protocol** and        |
   |                       |                  | **port** cannot be the same as those  |
   |                       |                  | of the associated listener, and       |
   |                       |                  | either **host** or **path** must be   |
   |                       |                  | passed or their values cannot be      |
   |                       |                  | **${xxx}** at the same time.          |
   |                       |                  |                                       |
   |                       |                  | This parameter is unsupported. Please |
   |                       |                  | do not use it.                        |
   +-----------------------+------------------+---------------------------------------+
   | fixed_response_config | :ref:`dl7pl_frc` | Specifies the configuration of the    |
   |                       | object           | page that will be returned. This      |
   |                       |                  | parameter will take effect when       |
   |                       |                  | **enhance_l7policy_enable** is set to |
   |                       |                  | **true**. If this parameter is passed |
   |                       |                  | and **enhance_l7policy_enable** is    |
   |                       |                  | set to **false**, an error will be    |
   |                       |                  | returned. For shared load balancers,  |
   |                       |                  | this parameter is not supported. If   |
   |                       |                  | it is passed, an error will be        |
   |                       |                  | returned.                             |
   |                       |                  |                                       |
   |                       |                  | This parameter is unsupported. Please |
   |                       |                  | do not use it.                        |
   +-----------------------+------------------+---------------------------------------+
   | priority              | Integer          | Specifies the forwarding policy       |
   |                       |                  | priority. This parameter is available |
   |                       |                  | only for dedicated load balancers and |
   |                       |                  | will take effect when                 |
   |                       |                  | **enhance_l7policy_enable** is set to |
   |                       |                  | **true**.                             |
   |                       |                  |                                       |
   |                       |                  | A smaller value indicates a higher    |
   |                       |                  | priority. The value must be unique    |
   |                       |                  | for each forwarding policy of the     |
   |                       |                  | same listener.                        |
   |                       |                  |                                       |
   |                       |                  | If **action** is set to               |
   |                       |                  | **REDIRECT_TO_LISTENER**, the value   |
   |                       |                  | can only be **0**, indicating that    |
   |                       |                  | **REDIRECT_TO_LISTENER** has the      |
   |                       |                  | highest priority.                     |
   |                       |                  |                                       |
   |                       |                  | - If **enhance_l7policy_enable** is   |
   |                       |                  |   set to **false**, forwarding        |
   |                       |                  |   policies are automatically          |
   |                       |                  |   prioritized based on the original   |
   |                       |                  |   sorting logic. Forwarding policy    |
   |                       |                  |   priorities are independent of each  |
   |                       |                  |   other regardless of domain names.   |
   |                       |                  |   If forwarding policies use the      |
   |                       |                  |   same domain name, their priorities  |
   |                       |                  |   follow the order of exact match     |
   |                       |                  |   (**EQUAL_TO**), prefix match        |
   |                       |                  |   (**STARTS_WITH**), and regular      |
   |                       |                  |   expression match (**REGEX**). If    |
   |                       |                  |   prefix match is used for matching,  |
   |                       |                  |   the longer the path, the higher     |
   |                       |                  |   the priority. If a forwarding       |
   |                       |                  |   policy contains only a domain name  |
   |                       |                  |   without a path specified, the path  |
   |                       |                  |   is **/**, and prefix match is used  |
   |                       |                  |   by default.                         |
   |                       |                  |                                       |
   |                       |                  | - If **enhance_l7policy_enable** is   |
   |                       |                  |   set to **true** and this parameter  |
   |                       |                  |   is not passed, the priority will    |
   |                       |                  |   set to a sum of 1 and the highest   |
   |                       |                  |   priority of existing forwarding     |
   |                       |                  |   policy in the same listener by      |
   |                       |                  |   default. There will be two cases:   |
   |                       |                  |   a) If the highest priority of       |
   |                       |                  |   existing forwarding policies is     |
   |                       |                  |   the maximum (10,000), the           |
   |                       |                  |   forwarding policy will fail to      |
   |                       |                  |   create because the final priority   |
   |                       |                  |   for creating the forwarding policy  |
   |                       |                  |   is the sum of 1 and 10,000, which   |
   |                       |                  |   exceeds the maximum. In this case,  |
   |                       |                  |   please specify a value or adjust    |
   |                       |                  |   the priorities of existing          |
   |                       |                  |   forwarding policies. b) If no       |
   |                       |                  |   forwarding policies exist, the      |
   |                       |                  |   highest priority of existing        |
   |                       |                  |   forwarding policies will set to 1   |
   |                       |                  |   by default.                         |
   |                       |                  |                                       |
   |                       |                  | This parameter is unsupported. Please |
   |                       |                  | do not use it.                        |
   |                       |                  |                                       |
   |                       |                  | Minimum: **0**                        |
   |                       |                  | Maximum: **10000**                    |
   +-----------------------+------------------+---------------------------------------+

.. _dl7pl_rr:
.. table:: **Table 7** RuleRef

   ========= ====== =================================
   Parameter Type   Description
   ========= ====== =================================
   id        String Specifies the forwarding rule ID.
   ========= ====== =================================

.. _dl7pl_ruc:
.. table:: **Table 8** RedirectUrlConfig

   +-------------+--------+---------------------------------------+
   | Parameter   | Type   | Description                           |
   +=============+========+=======================================+
   | protocol    | String | Specifies the protocol for            |
   |             |        | redirection. The default value is     |
   |             |        | **${protocol}**, indicating that the  |
   |             |        | protocol of the request will be used. |
   |             |        |                                       |
   |             |        | Value options:                        |
   |             |        |                                       |
   |             |        | -  **HTTP**                           |
   |             |        | -  **HTTPS**                          |
   |             |        | -  **${protocol}**                    |
   |             |        |                                       |
   |             |        | Minimum: **1**                        |
   |             |        | Maximum: **36**                       |
   +-------------+--------+---------------------------------------+
   | host        | String | Specifies the host name that requests |
   |             |        | are redirected to. The value can      |
   |             |        | contain only letters, digits, hyphens |
   |             |        | (-), and periods (.) and must start   |
   |             |        | with a letter or digit. The default   |
   |             |        | value is **${host}**, indicating that |
   |             |        | the host of the request will be used. |
   |             |        |                                       |
   |             |        | Default: **${host}**                  |
   |             |        | Minimum: **1**                        |
   |             |        | Maximum: **128**                      |
   +-------------+--------+---------------------------------------+
   | port        | String | Specifies the port that requests are  |
   |             |        | redirected to. The default value is   |
   |             |        | **${port}**, indicating that the port |
   |             |        | of the request will be used.          |
   |             |        |                                       |
   |             |        | Default: **${port}**                  |
   |             |        | Minimum: **1**                        |
   |             |        | Maximum: **16**                       |
   +-------------+--------+---------------------------------------+
   | path        | String | Specifies the path that requests are  |
   |             |        | redirected to. The default value is   |
   |             |        | **${path}**, indicating that the path |
   |             |        | of the request will be used. The      |
   |             |        | value can contain only letters,       |
   |             |        | digits, and special characters        |
   |             |        | \_-';@^- %#&$.*+?,=!:&vert;/()[]{}    |
   |             |        | must start with a slash (/).          |
   |             |        |                                       |
   |             |        | Default: **${path}**                  |
   |             |        | Minimum: **1**                        |
   |             |        | Maximum: **128**                      |
   +-------------+--------+---------------------------------------+
   | query       | String | Specifies the query string set in the |
   |             |        | URL for redirection. The default      |
   |             |        | value is **${query}**, indicating     |
   |             |        | that the query string of the request  |
   |             |        | will be used.                         |
   |             |        |                                       |
   |             |        | For example, in the URL               |
   |             |        | **https://www.                        |
   |             |        | xxx.com:8080/elb?type=loadbalancer**, |
   |             |        | **${query}** indicates                |
   |             |        | **type=loadbalancer**. If this        |
   |             |        | parameter is set to                   |
   |             |        | **${query}&name=my_name**, the URL    |
   |             |        | will be redirected to                 |
   |             |        | **https://www.xxx.com:8080/           |
   |             |        | elb?type=loadbalancer&name=my_name**. |
   |             |        |                                       |
   |             |        | The value is case-sensitive and can   |
   |             |        | contain only letters, digits, and     |
   |             |        | special characters                    |
   |             |        | !$&'()*+,-./:;=?@^_\`                 |
   |             |        |                                       |
   |             |        | Default: **${query}**                 |
   |             |        | Minimum: **0**                        |
   |             |        | Maximum: **128**                      |
   +-------------+--------+---------------------------------------+
   | status_code | String | Specifies the status code returned    |
   |             |        | after the requests are redirected.    |
   |             |        |                                       |
   |             |        | Value options:                        |
   |             |        |                                       |
   |             |        | -  **301**                            |
   |             |        | -  **302**                            |
   |             |        | -  **303**                            |
   |             |        | -  **307**                            |
   |             |        | -  **308**                            |
   |             |        |                                       |
   |             |        | Minimum: **1**                        |
   |             |        | Maximum: **16**                       |
   +-------------+--------+---------------------------------------+

.. _dl7pl_frc:
.. table:: **Table 9** FixtedResponseConfig

   +--------------+--------+---------------------------------------+
   | Parameter    | Type   | Description                           |
   +==============+========+=======================================+
   | status_code  | String | Specifies the HTTP status code        |
   |              |        | configured in the forwarding policy.  |
   |              |        | The value can be any integer in the   |
   |              |        | range of 200–299, 400–499, or         |
   |              |        | 500–599.                              |
   |              |        |                                       |
   |              |        | Minimum: **1**                        |
   |              |        | Maximum: **16**                       |
   +--------------+--------+---------------------------------------+
   | content_type | String | Specifies the format of the response  |
   |              |        | body.                                 |
   |              |        |                                       |
   |              |        | Value options:                        |
   |              |        |                                       |
   |              |        | -  **text/plain**                     |
   |              |        | -  **text/css**                       |
   |              |        | -  **text/html**                      |
   |              |        | -  **application/javascript**         |
   |              |        | -  **application/json**               |
   |              |        |                                       |
   |              |        | Minimum: **0**                        |
   |              |        | Maximum: **32**                       |
   +--------------+--------+---------------------------------------+
   | message_body | String | Specifies the content of the response |
   |              |        | body.                                 |
   |              |        |                                       |
   |              |        | Minimum: **0**                        |
   |              |        | Maximum: **1024**                     |
   +--------------+--------+---------------------------------------+

Example Requests
^^^^^^^^^^^^^^^^

.. code::

   GET

   https://{elb_endpoint}/v3/99a3fff0d03c428eac3678da6a7d0f24/elb/l7policies?display_all_rules=true

Example Responses
^^^^^^^^^^^^^^^^^

**Status code: 200**

Successful request.

.. code::

   {
     "request_id" : "d3c67339-be91-4813-bb24-85728a5d326a",
     "l7policies" : [ {
       "redirect_pool_id" : "3b34340d-59e8-4c70-9ef5-b41b12023dc9",
       "description" : "",
       "admin_state_up" : true,
       "rules" : [ {
         "id" : "1e5f17df-feec-427e-a162-8e4e05e91085"
       } ],
       "project_id" : "99a3fff0d03c428eac3678da6a7d0f24",
       "listener_id" : "e2220d2a-3faf-44f3-8cd6-0c42952bd0ab",
       "action" : "REDIRECT_TO_POOL",
       "position" : 100,
       "provisioning_status" : "ACTIVE",
       "id" : "0d7bf316-2e03-411f-bf29-c403c04e52bf",
       "name" : "elbv3"
     }, {
       "redirect_pool_id" : "3b34340d-59e8-4c70-9ef5-b41b12023dc9",
       "description" : "",
       "admin_state_up" : true,
       "rules" : [ {
         "id" : "0f5e8c34-09d1-4588-8459-f9b9add0be05"
       } ],
       "project_id" : "99a3fff0d03c428eac3678da6a7d0f24",
       "listener_id" : "e2220d2a-3faf-44f3-8cd6-0c42952bd0ab",
       "action" : "REDIRECT_TO_POOL",
       "position" : 100,
       "provisioning_status" : "ERROR",
       "id" : "2587d8b1-9e8d-459c-9081-7bccaa075d2b",
       "name" : "elbv3"
     } ],
     "page_info" : {
       "next_marker" : "2587d8b1-9e8d-459c-9081-7bccaa075d2b",
       "previous_marker" : "0d7bf316-2e03-411f-bf29-c403c04e52bf",
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

Viewing Details of a Forwarding Policy
======================================

Function
^^^^^^^^

This API is used to view details of a forwarding policy.

URI
^^^

GET /v3/{project_id}/elb/l7policies/{l7policy_id}

.. table:: **Table 1** Path parameters

   =========== ========= ====== ===================================
   Parameter   Mandatory Type   Description
   =========== ========= ====== ===================================
   project_id  Yes       String Specifies the project ID.
   l7policy_id Yes       String Specifies the forwarding policy ID.
   =========== ========= ====== ===================================

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

   +------------+-----------------------+----------------------------------------+
   | Parameter  | Type                  | Description                            |
   +============+=======================+========================================+
   | request_id | String                | Specifies the request ID. The value is |
   |            |                       | automatically generated.               |
   +------------+-----------------------+----------------------------------------+
   | l7policy   | :ref:`dl7ps_p` object | Specifies the forwarding policy.       |
   +------------+-----------------------+----------------------------------------+

.. _dl7ps_p:
.. table:: **Table 4** L7Policy

   +-----------------------+------------------+---------------------------------------+
   | Parameter             | Type             | Description                           |
   +=======================+==================+=======================================+
   | action                | String           | Specifies where requests will be      |
   |                       |                  | forwarded. The value can be one of    |
   |                       |                  | the following:                        |
   |                       |                  |                                       |
   |                       |                  | -  **REDIRECT_TO_POOL**: Requests     |
   |                       |                  |    will be forwarded to another       |
   |                       |                  |    backend server group.              |
   |                       |                  |                                       |
   |                       |                  | -  **REDIRECT_TO_LISTENER**: Requests |
   |                       |                  |    will be redirected to an HTTPS     |
   |                       |                  |    listener.                          |
   |                       |                  |                                       |
   |                       |                  | **REDIRECT_TO_LISTENER** has the      |
   |                       |                  | highest priority. If requests are to  |
   |                       |                  | be redirected to an HTTPS listener,   |
   |                       |                  | other forwarding policies of the      |
   |                       |                  | listener will become invalid.         |
   +-----------------------+------------------+---------------------------------------+
   | admin_state_up        | Boolean          | Specifies the administrative status   |
   |                       |                  | of the forwarding policy. The default |
   |                       |                  | value is **true**.                    |
   |                       |                  |                                       |
   |                       |                  | This parameter is unsupported. Please |
   |                       |                  | do not use it.                        |
   |                       |                  |                                       |
   |                       |                  | Default: **true**                     |
   +-----------------------+------------------+---------------------------------------+
   | description           | String           | Provides supplementary information    |
   |                       |                  | about the forwarding policy.          |
   +-----------------------+------------------+---------------------------------------+
   | id                    | String           | Specifies the forwarding policy ID.   |
   +-----------------------+------------------+---------------------------------------+
   | listener_id           | String           | Specifies the ID of the listener to   |
   |                       |                  | which the forwarding policy is added. |
   |                       |                  |                                       |
   |                       |                  | -  If **action** is set to            |
   |                       |                  |    **REDIRECT_TO_POOL**, the          |
   |                       |                  |    forwarding policy can be added to  |
   |                       |                  |    an HTTP or HTTPS listener.         |
   |                       |                  |                                       |
   |                       |                  | -  If **action** is set to            |
   |                       |                  |    **REDIRECT_TO_LISTENER**, the      |
   |                       |                  |    forwarding policy can be added to  |
   |                       |                  |    an HTTP listener.                  |
   +-----------------------+------------------+---------------------------------------+
   | name                  | String           | Specifies the forwarding policy name. |
   |                       |                  |                                       |
   |                       |                  | Minimum: **1**                        |
   |                       |                  | Maximum: **255**                      |
   +-----------------------+------------------+---------------------------------------+
   | position              | Integer          | Specifies the forwarding policy       |
   |                       |                  | priority. This parameter cannot be    |
   |                       |                  | updated.                              |
   |                       |                  |                                       |
   |                       |                  | This parameter is unsupported. Please |
   |                       |                  | do not use it.                        |
   |                       |                  |                                       |
   |                       |                  | Minimum: **1**                        |
   |                       |                  | Maximum: **100**                      |
   +-----------------------+------------------+---------------------------------------+
   | project_id            | String           | Specifies the project ID of the       |
   |                       |                  | forwarding policy.                    |
   +-----------------------+------------------+---------------------------------------+
   | provisioning_status   | String           | Specifies the provisioning status of  |
   |                       |                  | the forwarding policy.                |
   |                       |                  |                                       |
   |                       |                  | The value can only be **ACTIVE**.     |
   |                       |                  |                                       |
   |                       |                  | Default: **ACTIVE**                   |
   +-----------------------+------------------+---------------------------------------+
   | redirect_listener_id  | String           | Specifies the ID of the listener that |
   |                       |                  | requests are redirected to.           |
   |                       |                  |                                       |
   |                       |                  | This parameter is valid and mandatory |
   |                       |                  | only when **action** is set to        |
   |                       |                  | **REDIRECT_TO_LISTENER**.             |
   |                       |                  |                                       |
   |                       |                  | Only HTTPS listeners are supported,   |
   |                       |                  | and the listener cannot be any        |
   |                       |                  | listener added to other load          |
   |                       |                  | balancers.                            |
   +-----------------------+------------------+---------------------------------------+
   | redirect_pool_id      | String           | Specifies the ID of the backend       |
   |                       |                  | server group that requests are        |
   |                       |                  | forwarded to.                         |
   |                       |                  |                                       |
   |                       |                  | This parameter is valid and mandatory |
   |                       |                  | only when **action** is set to        |
   |                       |                  | **REDIRECT_TO_POOL**.                 |
   |                       |                  |                                       |
   |                       |                  | The specified backend server group    |
   |                       |                  | cannot be the default one associated  |
   |                       |                  | with the listener, or any backend     |
   |                       |                  | server group associated with the      |
   |                       |                  | forwarding policies of other          |
   |                       |                  | listeners.                            |
   |                       |                  |                                       |
   |                       |                  | This parameter cannot be specified    |
   |                       |                  | when **action** is set to             |
   |                       |                  | **REDIRECT_TO_LISTENER**.             |
   +-----------------------+------------------+---------------------------------------+
   | redirect_url          | String           | Specifies the URL to which requests   |
   |                       |                  | are forwarded.                        |
   |                       |                  |                                       |
   |                       |                  | Format:                               |
   |                       |                  | *protocol://host:port/path?query*     |
   |                       |                  |                                       |
   |                       |                  | This parameter is unsupported. Please |
   |                       |                  | do not use it.                        |
   +-----------------------+------------------+---------------------------------------+
   | rules                 | Array of         | Lists the forwarding rules in the     |
   |                       | :ref:`dl7ps_rr`  | forwarding policy.                    |
   |                       | objects          |                                       |
   +-----------------------+------------------+---------------------------------------+
   | redirect_url_config   | :ref:`dl7ps_ruc` | Specifies the URL to which requests   |
   |                       | object           | are forwarded.                        |
   |                       |                  |                                       |
   |                       |                  | For shared load balancers, this       |
   |                       |                  | parameter is not supported. If it is  |
   |                       |                  | passed, an error will be returned.    |
   |                       |                  |                                       |
   |                       |                  | For dedicated load balancers, this    |
   |                       |                  | parameter will take effect only when  |
   |                       |                  | advanced forwarding is enabled        |
   |                       |                  | (**enhance_l7policy_enable** is set   |
   |                       |                  | to **true**). If it is passed when    |
   |                       |                  | **enhance_l7policy_enable** is set to |
   |                       |                  | **false**, an error will be returned. |
   |                       |                  |                                       |
   |                       |                  | Format:                               |
   |                       |                  | *protocol://host:port/path?query*     |
   |                       |                  |                                       |
   |                       |                  | At least one of the four parameters   |
   |                       |                  | (**protocol**, **host**, **port**,    |
   |                       |                  | and **path**) must be passed, or      |
   |                       |                  | their values cannot be set to         |
   |                       |                  | **${xxx}** at the same time.          |
   |                       |                  | (**${xxx}** indicates that the value  |
   |                       |                  | in the request will be inherited. For |
   |                       |                  | example, **${host}** indicates the    |
   |                       |                  | host in the URL to be redirected.)    |
   |                       |                  |                                       |
   |                       |                  | The values of **protocol** and        |
   |                       |                  | **port** cannot be the same as those  |
   |                       |                  | of the associated listener, and       |
   |                       |                  | either **host** or **path** must be   |
   |                       |                  | passed or their values cannot be      |
   |                       |                  | **${xxx}** at the same time.          |
   |                       |                  |                                       |
   |                       |                  | This parameter is unsupported. Please |
   |                       |                  | do not use it.                        |
   +-----------------------+------------------+---------------------------------------+
   | fixed_response_config | :ref:`dl7ps_frc` | Specifies the configuration of the    |
   |                       | object           | page that will be returned. This      |
   |                       |                  | parameter will take effect when       |
   |                       |                  | **enhance_l7policy_enable** is set to |
   |                       |                  | **true**. If this parameter is passed |
   |                       |                  | and **enhance_l7policy_enable** is    |
   |                       |                  | set to **false**, an error will be    |
   |                       |                  | returned. For shared load balancers,  |
   |                       |                  | this parameter is not supported. If   |
   |                       |                  | it is passed, an error will be        |
   |                       |                  | returned.                             |
   |                       |                  |                                       |
   |                       |                  | This parameter is unsupported. Please |
   |                       |                  | do not use it.                        |
   +-----------------------+------------------+---------------------------------------+
   | priority              | Integer          | Specifies the forwarding policy       |
   |                       |                  | priority. This parameter is available |
   |                       |                  | only for dedicated load balancers and |
   |                       |                  | will take effect when                 |
   |                       |                  | **enhance_l7policy_enable** is set to |
   |                       |                  | **true**.                             |
   |                       |                  |                                       |
   |                       |                  | A smaller value indicates a higher    |
   |                       |                  | priority. The value must be unique    |
   |                       |                  | for each forwarding policy of the     |
   |                       |                  | same listener.                        |
   |                       |                  |                                       |
   |                       |                  | If **action** is set to               |
   |                       |                  | **REDIRECT_TO_LISTENER**, the value   |
   |                       |                  | can only be **0**, indicating that    |
   |                       |                  | **REDIRECT_TO_LISTENER** has the      |
   |                       |                  | highest priority.                     |
   |                       |                  |                                       |
   |                       |                  | - If **enhance_l7policy_enable** is   |
   |                       |                  |   set to **false**, forwarding        |
   |                       |                  |   policies are automatically          |
   |                       |                  |   prioritized based on the original   |
   |                       |                  |   sorting logic. Forwarding policy    |
   |                       |                  |   priorities are independent of each  |
   |                       |                  |   other regardless of domain names.   |
   |                       |                  |   If forwarding policies use the      |
   |                       |                  |   same domain name, their priorities  |
   |                       |                  |   follow the order of exact match     |
   |                       |                  |   (**EQUAL_TO**), prefix match        |
   |                       |                  |   (**STARTS_WITH**), and regular      |
   |                       |                  |   expression match (**REGEX**). If    |
   |                       |                  |   prefix match is used for matching,  |
   |                       |                  |   the longer the path, the higher     |
   |                       |                  |   the priority. If a forwarding       |
   |                       |                  |   policy contains only a domain name  |
   |                       |                  |   without a path specified, the path  |
   |                       |                  |   is **/**, and prefix match is used  |
   |                       |                  |   by default.                         |
   |                       |                  |                                       |
   |                       |                  | - If **enhance_l7policy_enable** is   |
   |                       |                  |   set to **true** and this parameter  |
   |                       |                  |   is not passed, the priority will    |
   |                       |                  |   set to a sum of 1 and the highest   |
   |                       |                  |   priority of existing forwarding     |
   |                       |                  |   policy in the same listener by      |
   |                       |                  |   default. There will be two cases:   |
   |                       |                  |   a) If the highest priority of       |
   |                       |                  |   existing forwarding policies is     |
   |                       |                  |   the maximum (10,000), the           |
   |                       |                  |   forwarding policy will fail to      |
   |                       |                  |   create because the final priority   |
   |                       |                  |   for creating the forwarding policy  |
   |                       |                  |   is the sum of 1 and 10,000, which   |
   |                       |                  |   exceeds the maximum. In this case,  |
   |                       |                  |   please specify a value or adjust    |
   |                       |                  |   the priorities of existing          |
   |                       |                  |   forwarding policies. b) If no       |
   |                       |                  |   forwarding policies exist, the      |
   |                       |                  |   highest priority of existing        |
   |                       |                  |   forwarding policies will set to 1   |
   |                       |                  |   by default.                         |
   |                       |                  |                                       |
   |                       |                  | This parameter is unsupported. Please |
   |                       |                  | do not use it.                        |
   |                       |                  |                                       |
   |                       |                  | Minimum: **0**                        |
   |                       |                  | Maximum: **10000**                    |
   +-----------------------+------------------+---------------------------------------+

.. _dl7ps_rr:
.. table:: **Table 5** RuleRef

   ========= ====== =================================
   Parameter Type   Description
   ========= ====== =================================
   id        String Specifies the forwarding rule ID.
   ========= ====== =================================

.. _dl7ps_ruc:
.. table:: **Table 6** RedirectUrlConfig

   +-------------+--------+---------------------------------------+
   | Parameter   | Type   | Description                           |
   +=============+========+=======================================+
   | protocol    | String | Specifies the protocol for            |
   |             |        | redirection. The default value is     |
   |             |        | **${protocol}**, indicating that the  |
   |             |        | protocol of the request will be used. |
   |             |        |                                       |
   |             |        | Value options:                        |
   |             |        |                                       |
   |             |        | -  **HTTP**                           |
   |             |        | -  **HTTPS**                          |
   |             |        | -  **${protocol}**                    |
   |             |        |                                       |
   |             |        | Minimum: **1**                        |
   |             |        | Maximum: **36**                       |
   +-------------+--------+---------------------------------------+
   | host        | String | Specifies the host name that requests |
   |             |        | are redirected to. The value can      |
   |             |        | contain only letters, digits, hyphens |
   |             |        | (-), and periods (.) and must start   |
   |             |        | with a letter or digit. The default   |
   |             |        | value is **${host}**, indicating that |
   |             |        | the host of the request will be used. |
   |             |        |                                       |
   |             |        | Default: **${host}**                  |
   |             |        | Minimum: **1**                        |
   |             |        | Maximum: **128**                      |
   +-------------+--------+---------------------------------------+
   | port        | String | Specifies the port that requests are  |
   |             |        | redirected to. The default value is   |
   |             |        | **${port}**, indicating that the port |
   |             |        | of the request will be used.          |
   |             |        |                                       |
   |             |        | Default: **${port}**                  |
   |             |        | Minimum: **1**                        |
   |             |        | Maximum: **16**                       |
   +-------------+--------+---------------------------------------+
   | path        | String | Specifies the path that requests are  |
   |             |        | redirected to. The default value is   |
   |             |        | **${path}**, indicating that the path |
   |             |        | of the request will be used. The      |
   |             |        | value can contain only letters,       |
   |             |        | digits, and special characters        |
   |             |        | \_-';@^- %#&$.*+?,=!:&vert;/()[]{}    |
   |             |        | must start with a slash (/).          |
   |             |        |                                       |
   |             |        | Default: **${path}**                  |
   |             |        | Minimum: **1**                        |
   |             |        | Maximum: **128**                      |
   +-------------+--------+---------------------------------------+
   | query       | String | Specifies the query string set in the |
   |             |        | URL for redirection. The default      |
   |             |        | value is **${query}**, indicating     |
   |             |        | that the query string of the request  |
   |             |        | will be used.                         |
   |             |        |                                       |
   |             |        | For example, in the URL               |
   |             |        | **https://www.                        |
   |             |        | xxx.com:8080/elb?type=loadbalancer**, |
   |             |        | **${query}** indicates                |
   |             |        | **type=loadbalancer**. If this        |
   |             |        | parameter is set to                   |
   |             |        | **${query}&name=my_name**, the URL    |
   |             |        | will be redirected to                 |
   |             |        | **https://www.xxx.com:8080/           |
   |             |        | elb?type=loadbalancer&name=my_name**. |
   |             |        |                                       |
   |             |        | The value is case-sensitive and can   |
   |             |        | contain only letters, digits, and     |
   |             |        | special characters                    |
   |             |        | !$&'()*+,-./:;=?@^_\`                 |
   |             |        |                                       |
   |             |        | Default: **${query}**                 |
   |             |        | Minimum: **0**                        |
   |             |        | Maximum: **128**                      |
   +-------------+--------+---------------------------------------+
   | status_code | String | Specifies the status code returned    |
   |             |        | after the requests are redirected.    |
   |             |        |                                       |
   |             |        | Value options:                        |
   |             |        |                                       |
   |             |        | -  **301**                            |
   |             |        | -  **302**                            |
   |             |        | -  **303**                            |
   |             |        | -  **307**                            |
   |             |        | -  **308**                            |
   |             |        |                                       |
   |             |        | Minimum: **1**                        |
   |             |        | Maximum: **16**                       |
   +-------------+--------+---------------------------------------+

.. _dl7ps_frc:
.. table:: **Table 7** FixtedResponseConfig

   +--------------+--------+---------------------------------------+
   | Parameter    | Type   | Description                           |
   +==============+========+=======================================+
   | status_code  | String | Specifies the HTTP status code        |
   |              |        | configured in the forwarding policy.  |
   |              |        | The value can be any integer in the   |
   |              |        | range of 200–299, 400–499, or         |
   |              |        | 500–599.                              |
   |              |        |                                       |
   |              |        | Minimum: **1**                        |
   |              |        | Maximum: **16**                       |
   +--------------+--------+---------------------------------------+
   | content_type | String | Specifies the format of the response  |
   |              |        | body.                                 |
   |              |        |                                       |
   |              |        | Value options:                        |
   |              |        |                                       |
   |              |        | -  **text/plain**                     |
   |              |        | -  **text/css**                       |
   |              |        | -  **text/html**                      |
   |              |        | -  **application/javascript**         |
   |              |        | -  **application/json**               |
   |              |        |                                       |
   |              |        | Minimum: **0**                        |
   |              |        | Maximum: **32**                       |
   +--------------+--------+---------------------------------------+
   | message_body | String | Specifies the content of the response |
   |              |        | body.                                 |
   |              |        |                                       |
   |              |        | Minimum: **0**                        |
   |              |        | Maximum: **1024**                     |
   +--------------+--------+---------------------------------------+

Example Requests
^^^^^^^^^^^^^^^^

.. code::

   GET

   https://{elb_endpoint}/v3/99a3fff0d03c428eac3678da6a7d0f24/elb/l7policies/cf4360fd-8631-41ff-a6f5-b72c35da74be

Example Responses
^^^^^^^^^^^^^^^^^

**Status code: 200**

Successful request.

.. code::

   {
     "l7policy" : {
       "description" : "",
       "admin_state_up" : true,
       "rules" : [ ],
       "project_id" : "99a3fff0d03c428eac3678da6a7d0f24",
       "listener_id" : "e2220d2a-3faf-44f3-8cd6-0c42952bd0ab",
       "redirect_listener_id" : "48a97732-449e-4aab-b561-828d29e45050",
       "action" : "REDIRECT_TO_LISTENER",
       "position" : 100,
       "provisioning_status" : "ACTIVE",
       "id" : "cf4360fd-8631-41ff-a6f5-b72c35da74be",
       "name" : ""
     },
     "request_id" : "6be83ec4-623e-4840-a417-2fcdf8ad5dfa"
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

Updating a Forwarding Policy
============================

Function
^^^^^^^^

This API is used to update a forwarding policy.

URI
^^^

PUT /v3/{project_id}/elb/l7policies/{l7policy_id}

.. table:: **Table 1** Path parameters

   =========== ========= ====== ===================================
   Parameter   Mandatory Type   Description
   =========== ========= ====== ===================================
   l7policy_id Yes       String Specifies the forwarding policy ID.
   project_id  Yes       String Specifies the project ID.
   =========== ========= ====== ===================================

Request Parameters
^^^^^^^^^^^^^^^^^^

.. table:: **Table 2** Request header parameters

   ============ ========= ====== ================================================
   Parameter    Mandatory Type   Description
   ============ ========= ====== ================================================
   X-Auth-Token Yes       String Specifies the token used for IAM authentication.
   ============ ========= ====== ================================================

.. table:: **Table 3** Request body parameters

   +-----------+-----------+------------------------+---------------------------------------------+
   | Parameter | Mandatory | Type                   | Description                                 |
   +===========+===========+========================+=============================================+
   | l7policy  | Yes       | :ref:`dl7pu_po` object | Specifies request parameters for updating a |
   |           |           |                        | forwarding policy.                          |
   +-----------+-----------+------------------------+---------------------------------------------+

.. _dl7pu_po:
.. table:: **Table 4** UpdateL7PolicyOption

   +-----------------------+-----------+------------------+-----------------------------------+
   | Parameter             | Mandatory | Type             | Description                       |
   +=======================+===========+==================+===================================+
   | admin_state_up        | No        | Boolean          | Specifies the                     |
   |                       |           |                  | administrative status of          |
   |                       |           |                  | the forwarding policy. The        |
   |                       |           |                  | default value is **true**.        |
   |                       |           |                  |                                   |
   |                       |           |                  | This parameter is                 |
   |                       |           |                  | unsupported. Please do not        |
   |                       |           |                  | use it.                           |
   |                       |           |                  |                                   |
   |                       |           |                  | Default: **true**                 |
   +-----------------------+-----------+------------------+-----------------------------------+
   | description           | No        | String           | Provides supplementary            |
   |                       |           |                  | information about the             |
   |                       |           |                  | forwarding policy.                |
   |                       |           |                  |                                   |
   |                       |           |                  | Minimum: **0**                    |
   |                       |           |                  | Maximum: **255**                  |
   +-----------------------+-----------+------------------+-----------------------------------+
   | name                  | No        | String           | Specifies the forwarding          |
   |                       |           |                  | policy name.                      |
   |                       |           |                  |                                   |
   |                       |           |                  | Minimum: **0**                    |
   |                       |           |                  | Maximum: **255**                  |
   +-----------------------+-----------+------------------+-----------------------------------+
   | redirect_listener_id  | No        | String           | Specifies the ID of the           |
   |                       |           |                  | listener that requests are        |
   |                       |           |                  | redirected to.                    |
   |                       |           |                  |                                   |
   |                       |           |                  | This parameter is valid and       |
   |                       |           |                  | mandatory only when               |
   |                       |           |                  | **action** is set to              |
   |                       |           |                  | **REDIRECT_TO_LISTENER**.         |
   |                       |           |                  |                                   |
   |                       |           |                  | Only HTTPS listeners are          |
   |                       |           |                  | supported, and the listener       |
   |                       |           |                  | cannot be any listener            |
   |                       |           |                  | added to other load               |
   |                       |           |                  | balancers.                        |
   +-----------------------+-----------+------------------+-----------------------------------+
   | redirect_pool_id      | No        | String           | Specifies the ID of the           |
   |                       |           |                  | backend server group that         |
   |                       |           |                  | requests are forwarded to.        |
   |                       |           |                  |                                   |
   |                       |           |                  | This parameter is valid and       |
   |                       |           |                  | mandatory only when               |
   |                       |           |                  | **action** is set to              |
   |                       |           |                  | **REDIRECT_TO_POOL**.             |
   |                       |           |                  |                                   |
   |                       |           |                  | The specified backend             |
   |                       |           |                  | server group cannot be the        |
   |                       |           |                  | default one associated with       |
   |                       |           |                  | the listener, or any              |
   |                       |           |                  | backend server group              |
   |                       |           |                  | associated with the               |
   |                       |           |                  | forwarding policies of            |
   |                       |           |                  | other listeners.                  |
   |                       |           |                  |                                   |
   |                       |           |                  | This parameter cannot be          |
   |                       |           |                  | specified when **action**         |
   |                       |           |                  | is set to                         |
   |                       |           |                  | **REDIRECT_TO_LISTENER**.         |
   +-----------------------+-----------+------------------+-----------------------------------+
   | redirect_url_config   | No        | :ref:`dl7pu_ruc` | Specifies the URL to which        |
   |                       |           | object           | requests are forwarded.           |
   |                       |           |                  |                                   |
   |                       |           |                  | For shared load balancers,        |
   |                       |           |                  | this parameter is not             |
   |                       |           |                  | supported. If it is passed,       |
   |                       |           |                  | an error will be returned.        |
   |                       |           |                  |                                   |
   |                       |           |                  | For dedicated load                |
   |                       |           |                  | balancers, this parameter         |
   |                       |           |                  | will take effect only when        |
   |                       |           |                  | advanced forwarding is            |
   |                       |           |                  | enabled                           |
   |                       |           |                  | (                                 |
   |                       |           |                  | **enhance_l7policy_enable**       |
   |                       |           |                  | is set to **true**). If it        |
   |                       |           |                  | is passed when                    |
   |                       |           |                  | **enhance_l7policy_enable**       |
   |                       |           |                  | is set to **false**, an           |
   |                       |           |                  | error will be returned.           |
   |                       |           |                  |                                   |
   |                       |           |                  | Format:                           |
   |                       |           |                  | *protocol://host:port/path?query* |
   |                       |           |                  |                                   |
   |                       |           |                  | At least one of the four          |
   |                       |           |                  | parameters (**protocol**,         |
   |                       |           |                  | **host**, **port**, and           |
   |                       |           |                  | **path**) must be passed,         |
   |                       |           |                  | or their values cannot be         |
   |                       |           |                  | set to **${xxx}** at the          |
   |                       |           |                  | same time. (**${xxx}**            |
   |                       |           |                  | indicates that the value in       |
   |                       |           |                  | the request will be               |
   |                       |           |                  | inherited. For example,           |
   |                       |           |                  | **${host}** indicates the         |
   |                       |           |                  | host in the URL to be             |
   |                       |           |                  | redirected.)                      |
   |                       |           |                  |                                   |
   |                       |           |                  | The values of **protocol**        |
   |                       |           |                  | and **port** cannot be the        |
   |                       |           |                  | same as those of the              |
   |                       |           |                  | associated listener, and          |
   |                       |           |                  | either **host** or **path**       |
   |                       |           |                  | must be passed or their           |
   |                       |           |                  | values cannot be **${xxx}**       |
   |                       |           |                  | at the same time.                 |
   |                       |           |                  |                                   |
   |                       |           |                  | This parameter is                 |
   |                       |           |                  | unsupported. Please do not        |
   |                       |           |                  | use it.                           |
   +-----------------------+-----------+------------------+-----------------------------------+
   | fixed_response_config | No        | :ref:`dl7pu_frc` | Specifies the configuration       |
   |                       |           | object           | of the page that will be          |
   |                       |           |                  | returned. This parameter          |
   |                       |           |                  | will take effect when             |
   |                       |           |                  | **enhance_l7policy_enable**       |
   |                       |           |                  | is set to **true**. If this       |
   |                       |           |                  | parameter is passed and           |
   |                       |           |                  | **enhance_l7policy_enable**       |
   |                       |           |                  | is set to **false**, an           |
   |                       |           |                  | error will be returned. For       |
   |                       |           |                  | shared load balancers, this       |
   |                       |           |                  | parameter is not supported.       |
   |                       |           |                  | If it is passed, an error         |
   |                       |           |                  | will be returned.                 |
   |                       |           |                  |                                   |
   |                       |           |                  | This parameter is                 |
   |                       |           |                  | unsupported. Please do not        |
   |                       |           |                  | use it.                           |
   +-----------------------+-----------+------------------+-----------------------------------+
   | rules                 | No        | Array of         | Lists the forwarding rules        |
   |                       |           | :ref:`dl7pu_ro`  | in the forwarding policy.         |
   |                       |           | objects          |                                   |
   |                       |           |                  | The list can contain a            |
   |                       |           |                  | maximum of 10 forwarding          |
   |                       |           |                  | rules (if **conditions** is       |
   |                       |           |                  | specified, a condition is         |
   |                       |           |                  | considered as a rule).            |
   |                       |           |                  |                                   |
   |                       |           |                  | If **type** is set to             |
   |                       |           |                  | **HOST_NAME**, **PATH**,          |
   |                       |           |                  | **METHOD**, or                    |
   |                       |           |                  | **SOURCE_IP**, only one           |
   |                       |           |                  | forwarding rule can be            |
   |                       |           |                  | created for each type.            |
   +-----------------------+-----------+------------------+-----------------------------------+
   | priority              | No        | Integer          | Specifies the forwarding          |
   |                       |           |                  | policy priority. This             |
   |                       |           |                  | parameter is available only       |
   |                       |           |                  | for dedicated load                |
   |                       |           |                  | balancers and will take           |
   |                       |           |                  | effect when                       |
   |                       |           |                  | **enhance_l7policy_enable**       |
   |                       |           |                  | is set to **true**. If this       |
   |                       |           |                  | parameter is passed and           |
   |                       |           |                  | **enhance_l7policy_enable**       |
   |                       |           |                  | is set to **false**, an           |
   |                       |           |                  | error will be returned. For       |
   |                       |           |                  | shared load balancers, this       |
   |                       |           |                  | parameter is not supported.       |
   |                       |           |                  | If it is passed, an error         |
   |                       |           |                  | will be returned.                 |
   |                       |           |                  |                                   |
   |                       |           |                  | A smaller value indicates a       |
   |                       |           |                  | higher priority. The value        |
   |                       |           |                  | must be unique for                |
   |                       |           |                  | forwarding policies of the        |
   |                       |           |                  | same listener.                    |
   |                       |           |                  |                                   |
   |                       |           |                  | If **action** is set to           |
   |                       |           |                  | **REDIRECT_TO_LISTENER**,         |
   |                       |           |                  | the value can only be             |
   |                       |           |                  | **0**, indicating that            |
   |                       |           |                  | **REDIRECT_TO_LISTENER**          |
   |                       |           |                  | has the highest priority.         |
   |                       |           |                  |                                   |
   |                       |           |                  | This parameter is                 |
   |                       |           |                  | unsupported. Please do not        |
   |                       |           |                  | use it.                           |
   |                       |           |                  |                                   |
   |                       |           |                  | Minimum: **0**                    |
   |                       |           |                  | Maximum: **10000**                |
   +-----------------------+-----------+------------------+-----------------------------------+

.. _dl7pu_ruc:
.. table:: **Table 5** UpdateRedirectUrlConfig

   +-------------+-----------+--------+-----------------------------+
   | Parameter   | Mandatory | Type   | Description                 |
   +=============+===========+========+=============================+
   | protocol    | No        | String | Specifies the protocol for  |
   |             |           |        | redirection. The default    |
   |             |           |        | value is **${protocol}**,   |
   |             |           |        | indicating that the         |
   |             |           |        | protocol of the request     |
   |             |           |        | will be used.               |
   |             |           |        |                             |
   |             |           |        | Value options:              |
   |             |           |        |                             |
   |             |           |        | -  **HTTP**                 |
   |             |           |        | -  **HTTPS**                |
   |             |           |        | -  **${protocol}**          |
   |             |           |        |                             |
   |             |           |        | Minimum: **1**              |
   |             |           |        | Maximum: **36**             |
   +-------------+-----------+--------+-----------------------------+
   | host        | No        | String | Specifies the host name     |
   |             |           |        | that requests are           |
   |             |           |        | redirected to. The value    |
   |             |           |        | can contain only letters,   |
   |             |           |        | digits, hyphens (-), and    |
   |             |           |        | periods (.) and must start  |
   |             |           |        | with a letter or digit. The |
   |             |           |        | default value is            |
   |             |           |        | **${host}**, indicating     |
   |             |           |        | that the host of the        |
   |             |           |        | request will be used.       |
   |             |           |        |                             |
   |             |           |        | Default: **${host}**        |
   |             |           |        | Minimum: **1**              |
   |             |           |        | Maximum: **128**            |
   +-------------+-----------+--------+-----------------------------+
   | port        | No        | String | Specifies the port that     |
   |             |           |        | requests are redirected to. |
   |             |           |        | The default value is        |
   |             |           |        | **${port}**, indicating     |
   |             |           |        | that the port of the        |
   |             |           |        | request will be used.       |
   |             |           |        |                             |
   |             |           |        | Default: **${port}**        |
   |             |           |        | Minimum: **1**              |
   |             |           |        | Maximum: **16**             |
   +-------------+-----------+--------+-----------------------------+
   | path        | No        | String | Specifies the path that     |
   |             |           |        | requests are redirected to. |
   |             |           |        | The default value is        |
   |             |           |        | **${path}**, indicating     |
   |             |           |        | that the path of the        |
   |             |           |        | request will be used.       |
   |             |           |        |                             |
   |             |           |        | The value can contain only  |
   |             |           |        | letters, digits, and        |
   |             |           |        | special characters \_-';@^- |
   |             |           |        | %#&$.*+?,=!:&vert;/()[]{}   |
   |             |           |        | must start with a slash     |
   |             |           |        | (/).                        |
   |             |           |        |                             |
   |             |           |        | Default: **${path}**        |
   |             |           |        | Minimum: **1**              |
   |             |           |        | Maximum: **128**            |
   +-------------+-----------+--------+-----------------------------+
   | query       | No        | String | Specifies the query string  |
   |             |           |        | set in the URL for          |
   |             |           |        | redirection. The default    |
   |             |           |        | value is **${query}**,      |
   |             |           |        | indicating that the query   |
   |             |           |        | string of the request will  |
   |             |           |        | be used.                    |
   |             |           |        |                             |
   |             |           |        | For example, in the URL     |
   |             |           |        | **https://www.xxx.com:80    |
   |             |           |        | 80/elb?type=loadbalancer**, |
   |             |           |        | **${query}** indicates      |
   |             |           |        | **type=loadbalancer**. If   |
   |             |           |        | this parameter is set to    |
   |             |           |        | **${query}&name=my_name**,  |
   |             |           |        | the URL will be redirected  |
   |             |           |        | to                          |
   |             |           |        | **https://                  |
   |             |           |        | www.xxx.com:8080/elb?type=l |
   |             |           |        | oadbalancer&name=my_name**. |
   |             |           |        |                             |
   |             |           |        | The value is case-sensitive |
   |             |           |        | and can contain only        |
   |             |           |        | letters, digits, and        |
   |             |           |        | special characters          |
   |             |           |        | !$&'()*+,-./:;=?@^_\`       |
   |             |           |        |                             |
   |             |           |        | Default: **${query}**       |
   |             |           |        | Minimum: **0**              |
   |             |           |        | Maximum: **128**            |
   +-------------+-----------+--------+-----------------------------+
   | status_code | No        | String | Specifies the status code   |
   |             |           |        | returned after the requests |
   |             |           |        | are redirected.             |
   |             |           |        |                             |
   |             |           |        | Value options:              |
   |             |           |        |                             |
   |             |           |        | -  **301**                  |
   |             |           |        | -  **302**                  |
   |             |           |        | -  **303**                  |
   |             |           |        | -  **307**                  |
   |             |           |        | -  **308**                  |
   |             |           |        |                             |
   |             |           |        | Minimum: **1**              |
   |             |           |        | Maximum: **16**             |
   +-------------+-----------+--------+-----------------------------+

.. _dl7pu_frc:
.. table:: **Table 6** UpdateFixtedResponseConfig

   +--------------+-----------+--------+------------------------------+
   | Parameter    | Mandatory | Type   | Description                  |
   +==============+===========+========+==============================+
   | status_code  | No        | String | Specifies the HTTP status    |
   |              |           |        | code configured in the       |
   |              |           |        | forwarding rule. The value   |
   |              |           |        | can be any integer in the    |
   |              |           |        | range of 200–299, 400–499,   |
   |              |           |        | or 500–599.                  |
   |              |           |        |                              |
   |              |           |        | Minimum: **1**               |
   |              |           |        |                              |
   |              |           |        | Maximum: **16**              |
   +--------------+-----------+--------+------------------------------+
   | content_type | No        | String | Specifies the format of the  |
   |              |           |        | response body.               |
   |              |           |        |                              |
   |              |           |        | Value options:               |
   |              |           |        |                              |
   |              |           |        | - **text/plain**             |
   |              |           |        | - **text/css**               |
   |              |           |        | - **text/html**              |
   |              |           |        | - **application/javascript** |
   |              |           |        | - **application/json**       |
   |              |           |        |                              |
   |              |           |        | Minimum: **1**               |
   |              |           |        | Maximum: **64**              |
   +--------------+-----------+--------+------------------------------+
   | message_body | No        | String | Specifies the content of     |
   |              |           |        | the response body.           |
   |              |           |        |                              |
   |              |           |        | Minimum: **0**               |
   |              |           |        | Maximum: **1024**            |
   +--------------+-----------+--------+------------------------------+

.. _dl7pu_ro:
.. table:: **Table 7** UpdateL7RuleOption

   +----------------+-----------+------------------+--------------------------------+
   | Parameter      | Mandatory | Type             | Description                    |
   +================+===========+==================+================================+
   | admin_state_up | No        | Boolean          | Specifies the                  |
   |                |           |                  | administrative status of       |
   |                |           |                  | the forwarding rule. The       |
   |                |           |                  | default value is **true**.     |
   |                |           |                  |                                |
   |                |           |                  | This parameter is              |
   |                |           |                  | unsupported. Please do not     |
   |                |           |                  | use it.                        |
   +----------------+-----------+------------------+--------------------------------+
   | compare_type   | No        | String           | Specifies how requests are     |
   |                |           |                  | matched with the domain        |
   |                |           |                  | name or URL.                   |
   |                |           |                  |                                |
   |                |           |                  | - If **type** is set to        |
   |                |           |                  |   **HOST_NAME**, this          |
   |                |           |                  |   parameter can only be        |
   |                |           |                  |   set to **EQUAL_TO**.         |
   |                |           |                  |                                |
   |                |           |                  | - If **type** is set to        |
   |                |           |                  |   **PATH**, this parameter     |
   |                |           |                  |   can be set to **REGEX**,     |
   |                |           |                  |   **STARTS_WITH**, or          |
   |                |           |                  |   **EQUAL_TO**.                |
   +----------------+-----------+------------------+--------------------------------+
   | invert         | No        | Boolean          | Specifies whether reverse      |
   |                |           |                  | matching is supported. The     |
   |                |           |                  | value is fixed at              |
   |                |           |                  | **false**. This parameter      |
   |                |           |                  | can be updated but remains     |
   |                |           |                  | invalid.                       |
   +----------------+-----------+------------------+--------------------------------+
   | key            | No        | String           | Specifies the key of the       |
   |                |           |                  | match item. For example, if    |
   |                |           |                  | an HTTP header is used for     |
   |                |           |                  | matching, **key** is the       |
   |                |           |                  | name of the HTTP header        |
   |                |           |                  | parameter.                     |
   |                |           |                  |                                |
   |                |           |                  | This parameter is              |
   |                |           |                  | unsupported. Please do not     |
   |                |           |                  | use it.                        |
   |                |           |                  |                                |
   |                |           |                  | Minimum: **1**                 |
   |                |           |                  | Maximum: **255**               |
   +----------------+-----------+------------------+--------------------------------+
   | value          | No        | String           | Specifies the value of the     |
   |                |           |                  | match item. For example, if    |
   |                |           |                  | a domain name is used for      |
   |                |           |                  | matching, **value** is the     |
   |                |           |                  | domain name.                   |
   |                |           |                  |                                |
   |                |           |                  | - If **type** is set to        |
   |                |           |                  |   **HOST_NAME**, the value     |
   |                |           |                  |   can contain letters,         |
   |                |           |                  |   digits, hyphens (-), and     |
   |                |           |                  |   periods (.) and must         |
   |                |           |                  |   start with a letter or       |
   |                |           |                  |   digit. If you want to        |
   |                |           |                  |   use a wildcard domain        |
   |                |           |                  |   name, enter an asterisk      |
   |                |           |                  |   (*) as the leftmost          |
   |                |           |                  |   label of the domain          |
   |                |           |                  |   name.                        |
   |                |           |                  |                                |
   |                |           |                  | - If **type** is set to        |
   |                |           |                  |   **PATH** and                 |
   |                |           |                  |   **compare_type** to          |
   |                |           |                  |   **STARTS_WITH** or           |
   |                |           |                  |   **EQUAL_TO**, the value      |
   |                |           |                  |   must start with a slash      |
   |                |           |                  |   (/) and can contain only     |
   |                |           |                  |   letters, digits, and         |
   |                |           |                  |   special characters           |
   |                |           |                  |   \ _~';@^-%#&$.*+?,=!:/()[]{} |
   |                |           |                  |                                |
   |                |           |                  | Minimum: **1**                 |
   |                |           |                  | Maximum: **128**               |
   +----------------+-----------+------------------+--------------------------------+
   | conditions     | No        | Array of         | Specifies the matching         |
   |                |           | :ref:`dl7pu_urc` | conditions of the              |
   |                |           | objects          | forwarding rule. This          |
   |                |           |                  | parameter will take effect     |
   |                |           |                  | when                           |
   |                |           |                  | **enhance_l7policy_enable**    |
   |                |           |                  | is set to **true**.            |
   |                |           |                  |                                |
   |                |           |                  | If **conditions** is           |
   |                |           |                  | specified, the values of       |
   |                |           |                  | **key** and **value** are      |
   |                |           |                  | invalid, and its value         |
   |                |           |                  | contains all conditions        |
   |                |           |                  | configured for the             |
   |                |           |                  | forwarding rule. The keys      |
   |                |           |                  | in the list must be the        |
   |                |           |                  | same, whereas each value       |
   |                |           |                  | must be unique. Only full      |
   |                |           |                  | update is supported.           |
   |                |           |                  |                                |
   |                |           |                  | This parameter is              |
   |                |           |                  | unsupported. Please do not     |
   |                |           |                  | use it.                        |
   +----------------+-----------+------------------+--------------------------------+

.. _dl7pu_urc:
.. table:: **Table 8** UpdateRuleCondition

   +-----------+-----------+--------+--------------------------------------+
   | Parameter | Mandatory | Type   | Description                          |
   +===========+===========+========+======================================+
   | key       | No        | String | Specifies the key of match           |
   |           |           |        | item. This parameter is              |
   |           |           |        | left blank.                          |
   |           |           |        |                                      |
   |           |           |        | Minimum: **1**                       |
   |           |           |        | Maximum: **128**                     |
   +-----------+-----------+--------+--------------------------------------+
   | value     | No        | String | Specifies the value of the           |
   |           |           |        | match item.                          |
   |           |           |        |                                      |
   |           |           |        | - If **type** is set to              |
   |           |           |        |   **HOST_NAME**, **key**             |
   |           |           |        |   is left blank, and                 |
   |           |           |        |   **value** indicates the            |
   |           |           |        |   domain name, which can             |
   |           |           |        |   contain 1 to 128                   |
   |           |           |        |   characters, including              |
   |           |           |        |   letters, digits, hyphens           |
   |           |           |        |   (-), periods (.), and              |
   |           |           |        |   asterisks (*), and must            |
   |           |           |        |   start with a letter,               |
   |           |           |        |   digit, or asterisk (*).            |
   |           |           |        |   If you want to use a               |
   |           |           |        |   wildcard domain name,              |
   |           |           |        |   enter an asterisk (*) as           |
   |           |           |        |   the leftmost label of              |
   |           |           |        |   the domain name.                   |
   |           |           |        |                                      |
   |           |           |        | - If **type** is set to              |
   |           |           |        |   **PATH**, **key** is               |
   |           |           |        |   left blank, and                    |
   |           |           |        |   **value** indicates the            |
   |           |           |        |   request path, which can            |
   |           |           |        |   contain 1 to 128                   |
   |           |           |        |   characters. If                     |
   |           |           |        |   **compare_type** is set            |
   |           |           |        |   to **STARTS_WITH** or              |
   |           |           |        |   **EQUAL_TO** for the               |
   |           |           |        |   forwarding rule, the               |
   |           |           |        |   value must start with a            |
   |           |           |        |   slash (/) and can                  |
   |           |           |        |   contain only letters,              |
   |           |           |        |   digits, and special                |
   |           |           |        |   characters                         |
   |           |           |        |   \ _~';@^-%#&$.*+?,=!:&vert;/()[]{} |
   |           |           |        |                                      |
   |           |           |        | Minimum: **1**                       |
   |           |           |        | Maximum: **128**                     |
   +-----------+-----------+--------+--------------------------------------+

Response Parameters
^^^^^^^^^^^^^^^^^^^

**Status code: 200**

.. table:: **Table 9** Response body parameters

   +------------+------------------------+----------------------------------------+
   | Parameter  | Type                   | Description                            |
   +============+========================+========================================+
   | request_id | String                 | Specifies the request ID. The value is |
   |            |                        | automatically generated.               |
   +------------+------------------------+----------------------------------------+
   | l7policy   | :ref:`dl7pu_rp` object | Specifies the forwarding policy.       |
   +------------+------------------------+----------------------------------------+

.. _dl7pu_rp:
.. table:: **Table 10** L7Policy

   +-----------------------+-------------------+---------------------------------------+
   | Parameter             | Type              | Description                           |
   +=======================+===================+=======================================+
   | action                | String            | Specifies where requests will be      |
   |                       |                   | forwarded. The value can be one of    |
   |                       |                   | the following:                        |
   |                       |                   |                                       |
   |                       |                   | - **REDIRECT_TO_POOL**: Requests      |
   |                       |                   |   will be forwarded to another        |
   |                       |                   |   backend server group.               |
   |                       |                   |                                       |
   |                       |                   | - **REDIRECT_TO_LISTENER**: Requests  |
   |                       |                   |   will be redirected to an HTTPS      |
   |                       |                   |   listener.                           |
   |                       |                   |                                       |
   |                       |                   | **REDIRECT_TO_LISTENER** has the      |
   |                       |                   | highest priority. If requests are to  |
   |                       |                   | be redirected to an HTTPS listener,   |
   |                       |                   | other forwarding policies of the      |
   |                       |                   | listener will become invalid.         |
   +-----------------------+-------------------+---------------------------------------+
   | admin_state_up        | Boolean           | Specifies the administrative status   |
   |                       |                   | of the forwarding policy. The default |
   |                       |                   | value is **true**.                    |
   |                       |                   |                                       |
   |                       |                   | This parameter is unsupported. Please |
   |                       |                   | do not use it.                        |
   |                       |                   |                                       |
   |                       |                   | Default: **true**                     |
   +-----------------------+-------------------+---------------------------------------+
   | description           | String            | Provides supplementary information    |
   |                       |                   | about the forwarding policy.          |
   +-----------------------+-------------------+---------------------------------------+
   | id                    | String            | Specifies the forwarding policy ID.   |
   +-----------------------+-------------------+---------------------------------------+
   | listener_id           | String            | Specifies the ID of the listener to   |
   |                       |                   | which the forwarding policy is added. |
   |                       |                   |                                       |
   |                       |                   | - If **action** is set to             |
   |                       |                   |   **REDIRECT_TO_POOL**, the           |
   |                       |                   |   forwarding policy can be added to   |
   |                       |                   |   an HTTP or HTTPS listener.          |
   |                       |                   |                                       |
   |                       |                   | - If **action** is set to             |
   |                       |                   |   **REDIRECT_TO_LISTENER**, the       |
   |                       |                   |   forwarding policy can be added to   |
   |                       |                   |   an HTTP listener.                   |
   +-----------------------+-------------------+---------------------------------------+
   | name                  | String            | Specifies the forwarding policy name. |
   |                       |                   |                                       |
   |                       |                   | Minimum: **1**                        |
   |                       |                   | Maximum: **255**                      |
   +-----------------------+-------------------+---------------------------------------+
   | position              | Integer           | Specifies the forwarding policy       |
   |                       |                   | priority. This parameter cannot be    |
   |                       |                   | updated.                              |
   |                       |                   |                                       |
   |                       |                   | This parameter is unsupported. Please |
   |                       |                   | do not use it.                        |
   |                       |                   |                                       |
   |                       |                   | Minimum: **1**                        |
   |                       |                   | Maximum: **100**                      |
   +-----------------------+-------------------+---------------------------------------+
   | project_id            | String            | Specifies the project ID of the       |
   |                       |                   | forwarding policy.                    |
   +-----------------------+-------------------+---------------------------------------+
   | provisioning_status   | String            | Specifies the provisioning status of  |
   |                       |                   | the forwarding policy.                |
   |                       |                   |                                       |
   |                       |                   | The value can only be **ACTIVE**.     |
   |                       |                   |                                       |
   |                       |                   | Default: **ACTIVE**                   |
   +-----------------------+-------------------+---------------------------------------+
   | redirect_listener_id  | String            | Specifies the ID of the listener that |
   |                       |                   | requests are redirected to.           |
   |                       |                   |                                       |
   |                       |                   | This parameter is valid and mandatory |
   |                       |                   | only when **action** is set to        |
   |                       |                   | **REDIRECT_TO_LISTENER**.             |
   |                       |                   |                                       |
   |                       |                   | Only HTTPS listeners are supported,   |
   |                       |                   | and the listener cannot be any        |
   |                       |                   | listener added to other load          |
   |                       |                   | balancers.                            |
   +-----------------------+-------------------+---------------------------------------+
   | redirect_pool_id      | String            | Specifies the ID of the backend       |
   |                       |                   | server group that requests are        |
   |                       |                   | forwarded to.                         |
   |                       |                   |                                       |
   |                       |                   | This parameter is valid and mandatory |
   |                       |                   | only when **action** is set to        |
   |                       |                   | **REDIRECT_TO_POOL**.                 |
   |                       |                   |                                       |
   |                       |                   | The specified backend server group    |
   |                       |                   | cannot be the default one associated  |
   |                       |                   | with the listener, or any backend     |
   |                       |                   | server group associated with the      |
   |                       |                   | forwarding policies of other          |
   |                       |                   | listeners.                            |
   |                       |                   |                                       |
   |                       |                   | This parameter cannot be specified    |
   |                       |                   | when **action** is set to             |
   |                       |                   | **REDIRECT_TO_LISTENER**.             |
   +-----------------------+-------------------+---------------------------------------+
   | redirect_url          | String            | Specifies the URL to which requests   |
   |                       |                   | are forwarded.                        |
   |                       |                   |                                       |
   |                       |                   | Format:                               |
   |                       |                   | *protocol://host:port/path?query*     |
   |                       |                   |                                       |
   |                       |                   | This parameter is unsupported. Please |
   |                       |                   | do not use it.                        |
   +-----------------------+-------------------+---------------------------------------+
   | rules                 | Array of          | Lists the forwarding rules in the     |
   |                       | :ref:`dl7pu_rr`   | forwarding policy.                    |
   |                       | objects           |                                       |
   +-----------------------+-------------------+---------------------------------------+
   | redirect_url_config   | :ref:`dl7pu_rruc` | Specifies the URL to which requests   |
   |                       | object            | are forwarded.                        |
   |                       |                   |                                       |
   |                       |                   | For shared load balancers, this       |
   |                       |                   | parameter is not supported. If it is  |
   |                       |                   | passed, an error will be returned.    |
   |                       |                   |                                       |
   |                       |                   | For dedicated load balancers, this    |
   |                       |                   | parameter will take effect only when  |
   |                       |                   | advanced forwarding is enabled        |
   |                       |                   | (**enhance_l7policy_enable** is set   |
   |                       |                   | to **true**). If it is passed when    |
   |                       |                   | **enhance_l7policy_enable** is set to |
   |                       |                   | **false**, an error will be returned. |
   |                       |                   |                                       |
   |                       |                   | Format:                               |
   |                       |                   | *protocol://host:port/path?query*     |
   |                       |                   |                                       |
   |                       |                   | At least one of the four parameters   |
   |                       |                   | (**protocol**, **host**, **port**,    |
   |                       |                   | and **path**) must be passed, or      |
   |                       |                   | their values cannot be set to         |
   |                       |                   | **${xxx}** at the same time.          |
   |                       |                   | (**${xxx}** indicates that the value  |
   |                       |                   | in the request will be inherited. For |
   |                       |                   | example, **${host}** indicates the    |
   |                       |                   | host in the URL to be redirected.)    |
   |                       |                   |                                       |
   |                       |                   | The values of **protocol** and        |
   |                       |                   | **port** cannot be the same as those  |
   |                       |                   | of the associated listener, and       |
   |                       |                   | either **host** or **path** must be   |
   |                       |                   | passed or their values cannot be      |
   |                       |                   | **${xxx}** at the same time.          |
   |                       |                   |                                       |
   |                       |                   | This parameter is unsupported. Please |
   |                       |                   | do not use it.                        |
   +-----------------------+-------------------+---------------------------------------+
   | fixed_response_config | :ref:`dl7pu_rfrc` | Specifies the configuration of the    |
   |                       | object            | page that will be returned. This      |
   |                       |                   | parameter will take effect when       |
   |                       |                   | **enhance_l7policy_enable** is set to |
   |                       |                   | **true**. If this parameter is passed |
   |                       |                   | and **enhance_l7policy_enable** is    |
   |                       |                   | set to **false**, an error will be    |
   |                       |                   | returned. For shared load balancers,  |
   |                       |                   | this parameter is not supported. If   |
   |                       |                   | it is passed, an error will be        |
   |                       |                   | returned.                             |
   |                       |                   |                                       |
   |                       |                   | This parameter is unsupported. Please |
   |                       |                   | do not use it.                        |
   +-----------------------+-------------------+---------------------------------------+
   | priority              | Integer           | Specifies the forwarding policy       |
   |                       |                   | priority. This parameter is available |
   |                       |                   | only for dedicated load balancers and |
   |                       |                   | will take effect when                 |
   |                       |                   | **enhance_l7policy_enable** is set to |
   |                       |                   | **true**.                             |
   |                       |                   |                                       |
   |                       |                   | A smaller value indicates a higher    |
   |                       |                   | priority. The value must be unique    |
   |                       |                   | for each forwarding policy of the     |
   |                       |                   | same listener.                        |
   |                       |                   |                                       |
   |                       |                   | If **action** is set to               |
   |                       |                   | **REDIRECT_TO_LISTENER**, the value   |
   |                       |                   | can only be **0**, indicating that    |
   |                       |                   | **REDIRECT_TO_LISTENER** has the      |
   |                       |                   | highest priority.                     |
   |                       |                   |                                       |
   |                       |                   | - If **enhance_l7policy_enable** is   |
   |                       |                   |   set to **false**, forwarding        |
   |                       |                   |   policies are automatically          |
   |                       |                   |   prioritized based on the original   |
   |                       |                   |   sorting logic. Forwarding policy    |
   |                       |                   |   priorities are independent of each  |
   |                       |                   |   other regardless of domain names.   |
   |                       |                   |   If forwarding policies use the      |
   |                       |                   |   same domain name, their priorities  |
   |                       |                   |   follow the order of exact match     |
   |                       |                   |   (**EQUAL_TO**), prefix match        |
   |                       |                   |   (**STARTS_WITH**), and regular      |
   |                       |                   |   expression match (**REGEX**). If    |
   |                       |                   |   prefix match is used for matching,  |
   |                       |                   |   the longer the path, the higher     |
   |                       |                   |   the priority. If a forwarding       |
   |                       |                   |   policy contains only a domain name  |
   |                       |                   |   without a path specified, the path  |
   |                       |                   |   is **/**, and prefix match is used  |
   |                       |                   |   by default.                         |
   |                       |                   |                                       |
   |                       |                   | - If **enhance_l7policy_enable** is   |
   |                       |                   |   set to **true** and this parameter  |
   |                       |                   |   is not passed, the priority will    |
   |                       |                   |   set to a sum of 1 and the highest   |
   |                       |                   |   priority of existing forwarding     |
   |                       |                   |   policy in the same listener by      |
   |                       |                   |   default. There will be two cases:   |
   |                       |                   |   a) If the highest priority of       |
   |                       |                   |   existing forwarding policies is     |
   |                       |                   |   the maximum (10,000), the           |
   |                       |                   |   forwarding policy will fail to      |
   |                       |                   |   create because the final priority   |
   |                       |                   |   for creating the forwarding policy  |
   |                       |                   |   is the sum of 1 and 10,000, which   |
   |                       |                   |   exceeds the maximum. In this case,  |
   |                       |                   |   please specify a value or adjust    |
   |                       |                   |   the priorities of existing          |
   |                       |                   |   forwarding policies. b) If no       |
   |                       |                   |   forwarding policies exist, the      |
   |                       |                   |   highest priority of existing        |
   |                       |                   |   forwarding policies will set to 1   |
   |                       |                   |   by default.                         |
   |                       |                   |                                       |
   |                       |                   | This parameter is unsupported. Please |
   |                       |                   | do not use it.                        |
   |                       |                   |                                       |
   |                       |                   | Minimum: **0**                        |
   |                       |                   | Maximum: **10000**                    |
   +-----------------------+-------------------+---------------------------------------+

.. _dl7pu_rr:
.. table:: **Table 11** RuleRef

   ========= ====== =================================
   Parameter Type   Description
   ========= ====== =================================
   id        String Specifies the forwarding rule ID.
   ========= ====== =================================

.. _dl7pu_rruc:
.. table:: **Table 12** RedirectUrlConfig

   +-------------+--------+----------------------------------------+
   | Parameter   | Type   | Description                            |
   +=============+========+========================================+
   | protocol    | String | Specifies the protocol for             |
   |             |        | redirection. The default value is      |
   |             |        | **${protocol}**, indicating that the   |
   |             |        | protocol of the request will be used.  |
   |             |        |                                        |
   |             |        | Value options:                         |
   |             |        |                                        |
   |             |        | -  **HTTP**                            |
   |             |        | -  **HTTPS**                           |
   |             |        | -  **${protocol}**                     |
   |             |        |                                        |
   |             |        | Minimum: **1**                         |
   |             |        | Maximum: **36**                        |
   +-------------+--------+----------------------------------------+
   | host        | String | Specifies the host name that requests  |
   |             |        | are redirected to. The value can       |
   |             |        | contain only letters, digits, hyphens  |
   |             |        | (-), and periods (.) and must start    |
   |             |        | with a letter or digit. The default    |
   |             |        | value is **${host}**, indicating that  |
   |             |        | the host of the request will be used.  |
   |             |        |                                        |
   |             |        | Default: **${host}**                   |
   |             |        | Minimum: **1**                         |
   |             |        | Maximum: **128**                       |
   +-------------+--------+----------------------------------------+
   | port        | String | Specifies the port that requests are   |
   |             |        | redirected to. The default value is    |
   |             |        | **${port}**, indicating that the port  |
   |             |        | of the request will be used.           |
   |             |        |                                        |
   |             |        | Default: **${port}**                   |
   |             |        | Minimum: **1**                         |
   |             |        | Maximum: **16**                        |
   +-------------+--------+----------------------------------------+
   | path        | String | Specifies the path that requests are   |
   |             |        | redirected to. The default value is    |
   |             |        | **${path}**, indicating that the path  |
   |             |        | of the request will be used. The       |
   |             |        | value can contain only letters,        |
   |             |        | digits, and special characters         |
   |             |        | \_-';@^- %#&$.*+?,=!:&vert;/()[]{} and |
   |             |        | must start with a slash (/).           |
   |             |        |                                        |
   |             |        | Default: **${path}**                   |
   |             |        | Minimum: **1**                         |
   |             |        | Maximum: **128**                       |
   +-------------+--------+----------------------------------------+
   | query       | String | Specifies the query string set in the  |
   |             |        | URL for redirection. The default       |
   |             |        | value is **${query}**, indicating      |
   |             |        | that the query string of the request   |
   |             |        | will be used.                          |
   |             |        |                                        |
   |             |        | For example, in the URL                |
   |             |        | **https://www.                         |
   |             |        | xxx.com:8080/elb?type=loadbalancer**,  |
   |             |        | **${query}** indicates                 |
   |             |        | **type=loadbalancer**. If this         |
   |             |        | parameter is set to                    |
   |             |        | **${query}&name=my_name**, the URL     |
   |             |        | will be redirected to                  |
   |             |        | **https://www.xxx.com:8080/            |
   |             |        | elb?type=loadbalancer&name=my_name**.  |
   |             |        |                                        |
   |             |        | The value is case-sensitive and can    |
   |             |        | contain only letters, digits, and      |
   |             |        | special characters                     |
   |             |        | !$&'()*+,-./:;=?@^_\`                  |
   |             |        |                                        |
   |             |        | Default: **${query}**                  |
   |             |        | Minimum: **0**                         |
   |             |        | Maximum: **128**                       |
   +-------------+--------+----------------------------------------+
   | status_code | String | Specifies the status code returned     |
   |             |        | after the requests are redirected.     |
   |             |        |                                        |
   |             |        | Value options:                         |
   |             |        |                                        |
   |             |        | -  **301**                             |
   |             |        | -  **302**                             |
   |             |        | -  **303**                             |
   |             |        | -  **307**                             |
   |             |        | -  **308**                             |
   |             |        |                                        |
   |             |        | Minimum: **1**                         |
   |             |        | Maximum: **16**                        |
   +-------------+--------+----------------------------------------+

.. _dl7pu_rfrc:
.. table:: **Table 13** FixtedResponseConfig

   +--------------+--------+---------------------------------------+
   | Parameter    | Type   | Description                           |
   +==============+========+=======================================+
   | status_code  | String | Specifies the HTTP status code        |
   |              |        | configured in the forwarding policy.  |
   |              |        | The value can be any integer in the   |
   |              |        | range of 200–299, 400–499, or         |
   |              |        | 500–599.                              |
   |              |        |                                       |
   |              |        | Minimum: **1**                        |
   |              |        | Maximum: **16**                       |
   +--------------+--------+---------------------------------------+
   | content_type | String | Specifies the format of the response  |
   |              |        | body.                                 |
   |              |        |                                       |
   |              |        | Value options:                        |
   |              |        |                                       |
   |              |        | -  **text/plain**                     |
   |              |        | -  **text/css**                       |
   |              |        | -  **text/html**                      |
   |              |        | -  **application/javascript**         |
   |              |        | -  **application/json**               |
   |              |        |                                       |
   |              |        | Minimum: **0**                        |
   |              |        | Maximum: **32**                       |
   +--------------+--------+---------------------------------------+
   | message_body | String | Specifies the content of the response |
   |              |        | body.                                 |
   |              |        |                                       |
   |              |        | Minimum: **0**                        |
   |              |        | Maximum: **1024**                     |
   +--------------+--------+---------------------------------------+

Example Requests
^^^^^^^^^^^^^^^^

.. code::

   PUT

   https://{elb_endpoint}/v3/99a3fff0d03c428eac3678da6a7d0f24/elb/l7policies/cf4360fd-8631-41ff-a6f5-b72c35da74be

   {
     "l7policy" : {
       "name" : "My policy.",
       "description" : "Update policy.",
       "redirect_listener_id" : "48a97732-449e-4aab-b561-828d29e45050"
     }
   }

Example Responses
^^^^^^^^^^^^^^^^^

**Status code: 200**

Successful request.

.. code::

   {
     "request_id" : "e5c07525-1470-47b6-9b0c-567527a036aa",
     "l7policy" : {
       "description" : "Update policy.",
       "admin_state_up" : true,
       "rules" : [ ],
       "project_id" : "99a3fff0d03c428eac3678da6a7d0f24",
       "listener_id" : "e2220d2a-3faf-44f3-8cd6-0c42952bd0ab",
       "redirect_listener_id" : "48a97732-449e-4aab-b561-828d29e45050",
       "action" : "REDIRECT_TO_LISTENER",
       "position" : 100,
       "provisioning_status" : "ACTIVE",
       "id" : "cf4360fd-8631-41ff-a6f5-b72c35da74be",
       "name" : "My policy."
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

Deleting a Forwarding Policy
============================

Function
^^^^^^^^

This API is used to delete a forwarding policy.

URI
^^^

DELETE /v3/{project_id}/elb/l7policies/{l7policy_id}

.. table:: **Table 1** Path parameters

   =========== ========= ====== ===================================
   Parameter   Mandatory Type   Description
   =========== ========= ====== ===================================
   project_id  Yes       String Specifies the project ID.
   l7policy_id Yes       String Specifies the forwarding policy ID.
   =========== ========= ====== ===================================

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

   https://{elb_endpoint}/v3/99a3fff0d03c428eac3678da6a7d0f24/elb/l7policies/cf4360fd-8631-41ff-a6f5-b72c35da74be

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

===============
Forwarding Rule
===============

Adding a Forwarding Rule
========================

Function
^^^^^^^^

This API is used to add a forwarding rule. After you add a forwarding rule, the
load balancer matches the domain name and path in the request and distributes
the traffic to the backend server group specified by **redirect_pool_id** of
the associated forwarding policy.

Constraints
^^^^^^^^^^^

The match type of forwarding rules in a forwarding policy must be unique.

URI
^^^

POST /v2.0/lbaas/l7policies/{l7policy_id}/rules

.. table:: **Table 1** Parameter description

   =========== ========= ====== ===================================
   Parameter   Mandatory Type   Description
   =========== ========= ====== ===================================
   l7policy_id Yes       String Specifies the forwarding policy ID.
   =========== ========= ====== ===================================

Request
^^^^^^^

.. table:: **Table 2** Parameter description

   +-----------+-----------+--------+-------------------------------------------------------------------+
   | Parameter | Mandatory | Type   | Description                                                       |
   +===========+===========+========+===================================================================+
   | rule      | Yes       | Object | Specifies the forwarding rule. For details, see :ref:`sl7rc_t3`.  |
   +-----------+-----------+--------+-------------------------------------------------------------------+

.. _sl7rc_t3:
.. table:: **Table 3** **rule** parameter description

   +----------------+-----------+---------+--------------------------------------+
   | Parameter      | Mandatory | Type    | Description                          |
   +================+===========+=========+======================================+
   | tenant_id      | No        | String  | Specifies the ID of the              |
   |                |           |         | project where the                    |
   |                |           |         | forwarding rule is used.             |
   |                |           |         |                                      |
   |                |           |         | The value must be the same           |
   |                |           |         | as the value of                      |
   |                |           |         | **project_id** in the                |
   |                |           |         | token.                               |
   |                |           |         |                                      |
   |                |           |         | The value contains a                 |
   |                |           |         | maximum of 255 characters.           |
   +----------------+-----------+---------+--------------------------------------+
   | admin_state_up | No        | Boolean | Specifies the                        |
   |                |           |         | administrative status of             |
   |                |           |         | the forwarding rule.                 |
   |                |           |         |                                      |
   |                |           |         | This parameter is reserved,          |
   |                |           |         | and the default value is             |
   |                |           |         | **true**.                            |
   +----------------+-----------+---------+--------------------------------------+
   | type           | Yes       | String  | Specifies the match type of          |
   |                |           |         | a forwarding rule.                   |
   |                |           |         |                                      |
   |                |           |         | The value can be one of the          |
   |                |           |         | following:                           |
   |                |           |         |                                      |
   |                |           |         | -  **HOST_NAME**: matches            |
   |                |           |         |    the domain name in the            |
   |                |           |         |    request.                          |
   |                |           |         | -  **PATH**: matches the             |
   |                |           |         |    path in the request.              |
   |                |           |         |                                      |
   |                |           |         | The match type of                    |
   |                |           |         | forwarding rules in a                |
   |                |           |         | forwarding policy must be            |
   |                |           |         | unique.                              |
   +----------------+-----------+---------+--------------------------------------+
   | compare_type   | Yes       | String  | Specifies the match mode.            |
   |                |           |         | The options are as follows:          |
   |                |           |         |                                      |
   |                |           |         | When **type** is set to              |
   |                |           |         | **HOST_NAME**, the value of          |
   |                |           |         | this parameter can only be           |
   |                |           |         | the following:                       |
   |                |           |         |                                      |
   |                |           |         | -  **EQUAL_TO**: indicates           |
   |                |           |         |    exact match.                      |
   |                |           |         |                                      |
   |                |           |         | When **type** is set to              |
   |                |           |         | **PATH**, the value of this          |
   |                |           |         | parameter can be one of the          |
   |                |           |         | following:                           |
   |                |           |         |                                      |
   |                |           |         | -  **REGEX**: indicates              |
   |                |           |         |    regular expression                |
   |                |           |         |    match.                            |
   |                |           |         | -  **STARTS_WITH**:                  |
   |                |           |         |    indicates prefix match.           |
   |                |           |         | -  **EQUAL_TO**: indicates           |
   |                |           |         |    exact match.                      |
   +----------------+-----------+---------+--------------------------------------+
   | invert         | No        | Boolean | Specifies whether reverse            |
   |                |           |         | matching is supported.               |
   |                |           |         |                                      |
   |                |           |         | The value can be **true**            |
   |                |           |         | or **false**. The default            |
   |                |           |         | value is **false**.                  |
   |                |           |         |                                      |
   |                |           |         | This parameter is reserved.          |
   +----------------+-----------+---------+--------------------------------------+
   | key            | No        | String  | Specifies the key of the             |
   |                |           |         | match content. The default           |
   |                |           |         | value is **null**.                   |
   |                |           |         |                                      |
   |                |           |         | This parameter is reserved.          |
   |                |           |         |                                      |
   |                |           |         | The value contains a                 |
   |                |           |         | maximum of 255 characters.           |
   +----------------+-----------+---------+--------------------------------------+
   | value          | Yes       | String  | Specifies the value of the           |
   |                |           |         | match content. The value             |
   |                |           |         | cannot contain spaces.               |
   |                |           |         |                                      |
   |                |           |         | The value contains a                 |
   |                |           |         | maximum of 128 characters.           |
   |                |           |         |                                      |
   |                |           |         | - When **type** is set to            |
   |                |           |         |   **HOST_NAME**, the value           |
   |                |           |         |   can contain a maximum of           |
   |                |           |         |   100 characters that                |
   |                |           |         |   contain only letters,              |
   |                |           |         |   digits, hyphens (-), and           |
   |                |           |         |   periods (.), and must              |
   |                |           |         |   start with a letter or             |
   |                |           |         |   digit.                             |
   |                |           |         | - When **type** is set to            |
   |                |           |         |   **PATH**, the value can            |
   |                |           |         |   contain a maximum of 128           |
   |                |           |         |   characters. When                   |
   |                |           |         |   **compare_type** is set            |
   |                |           |         |   to **STARTS_WITH** or              |
   |                |           |         |   **EQUAL_TO**, the value            |
   |                |           |         |   must start with a slash            |
   |                |           |         |   (/) and can contain only           |
   |                |           |         |   letters, digits, and               |
   |                |           |         |   special characters                 |
   |                |           |         |   \_~';@^-%#&$.*+?,=!:&vert;\/()[]{} |
   +----------------+-----------+---------+--------------------------------------+

Response
^^^^^^^^

.. table:: **Table 4** Response parameters

   +-----------+--------+--------------------------------------------------------------------+
   | Parameter | Type   | Description                                                        |
   +===========+========+====================================================================+
   | rule      | Object | Specifies the forwarding rule. For details, see :ref:`sl7rc_t5`.   |
   +-----------+--------+--------------------------------------------------------------------+

.. _sl7rc_t5:
.. table:: **Table 5** **rule** parameter description

   +---------------------+---------+---------------------------------------+
   | Parameter           | Type    | Description                           |
   +=====================+=========+=======================================+
   | id                  | String  | Specifies the forwarding rule ID.     |
   +---------------------+---------+---------------------------------------+
   | tenant_id           | String  | Specifies the ID of the project where |
   |                     |         | the forwarding rule is used.          |
   |                     |         |                                       |
   |                     |         | The value contains a maximum of 255   |
   |                     |         | characters.                           |
   +---------------------+---------+---------------------------------------+
   | admin_state_up      | Boolean | Specifies the administrative status   |
   |                     |         | of the forwarding rule.               |
   |                     |         |                                       |
   |                     |         | This parameter is reserved. The value |
   |                     |         | can be **true** or **false**.         |
   |                     |         |                                       |
   |                     |         | -  **true**: Enabled                  |
   |                     |         | -  **false**: Disabled                |
   +---------------------+---------+---------------------------------------+
   | type                | String  | Specifies the match type of a         |
   |                     |         | forwarding rule.                      |
   |                     |         |                                       |
   |                     |         | The value can be one of the           |
   |                     |         | following:                            |
   |                     |         |                                       |
   |                     |         | -  **HOST_NAME**: matches the domain  |
   |                     |         |    name in the request.               |
   |                     |         | -  **PATH**: matches the path in the  |
   |                     |         |    request.                           |
   +---------------------+---------+---------------------------------------+
   | compare_type        | String  | Specifies the match mode. The options |
   |                     |         | are as follows:                       |
   |                     |         |                                       |
   |                     |         | When **type** is set to               |
   |                     |         | **HOST_NAME**, the value of this      |
   |                     |         | parameter can only be the following:  |
   |                     |         |                                       |
   |                     |         | -  **EQUAL_TO**: indicates exact      |
   |                     |         |    match.                             |
   |                     |         |                                       |
   |                     |         | When **type** is set to **PATH**, the |
   |                     |         | value of this parameter can be one of |
   |                     |         | the following:                        |
   |                     |         |                                       |
   |                     |         | -  **REGEX**: indicates regular       |
   |                     |         |    expression match.                  |
   |                     |         | -  **STARTS_WITH**: indicates prefix  |
   |                     |         |    match.                             |
   |                     |         | -  **EQUAL_TO**: indicates exact      |
   |                     |         |    match.                             |
   +---------------------+---------+---------------------------------------+
   | invert              | Boolean | Specifies whether reverse matching is |
   |                     |         | supported.                            |
   |                     |         |                                       |
   |                     |         | The value can be **true** or          |
   |                     |         | **false**. The default value is       |
   |                     |         | **false**.                            |
   |                     |         |                                       |
   |                     |         | This parameter is reserved.           |
   +---------------------+---------+---------------------------------------+
   | key                 | String  | Specifies the key of the match        |
   |                     |         | content. The default value is         |
   |                     |         | **null**.                             |
   |                     |         |                                       |
   |                     |         | This parameter is reserved.           |
   |                     |         |                                       |
   |                     |         | The value contains a maximum of 255   |
   |                     |         | characters.                           |
   +---------------------+---------+---------------------------------------+
   | value               | String  | Specifies the value of the match      |
   |                     |         | content.                              |
   |                     |         |                                       |
   |                     |         | The value contains a maximum of 128   |
   |                     |         | characters.                           |
   |                     |         |                                       |
   |                     |         | -  When **type** is set to            |
   |                     |         |    **HOST_NAME**, the value can       |
   |                     |         |    contain a maximum of 100           |
   |                     |         |    characters that contain only       |
   |                     |         |    letters, digits, hyphens (-), and  |
   |                     |         |    periods (.), and must start with a |
   |                     |         |    letter or digit.                   |
   |                     |         | -  When **type** is set to **PATH**,  |
   |                     |         |    the value can contain a maximum of |
   |                     |         |    128 characters. When               |
   |                     |         |    **compare_type** is set to         |
   |                     |         |    **STARTS_WITH** or **EQUAL_TO**,   |
   |                     |         |    the value must start with a slash  |
   |                     |         |    (/) and can contain only letters,  |
   |                     |         |    digits, and special characters     |
   |                     |         |    \_~';@^-%#&$.*+?,=!:&vert;\/()[]{} |
   +---------------------+---------+---------------------------------------+
   | provisioning_status | String  | This parameter is reserved, and its   |
   |                     |         | value can only be **ACTIVE**.         |
   |                     |         |                                       |
   |                     |         | It specifies the provisioning status  |
   |                     |         | of the forwarding rule.               |
   +---------------------+---------+---------------------------------------+

Example Request
^^^^^^^^^^^^^^^

-  Example request: Adding a forwarding rule

   .. code::

      POST https://{Endpoint}/v2.0/lbaas/l7policies/5ae0e1e7-5f0f-47a1-b39f-5d4c428a1586/rules

      {
          "rule": {
              "compare_type": "EQUAL_TO",
              "type": "PATH",
              "value": "/bbb.html"
          }
      }

Example Response
^^^^^^^^^^^^^^^^

-  Example response

   .. code::

      {
          "rule": {
              "compare_type": "EQUAL_TO",
              "admin_state_up": true,
              "provisioning_status": "ACTIVE",
              "tenant_id": "a31d2bdcf7604c0faaddb058e1e08819",

              "invert": false,
              "value": "/bbb.html",
              "key": null,
              "type": "PATH",
              "id": "c6f457b8-bf6f-45d7-be5c-a3226945b7b1"
          }
      }

Status Code
^^^^^^^^^^^

See :ref:`shared_lb_status_code`.

Querying Forwarding Rules
=========================

Function
^^^^^^^^

This API is used to query forwarding rules. Filter query and pagination query
are supported. Unless otherwise specified, exact match is applied.

Constraints
^^^^^^^^^^^

Parameters **marker**, **limit**, and **page_reverse** are used for pagination
query. Parameters **marker** and **page_reverse** take effect only when they
are used together with parameter **limit**.

URI
^^^

GET /v2.0/lbaas/l7policies/{l7policy_id}/rules

.. table:: **Table 1** Parameter description

   =========== ========= ====== ===================================
   Parameter   Mandatory Type   Description
   =========== ========= ====== ===================================
   l7policy_id Yes       String Specifies the forwarding policy ID.
   =========== ========= ====== ===================================

Request
^^^^^^^

.. table:: **Table 2** Parameter description

   +---------------------+-----------+---------+--------------------------------------+
   | Parameter           | Mandatory | Type    | Description                          |
   +=====================+===========+=========+======================================+
   | marker              | No        | String  | Specifies the ID of the              |
   |                     |           |         | forwarding rule from which           |
   |                     |           |         | pagination query starts,             |
   |                     |           |         | that is, the ID of the last          |
   |                     |           |         | forwarding rule on the               |
   |                     |           |         | previous page.                       |
   |                     |           |         |                                      |
   |                     |           |         | This parameter must be used          |
   |                     |           |         | together with **limit**.             |
   +---------------------+-----------+---------+--------------------------------------+
   | limit               | No        | Integer | Specifies the number of              |
   |                     |           |         | forwarding rules on each             |
   |                     |           |         | page. If this parameter is           |
   |                     |           |         | not set, all forwarding              |
   |                     |           |         | rules are queried by                 |
   |                     |           |         | default.                             |
   +---------------------+-----------+---------+--------------------------------------+
   | page_reverse        | No        | Boolean | Specifies the page                   |
   |                     |           |         | direction. The value can be          |
   |                     |           |         | **true** or **false**, and           |
   |                     |           |         | the default value is                 |
   |                     |           |         | **false**. The last page in          |
   |                     |           |         | the list requested with              |
   |                     |           |         | **page_reverse** set to              |
   |                     |           |         | **false** will not contain           |
   |                     |           |         | the "next" link, and the             |
   |                     |           |         | last page in the list                |
   |                     |           |         | requested with                       |
   |                     |           |         | **page_reverse** set to              |
   |                     |           |         | **true** will not contain            |
   |                     |           |         | the "previous" link.                 |
   |                     |           |         |                                      |
   |                     |           |         | This parameter must be used          |
   |                     |           |         | together with **limit**.             |
   +---------------------+-----------+---------+--------------------------------------+
   | id                  | No        | String  | Specifies the forwarding             |
   |                     |           |         | rule ID.                             |
   +---------------------+-----------+---------+--------------------------------------+
   | tenant_id           | No        | String  | Specifies the ID of the              |
   |                     |           |         | project where the                    |
   |                     |           |         | forwarding rule is used.             |
   |                     |           |         |                                      |
   |                     |           |         | The value contains a                 |
   |                     |           |         | maximum of 255 characters.           |
   +---------------------+-----------+---------+--------------------------------------+
   | admin_state_up      | No        | Boolean | Specifies the                        |
   |                     |           |         | administrative status of             |
   |                     |           |         | the forwarding rule.                 |
   |                     |           |         |                                      |
   |                     |           |         | This parameter is reserved,          |
   |                     |           |         | and the default value is             |
   |                     |           |         | **true**.                            |
   +---------------------+-----------+---------+--------------------------------------+
   | type                | No        | String  | Specifies the match type of          |
   |                     |           |         | a forwarding rule.                   |
   |                     |           |         |                                      |
   |                     |           |         | The value can be one of the          |
   |                     |           |         | following:                           |
   |                     |           |         |                                      |
   |                     |           |         | -  **HOST_NAME**: matches            |
   |                     |           |         |    the domain name in the            |
   |                     |           |         |    request.                          |
   |                     |           |         | -  **PATH**: matches the             |
   |                     |           |         |    path in the request.              |
   |                     |           |         |                                      |
   |                     |           |         | The match type of                    |
   |                     |           |         | forwarding rules in a                |
   |                     |           |         | forwarding policy must be            |
   |                     |           |         | unique.                              |
   +---------------------+-----------+---------+--------------------------------------+
   | compare_type        | No        | String  | Specifies the match mode.            |
   |                     |           |         | The options are as follows:          |
   |                     |           |         |                                      |
   |                     |           |         | When **type** is set to              |
   |                     |           |         | **HOST_NAME**, the value of          |
   |                     |           |         | this parameter can only be           |
   |                     |           |         | the following:                       |
   |                     |           |         |                                      |
   |                     |           |         | -  **EQUAL_TO**: indicates           |
   |                     |           |         |    exact match.                      |
   |                     |           |         |                                      |
   |                     |           |         | When **type** is set to              |
   |                     |           |         | **PATH**, the value of this          |
   |                     |           |         | parameter can be one of the          |
   |                     |           |         | following:                           |
   |                     |           |         |                                      |
   |                     |           |         | -  **REGEX**: indicates              |
   |                     |           |         |    regular expression                |
   |                     |           |         |    match.                            |
   |                     |           |         | -  **STARTS_WITH**:                  |
   |                     |           |         |    indicates prefix match.           |
   |                     |           |         | -  **EQUAL_TO**: indicates           |
   |                     |           |         |    exact match.                      |
   +---------------------+-----------+---------+--------------------------------------+
   | invert              | No        | Boolean | Specifies whether reverse            |
   |                     |           |         | matching is supported.               |
   |                     |           |         |                                      |
   |                     |           |         | The value can be **true**            |
   |                     |           |         | or **false**. The default            |
   |                     |           |         | value is **false**.                  |
   |                     |           |         |                                      |
   |                     |           |         | This parameter is reserved.          |
   +---------------------+-----------+---------+--------------------------------------+
   | key                 | No        | String  | Specifies the key of the             |
   |                     |           |         | match content. The default           |
   |                     |           |         | value is **null**.                   |
   |                     |           |         |                                      |
   |                     |           |         | This parameter is reserved.          |
   |                     |           |         |                                      |
   |                     |           |         | The value contains a                 |
   |                     |           |         | maximum of 255 characters.           |
   +---------------------+-----------+---------+--------------------------------------+
   | value               | No        | String  | Specifies the value of the           |
   |                     |           |         | match content.                       |
   |                     |           |         |                                      |
   |                     |           |         | The value contains a                 |
   |                     |           |         | maximum of 128 characters.           |
   |                     |           |         |                                      |
   |                     |           |         | - When **type** is set to            |
   |                     |           |         |   **HOST_NAME**, the value           |
   |                     |           |         |   can contain a maximum of           |
   |                     |           |         |   100 characters that                |
   |                     |           |         |   contain only letters,              |
   |                     |           |         |   digits, hyphens (-), and           |
   |                     |           |         |   periods (.), and must              |
   |                     |           |         |   start with a letter or             |
   |                     |           |         |   digit.                             |
   |                     |           |         | - When **type** is set to            |
   |                     |           |         |   **PATH**, the value can            |
   |                     |           |         |   contain a maximum of 128           |
   |                     |           |         |   characters. When                   |
   |                     |           |         |   **compare_type** is set            |
   |                     |           |         |   to **STARTS_WITH** or              |
   |                     |           |         |   **EQUAL_TO**, the value            |
   |                     |           |         |   must start with a slash            |
   |                     |           |         |   (/) and can contain only           |
   |                     |           |         |   letters, digits, and               |
   |                     |           |         |   special characters                 |
   |                     |           |         |   \_~';@^-%#&$.*+?,=!:&vert;\/()[]{} |
   +---------------------+-----------+---------+--------------------------------------+
   | provisioning_status | No        | String  | This parameter is reserved,          |
   |                     |           |         | and its value can only be            |
   |                     |           |         | **ACTIVE**.                          |
   |                     |           |         |                                      |
   |                     |           |         | It specifies the                     |
   |                     |           |         | provisioning status of the           |
   |                     |           |         | forwarding rule.                     |
   +---------------------+-----------+---------+--------------------------------------+

Response
^^^^^^^^

.. table:: **Table 3** Response parameters

   +-------------+-------+---------------------------------------+
   | Parameter   | Type  | Description                           |
   +=============+=======+=======================================+
   | rules       | Array | Lists the forwarding rules. For       |
   |             |       | details, see :ref:`sl7rl_t4`.         |
   +-------------+-------+---------------------------------------+
   | rules_links | Array | Provides links to the previous or     |
   |             |       | next page during pagination query,    |
   |             |       | respectively.                         |
   |             |       |                                       |
   |             |       | This parameter exists only in the     |
   |             |       | response body of pagination query.    |
   |             |       |                                       |
   |             |       | For details, see :ref:`sl7rl_t5`.     |
   +-------------+-------+---------------------------------------+

.. _sl7rl_t4:
.. table:: **Table 4** **rules** parameter description

   +---------------------+---------+---------------------------------------+
   | Parameter           | Type    | Description                           |
   +=====================+=========+=======================================+
   | id                  | String  | Specifies the forwarding rule ID.     |
   +---------------------+---------+---------------------------------------+
   | tenant_id           | String  | Specifies the ID of the project where |
   |                     |         | the forwarding rule is used.          |
   |                     |         |                                       |
   |                     |         | The value contains a maximum of 255   |
   |                     |         | characters.                           |
   +---------------------+---------+---------------------------------------+
   | admin_state_up      | Boolean | Specifies the administrative status   |
   |                     |         | of the forwarding rule.               |
   |                     |         |                                       |
   |                     |         | This parameter is reserved. The value |
   |                     |         | can be **true** or **false**.         |
   |                     |         |                                       |
   |                     |         | -  **true**: Enabled                  |
   |                     |         | -  **false**: Disabled                |
   +---------------------+---------+---------------------------------------+
   | type                | String  | Specifies the match type of a         |
   |                     |         | forwarding rule.                      |
   |                     |         |                                       |
   |                     |         | The value can be one of the           |
   |                     |         | following:                            |
   |                     |         |                                       |
   |                     |         | -  **HOST_NAME**: matches the domain  |
   |                     |         |    name in the request.               |
   |                     |         | -  **PATH**: matches the path in the  |
   |                     |         |    request.                           |
   +---------------------+---------+---------------------------------------+
   | compare_type        | String  | Specifies the match mode. The options |
   |                     |         | are as follows:                       |
   |                     |         |                                       |
   |                     |         | When **type** is set to               |
   |                     |         | **HOST_NAME**, the value of this      |
   |                     |         | parameter can only be the following:  |
   |                     |         |                                       |
   |                     |         | -  **EQUAL_TO**: indicates exact      |
   |                     |         |    match.                             |
   |                     |         |                                       |
   |                     |         | When **type** is set to **PATH**, the |
   |                     |         | value of this parameter can be one of |
   |                     |         | the following:                        |
   |                     |         |                                       |
   |                     |         | -  **REGEX**: indicates regular       |
   |                     |         |    expression match.                  |
   |                     |         | -  **STARTS_WITH**: indicates prefix  |
   |                     |         |    match.                             |
   |                     |         | -  **EQUAL_TO**: indicates exact      |
   |                     |         |    match.                             |
   +---------------------+---------+---------------------------------------+
   | invert              | Boolean | Specifies whether reverse matching is |
   |                     |         | supported.                            |
   |                     |         |                                       |
   |                     |         | The value can be **true** or          |
   |                     |         | **false**. The default value is       |
   |                     |         | **false**.                            |
   |                     |         |                                       |
   |                     |         | This parameter is reserved.           |
   +---------------------+---------+---------------------------------------+
   | key                 | String  | Specifies the key of the match        |
   |                     |         | content. The default value is         |
   |                     |         | **null**.                             |
   |                     |         |                                       |
   |                     |         | This parameter is reserved.           |
   |                     |         |                                       |
   |                     |         | The value contains a maximum of 255   |
   |                     |         | characters.                           |
   +---------------------+---------+---------------------------------------+
   | value               | String  | Specifies the value of the match      |
   |                     |         | content.                              |
   |                     |         |                                       |
   |                     |         | The value contains a maximum of 128   |
   |                     |         | characters.                           |
   |                     |         |                                       |
   |                     |         | - When **type** is set to             |
   |                     |         |   **HOST_NAME**, the value can        |
   |                     |         |   contain a maximum of 100            |
   |                     |         |   characters that contain only        |
   |                     |         |   letters, digits, hyphens (-), and   |
   |                     |         |   periods (.), and must start with a  |
   |                     |         |   letter or digit.                    |
   |                     |         | - When **type** is set to **PATH**,   |
   |                     |         |   the value can contain a maximum of  |
   |                     |         |   128 characters. When                |
   |                     |         |   **compare_type** is set to          |
   |                     |         |   **STARTS_WITH** or **EQUAL_TO**,    |
   |                     |         |   the value must start with a slash   |
   |                     |         |   (/) and can contain only letters,   |
   |                     |         |   digits, and special characters      |
   |                     |         |   \_~';@^-%#&$.*+?,=!:&vert;\/()[]{}  |
   +---------------------+---------+---------------------------------------+
   | provisioning_status | String  | This parameter is reserved, and its   |
   |                     |         | value can only be **ACTIVE**.         |
   |                     |         |                                       |
   |                     |         | It specifies the provisioning status  |
   |                     |         | of the forwarding rule.               |
   +---------------------+---------+---------------------------------------+

.. _sl7rl_t5:
.. table:: **Table 5** **rules_links** parameter description

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

-  Example request: Querying all forwarding rules of a specific forwarding
   policy

   .. code::

      GET https://{Endpoint}/v2.0/lbaas/l7policies/5ae0e1e7-5f0f-47a1-b39f-5d4c428a1586/rules

Example Response
^^^^^^^^^^^^^^^^

-  Example response

   .. code::

      {
          "rules": [
              {
                  "compare_type": "EQUAL_TO",
                  "provisioning_status": "ACTIVE",
                  "admin_state_up": true,
                  "tenant_id": "a31d2bdcf7604c0faaddb058e1e08819",

                  "invert": false,
                  "value": "www.test.com",
                  "key": null,
                  "type": "HOST_NAME",
                  "id": "67d8a8fa-b0dd-4bd4-a85b-671db19b2ef3"
              },
              {
                  "compare_type": "EQUAL_TO",
                  "provisioning_status": "ACTIVE",
                  "admin_state_up": true,
                  "tenant_id": "a31d2bdcf7604c0faaddb058e1e08819",

                  "invert": false,
                  "value": "/aaa.html",
                  "key": null,
                  "type": "PATH",
                  "id": "f02b3bca-69d2-4335-a3fa-a8054e996213"
              }
          ]
          "rules_links": [
              {
              "href": "https://{Endpoint}/v2.0/lbaas/l7policies/061f461c-c7cf-47ab-9583-09be5076cd09/rules?marker=167c1a31-bc12-4c3d-9ad1-c9bf450df4ce&page_reverse=True",
              "rel": "previous"
              }
          ]
      }

Status Code
^^^^^^^^^^^

See :ref:`shared_lb_status_code`.

Querying Details of a Forwarding Rule
=====================================

Function
^^^^^^^^

This API is used to query details about a forwarding rule using its ID.

URI
^^^

GET /v2.0/lbaas/l7policies/{l7policy_id}/rules/{l7rule_id}

.. table:: **Table 1** Parameter description

   =========== ========= ====== ===================================
   Parameter   Mandatory Type   Description
   =========== ========= ====== ===================================
   l7policy_id Yes       String Specifies the forwarding policy ID.
   l7rule_id   Yes       String Specifies the forwarding rule ID.
   =========== ========= ====== ===================================

Request
^^^^^^^

None

Response
^^^^^^^^

.. table:: **Table 2** Response parameters

   +-----------+--------+-------------------------------------------------------------------+
   | Parameter | Type   | Description                                                       |
   +===========+========+===================================================================+
   | rule      | Object | Specifies the forwarding rule. For details, see :ref:`sl7rs_t3`.  |
   +-----------+--------+-------------------------------------------------------------------+

.. _sl7rs_t3:
.. table:: **Table 3** **rule** parameter description

   +---------------------+---------+---------------------------------------+
   | Parameter           | Type    | Description                           |
   +=====================+=========+=======================================+
   | id                  | String  | Specifies the forwarding rule ID.     |
   +---------------------+---------+---------------------------------------+
   | tenant_id           | String  | Specifies the ID of the project where |
   |                     |         | the forwarding rule is used.          |
   |                     |         |                                       |
   |                     |         | The value contains a maximum of 255   |
   |                     |         | characters.                           |
   +---------------------+---------+---------------------------------------+
   | admin_state_up      | Boolean | Specifies the administrative status   |
   |                     |         | of the forwarding rule.               |
   |                     |         |                                       |
   |                     |         | This parameter is reserved. The value |
   |                     |         | can be **true** or **false**.         |
   |                     |         |                                       |
   |                     |         | -  **true**: Enabled                  |
   |                     |         | -  **false**: Disabled                |
   +---------------------+---------+---------------------------------------+
   | type                | String  | Specifies the match type of a         |
   |                     |         | forwarding rule.                      |
   |                     |         |                                       |
   |                     |         | The value can be one of the           |
   |                     |         | following:                            |
   |                     |         |                                       |
   |                     |         | -  **HOST_NAME**: matches the domain  |
   |                     |         |    name in the request.               |
   |                     |         | -  **PATH**: matches the path in the  |
   |                     |         |    request.                           |
   +---------------------+---------+---------------------------------------+
   | compare_type        | String  | Specifies the match mode. The options |
   |                     |         | are as follows:                       |
   |                     |         |                                       |
   |                     |         | When **type** is set to               |
   |                     |         | **HOST_NAME**, the value of this      |
   |                     |         | parameter can only be the following:  |
   |                     |         |                                       |
   |                     |         | -  **EQUAL_TO**: indicates exact      |
   |                     |         |    match.                             |
   |                     |         |                                       |
   |                     |         | When **type** is set to **PATH**, the |
   |                     |         | value of this parameter can be one of |
   |                     |         | the following:                        |
   |                     |         |                                       |
   |                     |         | -  **REGEX**: indicates regular       |
   |                     |         |    expression match.                  |
   |                     |         | -  **STARTS_WITH**: indicates prefix  |
   |                     |         |    match.                             |
   |                     |         | -  **EQUAL_TO**: indicates exact      |
   |                     |         |    match.                             |
   +---------------------+---------+---------------------------------------+
   | invert              | Boolean | Specifies whether reverse matching is |
   |                     |         | supported.                            |
   |                     |         |                                       |
   |                     |         | The value can be **true** or          |
   |                     |         | **false**. The default value is       |
   |                     |         | **false**.                            |
   |                     |         |                                       |
   |                     |         | This parameter is reserved.           |
   +---------------------+---------+---------------------------------------+
   | key                 | String  | Specifies the key of the match        |
   |                     |         | content. The default value is         |
   |                     |         | **null**.                             |
   |                     |         |                                       |
   |                     |         | This parameter is reserved.           |
   |                     |         |                                       |
   |                     |         | The value contains a maximum of 255   |
   |                     |         | characters.                           |
   +---------------------+---------+---------------------------------------+
   | value               | String  | Specifies the value of the match      |
   |                     |         | content.                              |
   |                     |         |                                       |
   |                     |         | The value contains a maximum of 128   |
   |                     |         | characters.                           |
   |                     |         |                                       |
   |                     |         | - When **type** is set to             |
   |                     |         |   **HOST_NAME**, the value can        |
   |                     |         |   contain a maximum of 100            |
   |                     |         |   characters that contain only        |
   |                     |         |   letters, digits, hyphens (-), and   |
   |                     |         |   periods (.), and must start with a  |
   |                     |         |   letter or digit.                    |
   |                     |         | - When **type** is set to **PATH**,   |
   |                     |         |   the value can contain a maximum of  |
   |                     |         |   128 characters. When                |
   |                     |         |   **compare_type** is set to          |
   |                     |         |   **STARTS_WITH** or **EQUAL_TO**,    |
   |                     |         |   the value must start with a slash   |
   |                     |         |   (/) and can contain only letters,   |
   |                     |         |   digits, and special characters      |
   |                     |         |   \_~';@^-%#&$.*+?,=!:&vert;\/()[]{}  |
   +---------------------+---------+---------------------------------------+
   | provisioning_status | String  | This parameter is reserved, and its   |
   |                     |         | value can only be **ACTIVE**.         |
   |                     |         |                                       |
   |                     |         | It specifies the provisioning status  |
   |                     |         | of the forwarding rule.               |
   +---------------------+---------+---------------------------------------+

Example Request
^^^^^^^^^^^^^^^

-  Example request: Querying details of a forwarding rule

   .. code::

      GET https://{Endpoint}/v2.0/lbaas/l7policies/5ae0e1e7-5f0f-47a1-b39f-5d4c428a1586/rules/67d8a8fa-b0dd-4bd4-a85b-671db19b2ef3

Example Response
^^^^^^^^^^^^^^^^

-  Example response

   .. code::

      {
          "rule": {
              "compare_type": "EQUAL_TO",
              "provisioning_status": "ACTIVE",
              "admin_state_up": true,
              "tenant_id": "a31d2bdcf7604c0faaddb058e1e08819",

              "invert": false,
              "value": "/index.html",
              "key": null,
              "type": "PATH",
              "id": "67d8a8fa-b0dd-4bd4-a85b-671db19b2ef3"
          }
      }

Status Code
^^^^^^^^^^^

See :ref:`shared_lb_status_code`.

Updating a Forwarding Rule
==========================

Function
^^^^^^^^

This API is used to update a forwarding rule. You can change the mode that how
traffic is distributed by updating the forwarding rule.

URI
^^^

PUT /v2.0/lbaas/l7policies/{l7policy_id}/rules/{l7rule_id}

.. table:: **Table 1** Parameter description

   =========== ========= ====== ===================================
   Parameter   Mandatory Type   Description
   =========== ========= ====== ===================================
   l7policy_id Yes       String Specifies the forwarding policy ID.
   l7rule_id   Yes       String Specifies the forwarding rule ID.
   =========== ========= ====== ===================================

Request
^^^^^^^

.. table:: **Table 2** Parameter description

   +-----------+-----------+--------+------------------------------------------------------------------+
   | Parameter | Mandatory | Type   | Description                                                      |
   +===========+===========+========+==================================================================+
   | rule      | Yes       | Object | Specifies the forwarding rule. For details, see :ref:`sl7ru_t3`. |
   +-----------+-----------+--------+------------------------------------------------------------------+

.. _sl7ru_t3:
.. table:: **Table 3** **rule** parameter description

   +----------------+-----------+---------+--------------------------------------+
   | Parameter      | Mandatory | Type    | Description                          |
   +================+===========+=========+======================================+
   | compare_type   | No        | String  | Specifies the match mode.            |
   |                |           |         | The options are as follows:          |
   |                |           |         |                                      |
   |                |           |         | When **type** is set to              |
   |                |           |         | **HOST_NAME**, the value of          |
   |                |           |         | this parameter can only be           |
   |                |           |         | the following:                       |
   |                |           |         |                                      |
   |                |           |         | -  **EQUAL_TO**: indicates           |
   |                |           |         |    exact match.                      |
   |                |           |         |                                      |
   |                |           |         | When **type** is set to              |
   |                |           |         | **PATH**, the value of this          |
   |                |           |         | parameter can be one of the          |
   |                |           |         | following:                           |
   |                |           |         |                                      |
   |                |           |         | -  **REGEX**: indicates              |
   |                |           |         |    regular expression                |
   |                |           |         |    match.                            |
   |                |           |         | -  **STARTS_WITH**:                  |
   |                |           |         |    indicates prefix match.           |
   |                |           |         | -  **EQUAL_TO**: indicates           |
   |                |           |         |    exact match.                      |
   +----------------+-----------+---------+--------------------------------------+
   | admin_state_up | No        | Boolean | Specifies the                        |
   |                |           |         | administrative status of             |
   |                |           |         | the forwarding rule.                 |
   |                |           |         |                                      |
   |                |           |         | This parameter is reserved,          |
   |                |           |         | and the default value is             |
   |                |           |         | **true**.                            |
   +----------------+-----------+---------+--------------------------------------+
   | invert         | No        | Boolean | Specifies whether reverse            |
   |                |           |         | matching is supported.               |
   |                |           |         |                                      |
   |                |           |         | The value can be **true**            |
   |                |           |         | or **false**. The default            |
   |                |           |         | value is **false**.                  |
   |                |           |         |                                      |
   |                |           |         | This parameter is reserved.          |
   +----------------+-----------+---------+--------------------------------------+
   | key            | No        | String  | Specifies the key of the             |
   |                |           |         | match content. The default           |
   |                |           |         | value is **null**.                   |
   |                |           |         |                                      |
   |                |           |         | This parameter is reserved.          |
   |                |           |         |                                      |
   |                |           |         | The value contains a                 |
   |                |           |         | maximum of 255 characters.           |
   +----------------+-----------+---------+--------------------------------------+
   | value          | No        | String  | Specifies the value of the           |
   |                |           |         | match content. The value             |
   |                |           |         | cannot contain spaces.               |
   |                |           |         |                                      |
   |                |           |         | The value contains a                 |
   |                |           |         | maximum of 128 characters.           |
   |                |           |         |                                      |
   |                |           |         | - When **type** is set to            |
   |                |           |         |   **HOST_NAME**, the value           |
   |                |           |         |   can contain a maximum of           |
   |                |           |         |   100 characters that                |
   |                |           |         |   contain only letters,              |
   |                |           |         |   digits, hyphens (-), and           |
   |                |           |         |   periods (.), and must              |
   |                |           |         |   start with a letter or             |
   |                |           |         |   digit.                             |
   |                |           |         | - When **type** is set to            |
   |                |           |         |   **PATH**, the value can            |
   |                |           |         |   contain a maximum of 128           |
   |                |           |         |   characters. When                   |
   |                |           |         |   **compare_type** is set            |
   |                |           |         |   to **STARTS_WITH** or              |
   |                |           |         |   **EQUAL_TO**, the value            |
   |                |           |         |   must start with a slash            |
   |                |           |         |   (/) and can contain only           |
   |                |           |         |   letters, digits, and               |
   |                |           |         |   special characters                 |
   |                |           |         |   \_~';@^-%#&$.*+?,=!:&vert;\/()[]{} |
   +----------------+-----------+---------+--------------------------------------+

Response
^^^^^^^^

.. table:: **Table 4** Response parameters

   +-----------+--------+------------------------------------------------------------------+
   | Parameter | Type   | Description                                                      |
   +===========+========+==================================================================+
   | rule      | Object | Specifies the forwarding rule. For details, see :ref:`sl7ru_t5`. |
   +-----------+--------+------------------------------------------------------------------+

.. _sl7ru_t5:
.. table:: **Table 5** **rule** parameter description

   +---------------------+---------+---------------------------------------+
   | Parameter           | Type    | Description                           |
   +=====================+=========+=======================================+
   | id                  | String  | Specifies the forwarding rule ID.     |
   +---------------------+---------+---------------------------------------+
   | tenant_id           | String  | Specifies the ID of the project where |
   |                     |         | the forwarding rule is used.          |
   |                     |         |                                       |
   |                     |         | The value contains a maximum of 255   |
   |                     |         | characters.                           |
   +---------------------+---------+---------------------------------------+
   | admin_state_up      | Boolean | Specifies the administrative status   |
   |                     |         | of the forwarding rule.               |
   |                     |         |                                       |
   |                     |         | This parameter is reserved. The value |
   |                     |         | can be **true** or **false**.         |
   |                     |         |                                       |
   |                     |         | -  **true**: Enabled                  |
   |                     |         | -  **false**: Disabled                |
   +---------------------+---------+---------------------------------------+
   | type                | String  | Specifies the match type of a         |
   |                     |         | forwarding rule.                      |
   |                     |         |                                       |
   |                     |         | The value can be one of the           |
   |                     |         | following:                            |
   |                     |         |                                       |
   |                     |         | -  **HOST_NAME**: matches the domain  |
   |                     |         |    name in the request.               |
   |                     |         | -  **PATH**: matches the path in the  |
   |                     |         |    request.                           |
   +---------------------+---------+---------------------------------------+
   | compare_type        | String  | Specifies the match mode. The options |
   |                     |         | are as follows:                       |
   |                     |         |                                       |
   |                     |         | When **type** is set to               |
   |                     |         | **HOST_NAME**, the value of this      |
   |                     |         | parameter can only be the following:  |
   |                     |         |                                       |
   |                     |         | -  **EQUAL_TO**: indicates exact      |
   |                     |         |    match.                             |
   |                     |         |                                       |
   |                     |         | When **type** is set to **PATH**, the |
   |                     |         | value of this parameter can be one of |
   |                     |         | the following:                        |
   |                     |         |                                       |
   |                     |         | -  **REGEX**: indicates regular       |
   |                     |         |    expression match.                  |
   |                     |         | -  **STARTS_WITH**: indicates prefix  |
   |                     |         |    match.                             |
   |                     |         | -  **EQUAL_TO**: indicates exact      |
   |                     |         |    match.                             |
   +---------------------+---------+---------------------------------------+
   | invert              | Boolean | Specifies whether reverse matching is |
   |                     |         | supported.                            |
   |                     |         |                                       |
   |                     |         | The value can be **true** or          |
   |                     |         | **false**. The default value is       |
   |                     |         | **false**.                            |
   |                     |         |                                       |
   |                     |         | This parameter is reserved.           |
   +---------------------+---------+---------------------------------------+
   | key                 | String  | Specifies the key of the match        |
   |                     |         | content. The default value is         |
   |                     |         | **null**.                             |
   |                     |         |                                       |
   |                     |         | This parameter is reserved.           |
   |                     |         |                                       |
   |                     |         | The value contains a maximum of 255   |
   |                     |         | characters.                           |
   +---------------------+---------+---------------------------------------+
   | value               | String  | Specifies the value of the match      |
   |                     |         | content.                              |
   |                     |         |                                       |
   |                     |         | The value contains a maximum of 128   |
   |                     |         | characters.                           |
   |                     |         |                                       |
   |                     |         | - When **type** is set to             |
   |                     |         |   **HOST_NAME**, the value can        |
   |                     |         |   contain a maximum of 100            |
   |                     |         |   characters that contain only        |
   |                     |         |   letters, digits, hyphens (-), and   |
   |                     |         |   periods (.), and must start with a  |
   |                     |         |   letter or digit.                    |
   |                     |         | - When **type** is set to **PATH**,   |
   |                     |         |   the value can contain a maximum of  |
   |                     |         |   128 characters. When                |
   |                     |         |   **compare_type** is set to          |
   |                     |         |   **STARTS_WITH** or **EQUAL_TO**,    |
   |                     |         |   the value must start with a slash   |
   |                     |         |   (/) and can contain only letters,   |
   |                     |         |   digits, and special characters      |
   |                     |         |   \_~';@^-%#&$.*+?,=!:&vert;\/()[]{}  |
   +---------------------+---------+---------------------------------------+
   | provisioning_status | String  | This parameter is reserved, and its   |
   |                     |         | value can only be **ACTIVE**.         |
   |                     |         |                                       |
   |                     |         | It specifies the provisioning status  |
   |                     |         | of the forwarding rule.               |
   +---------------------+---------+---------------------------------------+

Example Request
^^^^^^^^^^^^^^^

-  Example request: Updating a forwarding rule

   .. code::

      PUT https://{Endpoint}/v2.0/lbaas/l7policies/5ae0e1e7-5f0f-47a1-b39f-5d4c428a1586/rules/c6f457b8-bf6f-45d7-be5c-a3226945b7b1

      {
          "rule": {
              "compare_type": "STARTS_WITH",
              "value": "/ccc.html"
          }
      }

Example Response
^^^^^^^^^^^^^^^^

-  Example response

   .. code::

      {
          "rule": {
              "compare_type": "STARTS_WITH",
              "provisioning_status": "ACTIVE",
              "admin_state_up": true,
              "tenant_id": "a31d2bdcf7604c0faaddb058e1e08819",

              "invert": false,
              "value": "/ccc.html",
              "key": null,
              "type": "PATH",
              "id": "c6f457b8-bf6f-45d7-be5c-a3226945b7b1"
          }
      }

Status Code
^^^^^^^^^^^

See :ref:`shared_lb_status_code`.

Deleting a Forwarding Rule
==========================

Function
^^^^^^^^

This API is used to delete a specific forwarding rule.

URI
^^^

DELETE /v2.0/lbaas/l7policies/{l7policy_id}/rules/{l7rule_id}

.. table:: **Table 1** Parameter description

   =========== ========= ====== ===================================
   Parameter   Mandatory Type   Description
   =========== ========= ====== ===================================
   l7policy_id Yes       String Specifies the forwarding policy ID.
   l7rule_id   Yes       String Specifies the forwarding rule ID.
   =========== ========= ====== ===================================

Request
^^^^^^^

None

Response
^^^^^^^^

None

Example Request
^^^^^^^^^^^^^^^

-  Example request: Deleting a forwarding rule

   .. code::

      DELETE https://{Endpoint}/v2.0/lbaas/l7policies/5ae0e1e7-5f0f-47a1-b39f-5d4c428a1586/rules/c6f457b8-bf6f-45d7-be5c-a3226945b7b1

Example Response
^^^^^^^^^^^^^^^^

-  Example response

   None

Status Code
^^^^^^^^^^^

See :ref:`shared_lb_status_code`.

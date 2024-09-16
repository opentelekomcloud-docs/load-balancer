:original_name: elb_zq_zg_0001.html

.. _elb_zq_zg_0001:

Adding a Forwarding Rule
========================

Function
--------

This API is used to add a forwarding rule. After you add a forwarding rule, the load balancer matches the domain name and path in the request and distributes the traffic to the backend server group specified by **redirect_pool_id** of the associated forwarding policy.

Constraints
-----------

The match type of forwarding rules in a forwarding policy must be unique.

URI
---

POST /v2.0/lbaas/l7policies/{l7policy_id}/rules

.. table:: **Table 1** Parameter description

   =========== ========= ====== ===================================
   Parameter   Mandatory Type   Description
   =========== ========= ====== ===================================
   l7policy_id Yes       String Specifies the forwarding policy ID.
   =========== ========= ====== ===================================

Request
-------

.. table:: **Table 2** Parameter description

   +-----------+-----------+--------+----------------------------------------------------------------------------------------------------------------------------+
   | Parameter | Mandatory | Type   | Description                                                                                                                |
   +===========+===========+========+============================================================================================================================+
   | rule      | Yes       | Object | Specifies the forwarding rule. For details, see :ref:`Table 3 <elb_zq_zg_0001__en-us_topic_0116649236_table857349145816>`. |
   +-----------+-----------+--------+----------------------------------------------------------------------------------------------------------------------------+

.. _elb_zq_zg_0001__en-us_topic_0116649236_table857349145816:

.. table:: **Table 3** **rule** parameter description

   +-----------------+-----------------+-----------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter       | Mandatory       | Type            | Description                                                                                                                                                                                                                                                                                         |
   +=================+=================+=================+=====================================================================================================================================================================================================================================================================================================+
   | tenant_id       | No              | String          | Specifies the ID of the project where the forwarding rule is used.                                                                                                                                                                                                                                  |
   |                 |                 |                 |                                                                                                                                                                                                                                                                                                     |
   |                 |                 |                 | The value must be the same as the value of **project_id** in the token.                                                                                                                                                                                                                             |
   |                 |                 |                 |                                                                                                                                                                                                                                                                                                     |
   |                 |                 |                 | The value contains a maximum of 255 characters.                                                                                                                                                                                                                                                     |
   +-----------------+-----------------+-----------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | admin_state_up  | No              | Boolean         | Specifies the administrative status of the forwarding rule.                                                                                                                                                                                                                                         |
   |                 |                 |                 |                                                                                                                                                                                                                                                                                                     |
   |                 |                 |                 | This parameter is reserved, and the default value is **true**.                                                                                                                                                                                                                                      |
   +-----------------+-----------------+-----------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | type            | Yes             | String          | Specifies the match type of a forwarding rule.                                                                                                                                                                                                                                                      |
   |                 |                 |                 |                                                                                                                                                                                                                                                                                                     |
   |                 |                 |                 | The value can be one of the following:                                                                                                                                                                                                                                                              |
   |                 |                 |                 |                                                                                                                                                                                                                                                                                                     |
   |                 |                 |                 | -  **HOST_NAME**: matches the domain name in the request.                                                                                                                                                                                                                                           |
   |                 |                 |                 | -  **PATH**: matches the path in the request.                                                                                                                                                                                                                                                       |
   |                 |                 |                 |                                                                                                                                                                                                                                                                                                     |
   |                 |                 |                 | The match type of forwarding rules in a forwarding policy must be unique.                                                                                                                                                                                                                           |
   +-----------------+-----------------+-----------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | compare_type    | Yes             | String          | Specifies the match mode. The options are as follows:                                                                                                                                                                                                                                               |
   |                 |                 |                 |                                                                                                                                                                                                                                                                                                     |
   |                 |                 |                 | When **type** is set to **HOST_NAME**, the value of this parameter can only be the following:                                                                                                                                                                                                       |
   |                 |                 |                 |                                                                                                                                                                                                                                                                                                     |
   |                 |                 |                 | -  **EQUAL_TO**: indicates exact match.                                                                                                                                                                                                                                                             |
   |                 |                 |                 |                                                                                                                                                                                                                                                                                                     |
   |                 |                 |                 | When **type** is set to **PATH**, the value of this parameter can be one of the following:                                                                                                                                                                                                          |
   |                 |                 |                 |                                                                                                                                                                                                                                                                                                     |
   |                 |                 |                 | -  **REGEX**: indicates regular expression match.                                                                                                                                                                                                                                                   |
   |                 |                 |                 | -  **STARTS_WITH**: indicates prefix match.                                                                                                                                                                                                                                                         |
   |                 |                 |                 | -  **EQUAL_TO**: indicates exact match.                                                                                                                                                                                                                                                             |
   +-----------------+-----------------+-----------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | invert          | No              | Boolean         | Specifies whether reverse matching is supported.                                                                                                                                                                                                                                                    |
   |                 |                 |                 |                                                                                                                                                                                                                                                                                                     |
   |                 |                 |                 | The value can be **true** or **false**. The default value is **false**.                                                                                                                                                                                                                             |
   |                 |                 |                 |                                                                                                                                                                                                                                                                                                     |
   |                 |                 |                 | This parameter is reserved.                                                                                                                                                                                                                                                                         |
   +-----------------+-----------------+-----------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | key             | No              | String          | Specifies the key of the match content. The default value is **null**.                                                                                                                                                                                                                              |
   |                 |                 |                 |                                                                                                                                                                                                                                                                                                     |
   |                 |                 |                 | This parameter is reserved.                                                                                                                                                                                                                                                                         |
   |                 |                 |                 |                                                                                                                                                                                                                                                                                                     |
   |                 |                 |                 | The value contains a maximum of 255 characters.                                                                                                                                                                                                                                                     |
   +-----------------+-----------------+-----------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | value           | Yes             | String          | Specifies the value of the match content. The value cannot contain spaces.                                                                                                                                                                                                                          |
   |                 |                 |                 |                                                                                                                                                                                                                                                                                                     |
   |                 |                 |                 | The value contains a maximum of 128 characters.                                                                                                                                                                                                                                                     |
   |                 |                 |                 |                                                                                                                                                                                                                                                                                                     |
   |                 |                 |                 | -  When **type** is set to **HOST_NAME**, the value can contain a maximum of 100 characters that contain only letters, digits, hyphens (-), and periods (.), and must start with a letter or digit.                                                                                                 |
   |                 |                 |                 | -  When **type** is set to **PATH**, the value can contain a maximum of 128 characters. When **compare_type** is set to **STARTS_WITH** or **EQUAL_TO**, the value must start with a slash (/) and can contain only letters, digits, and special characters\ ``_~';@^-%#&$.*+?,=!:|``\ ``\/()[]{}`` |
   +-----------------+-----------------+-----------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

Response
--------

.. table:: **Table 4** Response parameters

   +-----------+--------+-----------------------------------------------------------------------------------------------------------------------------+
   | Parameter | Type   | Description                                                                                                                 |
   +===========+========+=============================================================================================================================+
   | rule      | Object | Specifies the forwarding rule. For details, see :ref:`Table 5 <elb_zq_zg_0001__en-us_topic_0116649236_table1212118142596>`. |
   +-----------+--------+-----------------------------------------------------------------------------------------------------------------------------+

.. _elb_zq_zg_0001__en-us_topic_0116649236_table1212118142596:

.. table:: **Table 5** **rule** parameter description

   +-----------------------+-----------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter             | Type                  | Description                                                                                                                                                                                                                                                                                         |
   +=======================+=======================+=====================================================================================================================================================================================================================================================================================================+
   | id                    | String                | Specifies the forwarding rule ID.                                                                                                                                                                                                                                                                   |
   +-----------------------+-----------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | tenant_id             | String                | Specifies the ID of the project where the forwarding rule is used.                                                                                                                                                                                                                                  |
   |                       |                       |                                                                                                                                                                                                                                                                                                     |
   |                       |                       | The value contains a maximum of 255 characters.                                                                                                                                                                                                                                                     |
   +-----------------------+-----------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | admin_state_up        | Boolean               | Specifies the administrative status of the forwarding rule.                                                                                                                                                                                                                                         |
   |                       |                       |                                                                                                                                                                                                                                                                                                     |
   |                       |                       | This parameter is reserved. The value can be **true** or **false**.                                                                                                                                                                                                                                 |
   |                       |                       |                                                                                                                                                                                                                                                                                                     |
   |                       |                       | -  **true**: Enabled                                                                                                                                                                                                                                                                                |
   |                       |                       | -  **false**: Disabled                                                                                                                                                                                                                                                                              |
   +-----------------------+-----------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | type                  | String                | Specifies the match type of a forwarding rule.                                                                                                                                                                                                                                                      |
   |                       |                       |                                                                                                                                                                                                                                                                                                     |
   |                       |                       | The value can be one of the following:                                                                                                                                                                                                                                                              |
   |                       |                       |                                                                                                                                                                                                                                                                                                     |
   |                       |                       | -  **HOST_NAME**: matches the domain name in the request.                                                                                                                                                                                                                                           |
   |                       |                       | -  **PATH**: matches the path in the request.                                                                                                                                                                                                                                                       |
   +-----------------------+-----------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | compare_type          | String                | Specifies the match mode. The options are as follows:                                                                                                                                                                                                                                               |
   |                       |                       |                                                                                                                                                                                                                                                                                                     |
   |                       |                       | When **type** is set to **HOST_NAME**, the value of this parameter can only be the following:                                                                                                                                                                                                       |
   |                       |                       |                                                                                                                                                                                                                                                                                                     |
   |                       |                       | -  **EQUAL_TO**: indicates exact match.                                                                                                                                                                                                                                                             |
   |                       |                       |                                                                                                                                                                                                                                                                                                     |
   |                       |                       | When **type** is set to **PATH**, the value of this parameter can be one of the following:                                                                                                                                                                                                          |
   |                       |                       |                                                                                                                                                                                                                                                                                                     |
   |                       |                       | -  **REGEX**: indicates regular expression match.                                                                                                                                                                                                                                                   |
   |                       |                       | -  **STARTS_WITH**: indicates prefix match.                                                                                                                                                                                                                                                         |
   |                       |                       | -  **EQUAL_TO**: indicates exact match.                                                                                                                                                                                                                                                             |
   +-----------------------+-----------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | invert                | Boolean               | Specifies whether reverse matching is supported.                                                                                                                                                                                                                                                    |
   |                       |                       |                                                                                                                                                                                                                                                                                                     |
   |                       |                       | The value can be **true** or **false**. The default value is **false**.                                                                                                                                                                                                                             |
   |                       |                       |                                                                                                                                                                                                                                                                                                     |
   |                       |                       | This parameter is reserved.                                                                                                                                                                                                                                                                         |
   +-----------------------+-----------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | key                   | String                | Specifies the key of the match content. The default value is **null**.                                                                                                                                                                                                                              |
   |                       |                       |                                                                                                                                                                                                                                                                                                     |
   |                       |                       | This parameter is reserved.                                                                                                                                                                                                                                                                         |
   |                       |                       |                                                                                                                                                                                                                                                                                                     |
   |                       |                       | The value contains a maximum of 255 characters.                                                                                                                                                                                                                                                     |
   +-----------------------+-----------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | value                 | String                | Specifies the value of the match content.                                                                                                                                                                                                                                                           |
   |                       |                       |                                                                                                                                                                                                                                                                                                     |
   |                       |                       | The value contains a maximum of 128 characters.                                                                                                                                                                                                                                                     |
   |                       |                       |                                                                                                                                                                                                                                                                                                     |
   |                       |                       | -  When **type** is set to **HOST_NAME**, the value can contain a maximum of 100 characters that contain only letters, digits, hyphens (-), and periods (.), and must start with a letter or digit.                                                                                                 |
   |                       |                       | -  When **type** is set to **PATH**, the value can contain a maximum of 128 characters. When **compare_type** is set to **STARTS_WITH** or **EQUAL_TO**, the value must start with a slash (/) and can contain only letters, digits, and special characters\ ``_~';@^-%#&$.*+?,=!:|``\ ``\/()[]{}`` |
   +-----------------------+-----------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | provisioning_status   | String                | This parameter is reserved, and its value can only be **ACTIVE**.                                                                                                                                                                                                                                   |
   |                       |                       |                                                                                                                                                                                                                                                                                                     |
   |                       |                       | It specifies the provisioning status of the forwarding rule.                                                                                                                                                                                                                                        |
   +-----------------------+-----------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

Example Request
---------------

-  Example request: Adding a forwarding rule

   .. code-block:: text

      POST https://{Endpoint}/v2.0/lbaas/l7policies/5ae0e1e7-5f0f-47a1-b39f-5d4c428a1586/rules

      {
          "rule": {
              "compare_type": "EQUAL_TO",
              "type": "PATH",
              "value": "/bbb.html"
          }
      }

Example Response
----------------

-  Example response

   .. code-block::

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
-----------

For details, see :ref:`HTTP Status Codes of Shared Load Balancers <elb_gc_0002>`.

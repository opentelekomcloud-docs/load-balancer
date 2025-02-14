:original_name: elb_zq_zg_0003.html

.. _elb_zq_zg_0003:

Querying Details of a Forwarding Rule
=====================================

Function
--------

This API is used to query details about a forwarding rule by ID.

URI
---

GET /v2.0/lbaas/l7policies/{l7policy_id}/rules/{l7rule_id}

.. table:: **Table 1** Parameter description

   =========== ========= ====== ===================================
   Parameter   Mandatory Type   Description
   =========== ========= ====== ===================================
   l7policy_id Yes       String Specifies the forwarding policy ID.
   l7rule_id   Yes       String Specifies the forwarding rule ID.
   =========== ========= ====== ===================================

Request
-------

None

Response
--------

.. table:: **Table 2** Response parameters

   +-----------+--------+----------------------------------------------------------------------------------------------------------------------------+
   | Parameter | Type   | Description                                                                                                                |
   +===========+========+============================================================================================================================+
   | rule      | Object | Specifies the forwarding rule. For details, see :ref:`Table 3 <elb_zq_zg_0003__en-us_topic_0116649235_table239892725716>`. |
   +-----------+--------+----------------------------------------------------------------------------------------------------------------------------+

.. _elb_zq_zg_0003__en-us_topic_0116649235_table239892725716:

.. table:: **Table 3** **rule** parameter description

   +-----------------------+-----------------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter             | Type                  | Description                                                                                                                                                                                                                                                                                       |
   +=======================+=======================+===================================================================================================================================================================================================================================================================================================+
   | id                    | String                | Specifies the forwarding rule ID.                                                                                                                                                                                                                                                                 |
   +-----------------------+-----------------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | tenant_id             | String                | Specifies the ID of the project where the forwarding rule is used.                                                                                                                                                                                                                                |
   |                       |                       |                                                                                                                                                                                                                                                                                                   |
   |                       |                       | The value contains a maximum of 255 characters.                                                                                                                                                                                                                                                   |
   +-----------------------+-----------------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | admin_state_up        | Boolean               | Specifies the administrative status of the forwarding rule.                                                                                                                                                                                                                                       |
   |                       |                       |                                                                                                                                                                                                                                                                                                   |
   |                       |                       | This parameter is reserved. The value can be **true** or **false**.                                                                                                                                                                                                                               |
   |                       |                       |                                                                                                                                                                                                                                                                                                   |
   |                       |                       | -  **true**: Enabled                                                                                                                                                                                                                                                                              |
   |                       |                       | -  **false**: Disabled                                                                                                                                                                                                                                                                            |
   +-----------------------+-----------------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | type                  | String                | Specifies the match type of a forwarding rule.                                                                                                                                                                                                                                                    |
   |                       |                       |                                                                                                                                                                                                                                                                                                   |
   |                       |                       | The value can be one of the following:                                                                                                                                                                                                                                                            |
   |                       |                       |                                                                                                                                                                                                                                                                                                   |
   |                       |                       | -  **HOST_NAME**: matches the domain name in the request.                                                                                                                                                                                                                                         |
   |                       |                       | -  **PATH**: matches the path in the request.                                                                                                                                                                                                                                                     |
   +-----------------------+-----------------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | compare_type          | String                | Specifies the match mode. The options are as follows:                                                                                                                                                                                                                                             |
   |                       |                       |                                                                                                                                                                                                                                                                                                   |
   |                       |                       | When **type** is set to **HOST_NAME**, the value of this parameter can only be the following:                                                                                                                                                                                                     |
   |                       |                       |                                                                                                                                                                                                                                                                                                   |
   |                       |                       | -  **EQUAL_TO**: indicates exact match.                                                                                                                                                                                                                                                           |
   |                       |                       |                                                                                                                                                                                                                                                                                                   |
   |                       |                       | When **type** is set to **PATH**, the value of this parameter can be one of the following:                                                                                                                                                                                                        |
   |                       |                       |                                                                                                                                                                                                                                                                                                   |
   |                       |                       | -  **REGEX**: indicates regular expression match.                                                                                                                                                                                                                                                 |
   |                       |                       | -  **STARTS_WITH**: indicates prefix match.                                                                                                                                                                                                                                                       |
   |                       |                       | -  **EQUAL_TO**: indicates exact match.                                                                                                                                                                                                                                                           |
   +-----------------------+-----------------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | invert                | Boolean               | Specifies whether reverse matching is supported.                                                                                                                                                                                                                                                  |
   |                       |                       |                                                                                                                                                                                                                                                                                                   |
   |                       |                       | The value can be **true** or **false**. The default value is **false**.                                                                                                                                                                                                                           |
   |                       |                       |                                                                                                                                                                                                                                                                                                   |
   |                       |                       | This parameter is reserved.                                                                                                                                                                                                                                                                       |
   +-----------------------+-----------------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | key                   | String                | Specifies the key of the match content. The default value is **null**.                                                                                                                                                                                                                            |
   |                       |                       |                                                                                                                                                                                                                                                                                                   |
   |                       |                       | This parameter is reserved.                                                                                                                                                                                                                                                                       |
   |                       |                       |                                                                                                                                                                                                                                                                                                   |
   |                       |                       | The value contains a maximum of 255 characters.                                                                                                                                                                                                                                                   |
   +-----------------------+-----------------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | value                 | String                | Specifies the value of the match content.                                                                                                                                                                                                                                                         |
   |                       |                       |                                                                                                                                                                                                                                                                                                   |
   |                       |                       | The value contains a maximum of 128 characters.                                                                                                                                                                                                                                                   |
   |                       |                       |                                                                                                                                                                                                                                                                                                   |
   |                       |                       | -  When **type** is set to **HOST_NAME**, the value can contain a maximum of 100 characters that contain only letters, digits, hyphens (-), and periods (.), and must start with a letter or digit.                                                                                               |
   |                       |                       | -  When **type** is set to **PATH**, the value can contain a maximum of 128 characters. When **compare_type** is set to **STARTS_WITH** or **EQUAL_TO**, the value must start with a slash (/) and can contain only letters, digits, and special characters ``_~';@^-%#&$.*+?,=!:|`` ``\/()[]{}`` |
   +-----------------------+-----------------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | provisioning_status   | String                | This parameter is reserved, and its value can only be **ACTIVE**.                                                                                                                                                                                                                                 |
   |                       |                       |                                                                                                                                                                                                                                                                                                   |
   |                       |                       | It specifies the provisioning status of the forwarding rule.                                                                                                                                                                                                                                      |
   +-----------------------+-----------------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

Example Request
---------------

-  Example request: Querying details of a forwarding rule

   .. code-block:: text

      GET https://{Endpoint}/v2.0/lbaas/l7policies/5ae0e1e7-5f0f-47a1-b39f-5d4c428a1586/rules/67d8a8fa-b0dd-4bd4-a85b-671db19b2ef3

Example Response
----------------

-  Example response

   .. code-block::

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
-----------

For details, see :ref:`HTTP Status Codes of Shared Load Balancers <elb_gc_0002>`.

:original_name: ListL7Rules.html

.. _ListL7Rules:

Querying Forwarding Rules
=========================

Function
--------

This API is used to query all forwarding rules.

Constraints
-----------

Parameters **marker**, **limit**, and **page_reverse** are used for pagination query.

Parameters **marker** and **page_reverse** take effect only when they are used together with parameter **limit**.

URI
---

GET /v3/{project_id}/elb/l7policies/{l7policy_id}/rules

.. table:: **Table 1** Path Parameters

   =========== ========= ====== ===================================
   Parameter   Mandatory Type   Description
   =========== ========= ====== ===================================
   project_id  Yes       String Specifies the project ID.
   l7policy_id Yes       String Specifies the forwarding policy ID.
   =========== ========= ====== ===================================

.. table:: **Table 2** Query Parameters

   +-----------------------+-----------------+-----------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter             | Mandatory       | Type            | Description                                                                                                                                                                                                                      |
   +=======================+=================+=================+==================================================================================================================================================================================================================================+
   | limit                 | No              | Integer         | Specifies the number of records on each page.                                                                                                                                                                                    |
   |                       |                 |                 |                                                                                                                                                                                                                                  |
   |                       |                 |                 | Minimum: **0**                                                                                                                                                                                                                   |
   |                       |                 |                 |                                                                                                                                                                                                                                  |
   |                       |                 |                 | Maximum: **2000**                                                                                                                                                                                                                |
   +-----------------------+-----------------+-----------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | marker                | No              | String          | Specifies the ID of the last record on the previous page.                                                                                                                                                                        |
   |                       |                 |                 |                                                                                                                                                                                                                                  |
   |                       |                 |                 | Note:                                                                                                                                                                                                                            |
   |                       |                 |                 |                                                                                                                                                                                                                                  |
   |                       |                 |                 | -  This parameter must be used together with **limit**.                                                                                                                                                                          |
   |                       |                 |                 |                                                                                                                                                                                                                                  |
   |                       |                 |                 | -  If this parameter is not specified, the first page will be queried.                                                                                                                                                           |
   |                       |                 |                 |                                                                                                                                                                                                                                  |
   |                       |                 |                 | -  This parameter cannot be left blank or set to an invalid ID.                                                                                                                                                                  |
   +-----------------------+-----------------+-----------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | page_reverse          | No              | Boolean         | Specifies the page direction.                                                                                                                                                                                                    |
   |                       |                 |                 |                                                                                                                                                                                                                                  |
   |                       |                 |                 | The value can be **true** or **false**, and the default value is **false**.                                                                                                                                                      |
   |                       |                 |                 |                                                                                                                                                                                                                                  |
   |                       |                 |                 | The last page in the list requested with **page_reverse** set to **false** will not contain the "next" link, and the last page in the list requested with **page_reverse** set to **true** will not contain the "previous" link. |
   |                       |                 |                 |                                                                                                                                                                                                                                  |
   |                       |                 |                 | This parameter must be used together with **limit**.                                                                                                                                                                             |
   +-----------------------+-----------------+-----------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | id                    | No              | Array           | Specifies the forwarding rule ID.                                                                                                                                                                                                |
   |                       |                 |                 |                                                                                                                                                                                                                                  |
   |                       |                 |                 | Multiple IDs can be queried in the format of *id=xxx&id=xxx*.                                                                                                                                                                    |
   +-----------------------+-----------------+-----------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | compare_type          | No              | Array           | Specifies how requests are matched with the domain name or URL.                                                                                                                                                                  |
   |                       |                 |                 |                                                                                                                                                                                                                                  |
   |                       |                 |                 | -  If **type** is set to **HOST_NAME**, this parameter can only be set to **EQUAL_TO**.                                                                                                                                          |
   |                       |                 |                 |                                                                                                                                                                                                                                  |
   |                       |                 |                 | -  If **type** is set to **PATH**, this parameter can be set to **REGEX**, **STARTS_WITH**, or **EQUAL_TO**.                                                                                                                     |
   |                       |                 |                 |                                                                                                                                                                                                                                  |
   |                       |                 |                 | Multiple values can be queried in the format of *compare_type=xxx&compare_type=xxx*.                                                                                                                                             |
   +-----------------------+-----------------+-----------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | provisioning_status   | No              | Array           | Specifies the provisioning status of the forwarding rule. The value can only be **ACTIVE**, indicating that the forwarding rule is provisioned successfully.                                                                     |
   |                       |                 |                 |                                                                                                                                                                                                                                  |
   |                       |                 |                 | Multiple provisioning statuses can be queried in the format of *provisioning_status=xxx&provisioning_status=xxx*.                                                                                                                |
   +-----------------------+-----------------+-----------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | invert                | No              | Boolean         | Specifies whether reverse matching is supported. The value is fixed at **false**. This parameter can be updated but remains invalid.                                                                                             |
   +-----------------------+-----------------+-----------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | admin_state_up        | No              | Boolean         | Specifies the administrative status of the forwarding rule. The default value is **true**.                                                                                                                                       |
   |                       |                 |                 |                                                                                                                                                                                                                                  |
   |                       |                 |                 | This parameter is unsupported. Please do not use it.                                                                                                                                                                             |
   +-----------------------+-----------------+-----------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | value                 | No              | Array           | Specifies the value of the match content.                                                                                                                                                                                        |
   |                       |                 |                 |                                                                                                                                                                                                                                  |
   |                       |                 |                 | Multiple values can be queried in the format of *value=xxx&value=xxx*.                                                                                                                                                           |
   +-----------------------+-----------------+-----------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | key                   | No              | Array           | Specifies the key of the match content that is used to identify the forwarding rule.                                                                                                                                             |
   |                       |                 |                 |                                                                                                                                                                                                                                  |
   |                       |                 |                 | Multiple keys can be queried in the format of *key=xxx&key=xxx*.                                                                                                                                                                 |
   |                       |                 |                 |                                                                                                                                                                                                                                  |
   |                       |                 |                 | This parameter is unsupported. Please do not use it.                                                                                                                                                                             |
   +-----------------------+-----------------+-----------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | type                  | No              | Array           | Specifies the match content. The value can be **HOST_NAME** or **PATH**.                                                                                                                                                         |
   |                       |                 |                 |                                                                                                                                                                                                                                  |
   |                       |                 |                 | **HOST_NAME** indicates that the domain name will be used for matching, and **PATH** indicates that the URL will be used for matching.                                                                                           |
   |                       |                 |                 |                                                                                                                                                                                                                                  |
   |                       |                 |                 | The **type** value must be unique for each forwarding rule in a forwarding policy.                                                                                                                                               |
   |                       |                 |                 |                                                                                                                                                                                                                                  |
   |                       |                 |                 | Multiple values can be queried in the format of *type=xxx&type=xxx*.                                                                                                                                                             |
   +-----------------------+-----------------+-----------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | enterprise_project_id | No              | Array           | Specifies the enterprise project ID.                                                                                                                                                                                             |
   |                       |                 |                 |                                                                                                                                                                                                                                  |
   |                       |                 |                 | -  If this parameter is not passed, resources in the default enterprise project are queried, and authentication is performed based on the default enterprise project.                                                            |
   |                       |                 |                 |                                                                                                                                                                                                                                  |
   |                       |                 |                 | -  If this parameter is passed, its value can be the ID of an existing enterprise project or **all_granted_eps**.                                                                                                                |
   |                       |                 |                 |                                                                                                                                                                                                                                  |
   |                       |                 |                 | If the value is a specific ID, resources in the specific enterprise project are required. If the value is **all_granted_eps**, resources in all enterprise projects are queried.                                                 |
   |                       |                 |                 |                                                                                                                                                                                                                                  |
   |                       |                 |                 | Multiple IDs can be queried in the format of *enterprise_project_id=xxx&enterprise_project_id=xxx*.                                                                                                                              |
   |                       |                 |                 |                                                                                                                                                                                                                                  |
   |                       |                 |                 | This parameter is unsupported. Please do not use it.                                                                                                                                                                             |
   +-----------------------+-----------------+-----------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

Request Parameters
------------------

.. table:: **Table 3** Request header parameters

   +--------------+-----------+--------+--------------------------------------------------+
   | Parameter    | Mandatory | Type   | Description                                      |
   +==============+===========+========+==================================================+
   | X-Auth-Token | Yes       | String | Specifies the token used for IAM authentication. |
   +--------------+-----------+--------+--------------------------------------------------+

Response Parameters
-------------------

**Status code: 200**

.. table:: **Table 4** Response body parameters

   +------------+---------------------------------------------------------------+-----------------------------------------------------------------+
   | Parameter  | Type                                                          | Description                                                     |
   +============+===============================================================+=================================================================+
   | request_id | String                                                        | Specifies the request ID. The value is automatically generated. |
   +------------+---------------------------------------------------------------+-----------------------------------------------------------------+
   | page_info  | :ref:`PageInfo <listl7rules__response_pageinfo>` object       | Shows pagination information.                                   |
   +------------+---------------------------------------------------------------+-----------------------------------------------------------------+
   | rules      | Array of :ref:`L7Rule <listl7rules__response_l7rule>` objects | Lists the forwarding rules.                                     |
   +------------+---------------------------------------------------------------+-----------------------------------------------------------------+

.. _listl7rules__response_pageinfo:

.. table:: **Table 5** PageInfo

   +-----------------+---------+------------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter       | Type    | Description                                                                                                                              |
   +=================+=========+==========================================================================================================================================+
   | previous_marker | String  | Specifies the ID of the first record in the pagination query result. This parameter will not be returned if no query result is returned. |
   +-----------------+---------+------------------------------------------------------------------------------------------------------------------------------------------+
   | next_marker     | String  | Marks the start record on the next page in the pagination query result. This parameter will not be returned if there is no next page.    |
   +-----------------+---------+------------------------------------------------------------------------------------------------------------------------------------------+
   | current_count   | Integer | Specifies the number of records.                                                                                                         |
   +-----------------+---------+------------------------------------------------------------------------------------------------------------------------------------------+

.. _listl7rules__response_l7rule:

.. table:: **Table 6** L7Rule

   +-----------------------+-----------------------------------------------------------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter             | Type                                                                        | Description                                                                                                                                                                                                                                                       |
   +=======================+=============================================================================+===================================================================================================================================================================================================================================================================+
   | admin_state_up        | Boolean                                                                     | Specifies the administrative status of the forwarding rule. The default value is **true**.                                                                                                                                                                        |
   |                       |                                                                             |                                                                                                                                                                                                                                                                   |
   |                       |                                                                             | This parameter is unsupported. Please do not use it.                                                                                                                                                                                                              |
   +-----------------------+-----------------------------------------------------------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | compare_type          | String                                                                      | Specifies how requests are matched with the domain name or URL.                                                                                                                                                                                                   |
   |                       |                                                                             |                                                                                                                                                                                                                                                                   |
   |                       |                                                                             | -  If **type** is set to **HOST_NAME**, this parameter can only be set to **EQUAL_TO**.                                                                                                                                                                           |
   |                       |                                                                             |                                                                                                                                                                                                                                                                   |
   |                       |                                                                             | -  If **type** is set to **PATH**, this parameter can be set to **REGEX**, **STARTS_WITH**, or **EQUAL_TO**.                                                                                                                                                      |
   +-----------------------+-----------------------------------------------------------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | key                   | String                                                                      | Specifies the key of the match content. This parameter will not take effect when **type** is set to **HOST_NAME** or **PATH**. It can be updated but will not take effect.                                                                                        |
   |                       |                                                                             |                                                                                                                                                                                                                                                                   |
   |                       |                                                                             | This parameter is unsupported. Please do not use it.                                                                                                                                                                                                              |
   |                       |                                                                             |                                                                                                                                                                                                                                                                   |
   |                       |                                                                             | Minimum: **1**                                                                                                                                                                                                                                                    |
   |                       |                                                                             |                                                                                                                                                                                                                                                                   |
   |                       |                                                                             | Maximum: **255**                                                                                                                                                                                                                                                  |
   +-----------------------+-----------------------------------------------------------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | project_id            | String                                                                      | Specifies the project ID.                                                                                                                                                                                                                                         |
   +-----------------------+-----------------------------------------------------------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | type                  | String                                                                      | Specifies the match content. The value can be one of the following:                                                                                                                                                                                               |
   |                       |                                                                             |                                                                                                                                                                                                                                                                   |
   |                       |                                                                             | -  **HOST_NAME**: A domain name will be used for matching.                                                                                                                                                                                                        |
   |                       |                                                                             |                                                                                                                                                                                                                                                                   |
   |                       |                                                                             | -  **PATH**: A URL will be used for matching.                                                                                                                                                                                                                     |
   +-----------------------+-----------------------------------------------------------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | value                 | String                                                                      | Specifies the value of the match item. For example, if a domain name is used for matching, **value** is the domain name.                                                                                                                                          |
   |                       |                                                                             |                                                                                                                                                                                                                                                                   |
   |                       |                                                                             | -  If **type** is set to **HOST_NAME**, the value can contain letters, digits, hyphens (-), and periods (.) and must start with a letter or digit. If you want to use a wildcard domain name, enter an asterisk (``*``) as the leftmost label of the domain name. |
   |                       |                                                                             |                                                                                                                                                                                                                                                                   |
   |                       |                                                                             | -  If **type** is set to **PATH** and **compare_type** to **STARTS_WITH** or **EQUAL_TO**, the value must start with a slash (/) and can contain only letters, digits, and special characters ``_~';@^-%#&$.*+?,=!:|/()[]{}``                                     |
   |                       |                                                                             |                                                                                                                                                                                                                                                                   |
   |                       |                                                                             | Minimum: **1**                                                                                                                                                                                                                                                    |
   |                       |                                                                             |                                                                                                                                                                                                                                                                   |
   |                       |                                                                             | Maximum: **128**                                                                                                                                                                                                                                                  |
   +-----------------------+-----------------------------------------------------------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | provisioning_status   | String                                                                      | Specifies the provisioning status of the forwarding rule.                                                                                                                                                                                                         |
   +-----------------------+-----------------------------------------------------------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | invert                | Boolean                                                                     | Specifies whether reverse matching is supported. The value is fixed at **false**. This parameter can be updated but remains invalid.                                                                                                                              |
   |                       |                                                                             |                                                                                                                                                                                                                                                                   |
   |                       |                                                                             | Default: **false**                                                                                                                                                                                                                                                |
   +-----------------------+-----------------------------------------------------------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | id                    | String                                                                      | Specifies the forwarding policy ID.                                                                                                                                                                                                                               |
   +-----------------------+-----------------------------------------------------------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | conditions            | Array of :ref:`RuleCondition <listl7rules__response_rulecondition>` objects | Specifies the matching conditions of the forwarding rule.                                                                                                                                                                                                         |
   |                       |                                                                             |                                                                                                                                                                                                                                                                   |
   |                       |                                                                             | -  If **conditions** is specified, **key** and **value** will not take effect, and the value of this parameter will contain all conditions configured for the forwarding rule. The keys in the list must be the same, whereas each value must be unique.          |
   |                       |                                                                             |                                                                                                                                                                                                                                                                   |
   |                       |                                                                             | -  If **conditions** is not specified, the values of **key** and **value** are displayed.                                                                                                                                                                         |
   |                       |                                                                             |                                                                                                                                                                                                                                                                   |
   |                       |                                                                             | This parameter is unsupported. Please do not use it.                                                                                                                                                                                                              |
   +-----------------------+-----------------------------------------------------------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

.. _listl7rules__response_rulecondition:

.. table:: **Table 7** RuleCondition

   +-----------------------+-----------------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter             | Type                  | Description                                                                                                                                                                                                                                                                                                                                                                                 |
   +=======================+=======================+=============================================================================================================================================================================================================================================================================================================================================================================================+
   | key                   | String                | Specifies the key of match item. This parameter is left blank.                                                                                                                                                                                                                                                                                                                              |
   |                       |                       |                                                                                                                                                                                                                                                                                                                                                                                             |
   |                       |                       | Minimum: **1**                                                                                                                                                                                                                                                                                                                                                                              |
   |                       |                       |                                                                                                                                                                                                                                                                                                                                                                                             |
   |                       |                       | Maximum: **128**                                                                                                                                                                                                                                                                                                                                                                            |
   +-----------------------+-----------------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | value                 | String                | Specifies the value of the match item.                                                                                                                                                                                                                                                                                                                                                      |
   |                       |                       |                                                                                                                                                                                                                                                                                                                                                                                             |
   |                       |                       | -  If **type** is set to **HOST_NAME**, **key** is left blank, and **value** indicates the domain name, which can contain 1 to 128 characters, including letters, digits, hyphens (-), periods (.), and asterisks (*), and must start with a letter, digit, or asterisk (*). If you want to use a wildcard domain name, enter an asterisk (``*``) as the leftmost label of the domain name. |
   |                       |                       |                                                                                                                                                                                                                                                                                                                                                                                             |
   |                       |                       | -  If **type** is set to **PATH**, **key** is left blank, and **value** indicates the request path, which can contain 1 to 128 characters. If **compare_type** is set to **STARTS_WITH** or **EQUAL_TO** for the forwarding rule, the value must start with a slash (/) and can contain only letters, digits, and special characters ``_~';@^-%#&$.*+?,=!:|/()[]{}``                        |
   |                       |                       |                                                                                                                                                                                                                                                                                                                                                                                             |
   |                       |                       | Minimum: **1**                                                                                                                                                                                                                                                                                                                                                                              |
   |                       |                       |                                                                                                                                                                                                                                                                                                                                                                                             |
   |                       |                       | Maximum: **128**                                                                                                                                                                                                                                                                                                                                                                            |
   +-----------------------+-----------------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

Example Requests
----------------

.. code-block:: text

   GET

   https://{elb_endpoint}/v3/99a3fff0d03c428eac3678da6a7d0f24/elb/l7policies/cf4360fd-8631-41ff-a6f5-b72c35da74be/rules

Example Responses
-----------------

**Status code: 200**

Successful request.

.. code-block::

   {
     "rules" : [ {
       "compare_type" : "STARTS_WITH",
       "provisioning_status" : "ACTIVE",
       "project_id" : "99a3fff0d03c428eac3678da6a7d0f24",
       "invert" : false,
       "admin_state_up" : true,
       "value" : "/ccc.html",
       "key" : null,
       "type" : "PATH",
       "id" : "84f4fcae-9c15-4e19-a99f-72c0b08fd3d7"
     } ],
     "page_info" : {
       "previous_marker" : "84f4fcae-9c15-4e19-a99f-72c0b08fd3d7",
       "current_count" : 1
     },
     "request_id" : "ae4dbd7d-9271-4040-98b6-3bfe45bb15ee"
   }

Status Codes
------------

=========== ===================
Status Code Description
=========== ===================
200         Successful request.
=========== ===================

Error Codes
-----------

See :ref:`Error Codes <errorcode>`.

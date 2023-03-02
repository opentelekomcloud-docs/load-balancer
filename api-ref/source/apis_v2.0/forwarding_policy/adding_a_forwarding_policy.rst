:original_name: elb_zq_zf_0001.html

.. _elb_zq_zf_0001:

Adding a Forwarding Policy
==========================

Function
--------

This API is used to add a forwarding policy. The listener and forwarding policy determine how traffic is forwarded to backend servers.

-  By matching the URL or domain name specified in the forwarding policy when **action** is set to **REDIRECT_TO_POOL**, the load balancer distributes the traffic to backend servers in a specific backend server group.
-  When **action** is set to **REDIRECT_TO_LISTENER**, the HTTP listener is redirected to an HTTPS listener, and requests are routed by the HTTPS listener.

Constraints
-----------

Currently, only redirects from an HTTP listener to an HTTPS listener are supported. When **action** is set to **REDIRECT_TO_LISTENER**, the listener specified by **listener_id** can only be an HTTP listener, and the listener specified by **redirect_listener_id** can only be an HTTPS listener.

The load balancer of the HTTPS listener to which traffic is redirected must be the same as that of the HTTP listener.

URI
---

POST /v2.0/lbaas/l7policies

Request
-------

.. table:: **Table 1** Parameter description

   +-----------+-----------+--------+---------------------------------------------------------------------------------------------------------------------------------+
   | Parameter | Mandatory | Type   | Description                                                                                                                     |
   +===========+===========+========+=================================================================================================================================+
   | l7policy  | Yes       | Object | Specifies the forwarding policy. For details, see :ref:`Table 2 <elb_zq_zf_0001__en-us_topic_0136295317_table173601118133515>`. |
   +-----------+-----------+--------+---------------------------------------------------------------------------------------------------------------------------------+

.. _elb_zq_zf_0001__en-us_topic_0136295317_table173601118133515:

.. table:: **Table 2** **l7policy** parameter description

   +----------------------+-----------------+-----------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter            | Mandatory       | Type            | Description                                                                                                                                                           |
   +======================+=================+=================+=======================================================================================================================================================================+
   | tenant_id            | No              | String          | Specifies the ID of the project where the forwarding policy is used.                                                                                                  |
   |                      |                 |                 |                                                                                                                                                                       |
   |                      |                 |                 | The value must be the same as the value of **tenant_id** in the token.                                                                                                |
   |                      |                 |                 |                                                                                                                                                                       |
   |                      |                 |                 | The value contains a maximum of 255 characters.                                                                                                                       |
   +----------------------+-----------------+-----------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | name                 | No              | String          | Specifies the forwarding policy name.                                                                                                                                 |
   |                      |                 |                 |                                                                                                                                                                       |
   |                      |                 |                 | The value contains a maximum of 255 characters.                                                                                                                       |
   +----------------------+-----------------+-----------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | admin_state_up       | No              | Boolean         | Specifies the administrative status of the forwarding policy.                                                                                                         |
   |                      |                 |                 |                                                                                                                                                                       |
   |                      |                 |                 | This parameter is reserved, and the default value is **true**.                                                                                                        |
   +----------------------+-----------------+-----------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | description          | No              | String          | Provides supplementary information about the forwarding policy.                                                                                                       |
   |                      |                 |                 |                                                                                                                                                                       |
   |                      |                 |                 | The value contains a maximum of 255 characters.                                                                                                                       |
   +----------------------+-----------------+-----------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | listener_id          | Yes             | String          | Specifies the ID of the listener to which the forwarding policy is added.                                                                                             |
   |                      |                 |                 |                                                                                                                                                                       |
   |                      |                 |                 | -  When **action** is set to **REDIRECT_TO_POOL**, forwarding policies can be added to a listener with **protocol** set to **HTTP** or **TERMINATED_HTTPS**.          |
   |                      |                 |                 | -  When **action** is set to **REDIRECT_TO_LISTENER**, forwarding policies can be added to a listener with **protocol** set to **HTTP**.                              |
   +----------------------+-----------------+-----------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | action               | Yes             | String          | Specifies whether requests are forwarded to another backend server group or redirected to an HTTPS listener.                                                          |
   |                      |                 |                 |                                                                                                                                                                       |
   |                      |                 |                 | The value can be one of the following:                                                                                                                                |
   |                      |                 |                 |                                                                                                                                                                       |
   |                      |                 |                 | -  **REDIRECT_TO_POOL**: Requests are forwarded to the backend server group specified by **redirect_pool_id**.                                                        |
   |                      |                 |                 | -  **REDIRECT_TO_LISTENER**: Requests are redirected from the HTTP listener specified by **listener_id** to the HTTPS listener specified by **redirect_listener_id**. |
   +----------------------+-----------------+-----------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | redirect_pool_id     | No              | String          | Specifies the ID of the backend server group to which traffic is forwarded. The default value is **null**.                                                            |
   |                      |                 |                 |                                                                                                                                                                       |
   |                      |                 |                 | This parameter is mandatory when **action** is set to **REDIRECT_TO_POOL**.                                                                                           |
   |                      |                 |                 |                                                                                                                                                                       |
   |                      |                 |                 | This parameter cannot be specified when **action** is set to **REDIRECT_TO_LISTENER**.                                                                                |
   |                      |                 |                 |                                                                                                                                                                       |
   |                      |                 |                 | The backend server group must meet the following requirements:                                                                                                        |
   |                      |                 |                 |                                                                                                                                                                       |
   |                      |                 |                 | -  Cannot be the default backend server group of the listener.                                                                                                        |
   |                      |                 |                 | -  Cannot be the backend server group used by forwarding policies of other listeners.                                                                                 |
   +----------------------+-----------------+-----------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | redirect_listener_id | No              | String          | Specifies the ID of the listener to which the traffic is redirected. The default value is **null**.                                                                   |
   |                      |                 |                 |                                                                                                                                                                       |
   |                      |                 |                 | This parameter cannot be specified when **action** is set to **REDIRECT_TO_POOL**.                                                                                    |
   |                      |                 |                 |                                                                                                                                                                       |
   |                      |                 |                 | This parameter is mandatory when **action** is set to **REDIRECT_TO_LISTENER**, and the listener must meet the following requirements:                                |
   |                      |                 |                 |                                                                                                                                                                       |
   |                      |                 |                 | -  Can only be an HTTPS listener.                                                                                                                                     |
   |                      |                 |                 | -  Can only be a listener of the same load balancer.                                                                                                                  |
   +----------------------+-----------------+-----------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | redirect_url         | No              | String          | Specifies the URL to which traffic is redirected. The default value is **null**.                                                                                      |
   |                      |                 |                 |                                                                                                                                                                       |
   |                      |                 |                 | This parameter is reserved.                                                                                                                                           |
   |                      |                 |                 |                                                                                                                                                                       |
   |                      |                 |                 | The value contains a maximum of 255 characters.                                                                                                                       |
   +----------------------+-----------------+-----------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | position             | No              | Integer         | Specifies the forwarding priority. The value ranges from **1** to **100**. The default value is **100**.                                                              |
   |                      |                 |                 |                                                                                                                                                                       |
   |                      |                 |                 | This parameter is reserved.                                                                                                                                           |
   +----------------------+-----------------+-----------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | rules                | No              | Array           | Lists the forwarding rules of the forwarding policy. For details, see :ref:`Table 3 <elb_zq_zf_0001__en-us_topic_0136295317_table16998194317143>`.                    |
   |                      |                 |                 |                                                                                                                                                                       |
   |                      |                 |                 | The list contains a maximum of two rules, and the **type** parameter of each rule must be unique.                                                                     |
   +----------------------+-----------------+-----------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------+

.. _elb_zq_zf_0001__en-us_topic_0136295317_table16998194317143:

.. table:: **Table 3** **rules** parameter description

   +-----------------+-----------------+-----------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter       | Mandatory       | Type            | Description                                                                                                                                                                                                                                                                                  |
   +=================+=================+=================+==============================================================================================================================================================================================================================================================================================+
   | admin_state_up  | No              | Boolean         | Specifies the administrative status of the forwarding rule.                                                                                                                                                                                                                                  |
   |                 |                 |                 |                                                                                                                                                                                                                                                                                              |
   |                 |                 |                 | This parameter is reserved, and the default value is **true**.                                                                                                                                                                                                                               |
   +-----------------+-----------------+-----------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | type            | Yes             | String          | Specifies the match type of a forwarding rule.                                                                                                                                                                                                                                               |
   |                 |                 |                 |                                                                                                                                                                                                                                                                                              |
   |                 |                 |                 | The value range varies depending on the protocol of the backend server group:                                                                                                                                                                                                                |
   |                 |                 |                 |                                                                                                                                                                                                                                                                                              |
   |                 |                 |                 | -  **HOST_NAME**: matches the domain name in the request.                                                                                                                                                                                                                                    |
   |                 |                 |                 | -  **PATH**: matches the path in the request.                                                                                                                                                                                                                                                |
   |                 |                 |                 |                                                                                                                                                                                                                                                                                              |
   |                 |                 |                 | The match type of forwarding rules in a forwarding policy must be unique.                                                                                                                                                                                                                    |
   +-----------------+-----------------+-----------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | compare_type    | Yes             | String          | Specifies the match mode. The options are as follows:                                                                                                                                                                                                                                        |
   |                 |                 |                 |                                                                                                                                                                                                                                                                                              |
   |                 |                 |                 | When **type** is set to **HOST_NAME**, the value of this parameter can only be the following:                                                                                                                                                                                                |
   |                 |                 |                 |                                                                                                                                                                                                                                                                                              |
   |                 |                 |                 | -  **EQUAL_TO**: indicates exact match.                                                                                                                                                                                                                                                      |
   |                 |                 |                 |                                                                                                                                                                                                                                                                                              |
   |                 |                 |                 | When **type** is set to **PATH**, the value of this parameter can be one of the following:                                                                                                                                                                                                   |
   |                 |                 |                 |                                                                                                                                                                                                                                                                                              |
   |                 |                 |                 | -  **REGEX**: indicates regular expression match.                                                                                                                                                                                                                                            |
   |                 |                 |                 | -  **STARTS_WITH**: indicates prefix match.                                                                                                                                                                                                                                                  |
   |                 |                 |                 | -  **EQUAL_TO**: indicates exact match.                                                                                                                                                                                                                                                      |
   +-----------------+-----------------+-----------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | invert          | No              | Boolean         | Specifies whether reverse matching is supported.                                                                                                                                                                                                                                             |
   |                 |                 |                 |                                                                                                                                                                                                                                                                                              |
   |                 |                 |                 | The value can be **true** or **false**. The default value is **false**.                                                                                                                                                                                                                      |
   |                 |                 |                 |                                                                                                                                                                                                                                                                                              |
   |                 |                 |                 | This parameter is reserved.                                                                                                                                                                                                                                                                  |
   +-----------------+-----------------+-----------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | key             | No              | String          | Specifies the key of the match content. The default value is **null**.                                                                                                                                                                                                                       |
   |                 |                 |                 |                                                                                                                                                                                                                                                                                              |
   |                 |                 |                 | This parameter is reserved.                                                                                                                                                                                                                                                                  |
   +-----------------+-----------------+-----------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | value           | Yes             | String          | Specifies the value of the match content. The value cannot contain spaces.                                                                                                                                                                                                                   |
   |                 |                 |                 |                                                                                                                                                                                                                                                                                              |
   |                 |                 |                 | -  When **type** is set to **HOST_NAME**, the value can contain a maximum of 100 characters that contain only letters, digits, hyphens (-), and periods (.), and must start with a letter or digit.                                                                                          |
   |                 |                 |                 | -  When **type** is set to **PATH**, the value can contain a maximum of 128 characters. When **compare_type** is set to **STARTS_WITH** or **EQUAL_TO**, the value must start with a slash (/) and can contain only letters, digits, and special characters ``_~';@^-%#&$.*+?,=!:|\/()[]{}`` |
   +-----------------+-----------------+-----------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

Response
--------

.. table:: **Table 4** Response parameters

   +-----------+--------+-------------------------------------------------------------------------------------------------------------------------------+
   | Parameter | Type   | Description                                                                                                                   |
   +===========+========+===============================================================================================================================+
   | l7policy  | Object | Specifies the forwarding policy. For details, see :ref:`Table 5 <elb_zq_zf_0001__en-us_topic_0136295317_table1251155618376>`. |
   +-----------+--------+-------------------------------------------------------------------------------------------------------------------------------+

.. _elb_zq_zf_0001__en-us_topic_0136295317_table1251155618376:

.. table:: **Table 5** **l7policy** parameter description

   +-----------------------+-----------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter             | Type                  | Description                                                                                                                                                           |
   +=======================+=======================+=======================================================================================================================================================================+
   | id                    | String                | Specifies the forwarding policy ID.                                                                                                                                   |
   +-----------------------+-----------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | tenant_id             | String                | Specifies the ID of the project where the forwarding policy is used.                                                                                                  |
   +-----------------------+-----------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | name                  | String                | Specifies the forwarding policy name.                                                                                                                                 |
   +-----------------------+-----------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | admin_state_up        | Boolean               | Specifies the administrative status of the forwarding policy.                                                                                                         |
   |                       |                       |                                                                                                                                                                       |
   |                       |                       | This parameter is reserved. The value can be **true** or **false**.                                                                                                   |
   |                       |                       |                                                                                                                                                                       |
   |                       |                       | -  **true**: Enabled                                                                                                                                                  |
   |                       |                       | -  **false**: Disabled                                                                                                                                                |
   +-----------------------+-----------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | description           | String                | Provides supplementary information about the forwarding policy.                                                                                                       |
   +-----------------------+-----------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | listener_id           | String                | Specifies the ID of the listener to which the forwarding policy is added.                                                                                             |
   +-----------------------+-----------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | action                | String                | Specifies whether requests are forwarded to another backend server group or redirected to an HTTPS listener.                                                          |
   |                       |                       |                                                                                                                                                                       |
   |                       |                       | The value can be one of the following:                                                                                                                                |
   |                       |                       |                                                                                                                                                                       |
   |                       |                       | -  **REDIRECT_TO_POOL**: Requests are forwarded to the backend server group specified by **redirect_pool_id**.                                                        |
   |                       |                       | -  **REDIRECT_TO_LISTENER**: Requests are redirected from the HTTP listener specified by **listener_id** to the HTTPS listener specified by **redirect_listener_id**. |
   +-----------------------+-----------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | redirect_pool_id      | String                | Specifies the ID of the backend server group to which traffic is forwarded.                                                                                           |
   +-----------------------+-----------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | redirect_listener_id  | String                | Specifies the ID of the listener to which the traffic is redirected.                                                                                                  |
   +-----------------------+-----------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | redirect_url          | String                | Specifies the URL to which traffic is redirected.                                                                                                                     |
   |                       |                       |                                                                                                                                                                       |
   |                       |                       | This parameter is reserved.                                                                                                                                           |
   +-----------------------+-----------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | rules                 | Array                 | Lists the forwarding rules of the forwarding policy. For details, see :ref:`Table 6 <elb_zq_zf_0001__en-us_topic_0136295317_table129777459104>`.                      |
   +-----------------------+-----------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | position              | Integer               | Specifies the forwarding priority. The value ranges from **1** to **100**. The default value is **100**.                                                              |
   |                       |                       |                                                                                                                                                                       |
   |                       |                       | This parameter is reserved.                                                                                                                                           |
   +-----------------------+-----------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | provisioning_status   | String                | This parameter is reserved, and its value can only be **ACTIVE**.                                                                                                     |
   |                       |                       |                                                                                                                                                                       |
   |                       |                       | It specifies the provisioning status of the forwarding policy.                                                                                                        |
   +-----------------------+-----------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------+

.. _elb_zq_zf_0001__en-us_topic_0136295317_table129777459104:

.. table:: **Table 6** **rules** parameter description

   +-----------+--------+-----------------------------------------------------------------+
   | Parameter | Type   | Description                                                     |
   +===========+========+=================================================================+
   | id        | String | Lists the IDs of the forwarding rules in the forwarding policy. |
   +-----------+--------+-----------------------------------------------------------------+

Example Request
---------------

-  Example request 1: Adding a forwarding policy

   .. code-block:: text

      POST https://{Endpoint}/v2.0/lbaas/l7policies

      {
          "l7policy": {
              "name": "niubiao_yaqing_api-2",
              "listener_id": "3e24a3ca-11e5-4aa3-abd4-61ba0a8a18f1",
              "action": "REDIRECT_TO_POOL",
              "redirect_pool_id": "6460f13a-76de-43c7-b776-4fefc06a676e",
              "rules": [
                  {
                      "type": "PATH",
                      "compare_type": "EQUAL_TO",
                      "value": "/test"
                  },
                  {
                      "type": "HOST_NAME",
                      "compare_type": "EQUAL_TO",
                      "value": "www.test.com"
                  }
              ]
          }
      }

-  Example request 2: Creating a redirect

   .. code-block:: text

      POST https://{Endpoint}/v2.0/lbaas/l7policies

      {
          "l7policy": {
              "action": "REDIRECT_TO_LISTENER",
              "listener_id": "4ef8553e-9ef7-4859-a42d-919feaf89d60",
              "redirect_listener_id": "3ee10199-a7b4-4784-93cd-857afe9d0890",
              "name": "redirect-test"
          }
      }

Example Response
----------------

-  Example response 1

   .. code-block::

      {
          "l7policy": {
              "redirect_pool_id": "6460f13a-76de-43c7-b776-4fefc06a676e",
              "description": "",
              "admin_state_up": true,
              "rules": [
                  {
                      "id": "742600d9-2a14-4808-af69-336883dbb590"
                  },
                  {
                      "id": "3251ed77-0d52-412b-9310-733636bb3fbf"
                  }
              ],
              "tenant_id": "573d73c9f90e48d0bddfa0eb202b25c2",
              "listener_id": "3e24a3ca-11e5-4aa3-abd4-61ba0a8a18f1",
              "redirect_url": null,
              "redirect_listener_id": null,
              "action": "REDIRECT_TO_POOL",
              "position": 100,
              "provisioning_status": "ACTIVE",

              "id": "65d6e115-f179-4bcd-9bbb-1484e5f8ee81",
              "name": "niubiao_yaqing-_api-2"
          }
      }

-  Example response 2

   .. code-block::

      {
          "l7policy": {
              "redirect_pool_id": null,
              "description": "",
              "admin_state_up": true,
              "rules": [ ],
              "tenant_id": "573d73c9f90e48d0bddfa0eb202b25c2",
              "listener_id": "4ef8553e-9ef7-4859-a42d-919feaf89d60",
              "redirect_url": null,
              "redirect_listener_id": "3ee10199-a7b4-4784-93cd-857afe9d0890",
              "action": "REDIRECT_TO_LISTENER",
              "position": 100,
              "provisioning_status": "ACTIVE",
              "id": "bc4e4338-480f-4a98-8245-5bb1964f0e1d",
              "name": "redirect-test"
          }
      }

Status Code
-----------

For details, see :ref:`HTTP Status Codes of Shared Load Balancers <elb_gc_0002>`.

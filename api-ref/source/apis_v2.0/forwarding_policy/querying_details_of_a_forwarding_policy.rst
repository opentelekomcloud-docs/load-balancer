:original_name: elb_zq_zf_0003.html

.. _elb_zq_zf_0003:

Querying Details of a Forwarding Policy
=======================================

Function
--------

This API is used to query details about a forwarding policy.

URI
---

GET /v2.0/lbaas/l7policies/{l7policy_id}

.. table:: **Table 1** Parameter description

   =========== ========= ====== ===================================
   Parameter   Mandatory Type   Description
   =========== ========= ====== ===================================
   l7policy_id Yes       String Specifies the forwarding policy ID.
   =========== ========= ====== ===================================

Request
-------

None

Response
--------

.. table:: **Table 2** Parameter description

   +-----------+--------+--------------------------------------------------------------------------------------------------------------------------------+
   | Parameter | Type   | Description                                                                                                                    |
   +===========+========+================================================================================================================================+
   | l7policy  | Object | Specifies the forwarding policy. For details, see :ref:`Table 3 <elb_zq_zf_0003__en-us_topic_0136295316_table77011444133616>`. |
   +-----------+--------+--------------------------------------------------------------------------------------------------------------------------------+

.. _elb_zq_zf_0003__en-us_topic_0136295316_table77011444133616:

.. table:: **Table 3** **l7policy** parameter description

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

.. table:: **Table 4** **rules** parameter description

   +-----------+--------+-----------------------------------------------------------------+
   | Parameter | Type   | Description                                                     |
   +===========+========+=================================================================+
   | id        | String | Lists the IDs of the forwarding rules in the forwarding policy. |
   +-----------+--------+-----------------------------------------------------------------+

Example Request
---------------

-  Example request: Querying details of a forwarding policy

   .. code-block:: text

      GET https://{Endpoint}/v2.0/lbaas/l7policies/5ae0e1e7-5f0f-47a1-b39f-5d4c428a1586

Example Response
----------------

-  Example response

   .. code-block::

      {
          "l7policy": {
              "redirect_pool_id": "431a03eb-81bb-408e-ae37-7ce19023692b",
              "redirect_listener_id": null,
              "description": "",
              "admin_state_up": true,
              "rules": [
                  {
                      "id": "67d8a8fa-b0dd-4bd4-a85b-671db19b2ef3"
                  },
                  {
                      "id": "f02b3bca-69d2-4335-a3fa-a8054e996213"
                  }
              ],
              "tenant_id": "a31d2bdcf7604c0faaddb058e1e08819",
              "listener_id": "26058b64-6185-4e06-874e-4bd68b7633d0",
              "redirect_url": null,
              "provisioning_status": "ACTIVE",
              "action": "REDIRECT_TO_POOL",
              "position": 1,
              "id": "5ae0e1e7-5f0f-47a1-b39f-5d4c428a1586",
              "name": "l7policy-garry-1"
          }
      }

Status Code
-----------

For details, see :ref:`Status Codes <elb_gc_1102>`.

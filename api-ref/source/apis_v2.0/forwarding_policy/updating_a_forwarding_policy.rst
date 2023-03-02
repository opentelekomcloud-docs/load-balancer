:original_name: elb_zq_zf_0004.html

.. _elb_zq_zf_0004:

Updating a Forwarding Policy
============================

Function
--------

This API is used to update a forwarding policy. You can select another backend server group or redirect to another HTTPS listener.

URI
---

PUT /v2.0/lbaas/l7policies/{l7policy_id}

.. table:: **Table 1** Parameter description

   =========== ========= ====== ===================================
   Parameter   Mandatory Type   Description
   =========== ========= ====== ===================================
   l7policy_id Yes       Object Specifies the forwarding policy ID.
   =========== ========= ====== ===================================

Request
-------

.. table:: **Table 2** Parameter description

   +-----------+-----------+--------+-------------------------------------------------------------------------------------------------------------------------------+
   | Parameter | Mandatory | Type   | Description                                                                                                                   |
   +===========+===========+========+===============================================================================================================================+
   | l7policy  | Yes       | Object | Specifies the forwarding policy. For details, see :ref:`Table 3 <elb_zq_zf_0004__en-us_topic_0136295318_table7905034124412>`. |
   +-----------+-----------+--------+-------------------------------------------------------------------------------------------------------------------------------+

.. _elb_zq_zf_0004__en-us_topic_0136295318_table7905034124412:

.. table:: **Table 3** **l7policy** parameter description

   +----------------------+-----------------+-----------------+---------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter            | Mandatory       | Type            | Description                                                                                                                           |
   +======================+=================+=================+=======================================================================================================================================+
   | name                 | No              | String          | Specifies the forwarding policy name.                                                                                                 |
   |                      |                 |                 |                                                                                                                                       |
   |                      |                 |                 | The value contains a maximum of 255 characters.                                                                                       |
   +----------------------+-----------------+-----------------+---------------------------------------------------------------------------------------------------------------------------------------+
   | description          | No              | String          | Provides supplementary information about the forwarding policy.                                                                       |
   |                      |                 |                 |                                                                                                                                       |
   |                      |                 |                 | The value contains a maximum of 255 characters.                                                                                       |
   +----------------------+-----------------+-----------------+---------------------------------------------------------------------------------------------------------------------------------------+
   | redirect_pool_id     | No              | String          | Specifies the ID of the backend server group to which traffic is forwarded. The default value is **null**.                            |
   |                      |                 |                 |                                                                                                                                       |
   |                      |                 |                 | This parameter is mandatory when **action** is set to **REDIRECT_TO_POOL**.                                                           |
   |                      |                 |                 |                                                                                                                                       |
   |                      |                 |                 | This parameter cannot be specified when **action** is set to **REDIRECT_TO_LISTENER**.                                                |
   |                      |                 |                 |                                                                                                                                       |
   |                      |                 |                 | The backend server group must meet the following requirements:                                                                        |
   |                      |                 |                 |                                                                                                                                       |
   |                      |                 |                 | -  Cannot be the default backend server group of the listener.                                                                        |
   |                      |                 |                 | -  Cannot be the backend server group used by forwarding policies of other listeners.                                                 |
   +----------------------+-----------------+-----------------+---------------------------------------------------------------------------------------------------------------------------------------+
   | redirect_listener_id | No              | String          | Specifies the ID of the listener to which the traffic is redirected. The default value is **null**.                                   |
   |                      |                 |                 |                                                                                                                                       |
   |                      |                 |                 | This parameter is mandatory when **action** is set to **REDIRECT_TO_LISTENER**.                                                       |
   |                      |                 |                 |                                                                                                                                       |
   |                      |                 |                 | This parameter cannot be specified when **action** is set to **REDIRECT_TO_POOL**. The listener must meet the following requirements: |
   |                      |                 |                 |                                                                                                                                       |
   |                      |                 |                 | -  Can only be an HTTPS listener.                                                                                                     |
   |                      |                 |                 | -  Can only be a listener of the same load balancer.                                                                                  |
   +----------------------+-----------------+-----------------+---------------------------------------------------------------------------------------------------------------------------------------+
   | admin_state_up       | No              | Boolean         | Specifies the administrative status of the forwarding policy.                                                                         |
   |                      |                 |                 |                                                                                                                                       |
   |                      |                 |                 | This parameter is reserved, and the default value is **true**.                                                                        |
   +----------------------+-----------------+-----------------+---------------------------------------------------------------------------------------------------------------------------------------+

Response
--------

.. table:: **Table 4** Response parameters

   +-----------+-----------+--------+--------------------------------------------------------------------------------------------------------------------------------+
   | Parameter | Mandatory | Type   | Description                                                                                                                    |
   +===========+===========+========+================================================================================================================================+
   | l7policy  | Yes       | Object | Specifies the forwarding policy. For details, see :ref:`Table 5 <elb_zq_zf_0004__en-us_topic_0136295318_table20746114154514>`. |
   +-----------+-----------+--------+--------------------------------------------------------------------------------------------------------------------------------+

.. _elb_zq_zf_0004__en-us_topic_0136295318_table20746114154514:

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

.. table:: **Table 6** **rules** parameter description

   +-----------+--------+-----------------------------------------------------------------+
   | Parameter | Type   | Description                                                     |
   +===========+========+=================================================================+
   | id        | String | Lists the IDs of the forwarding rules in the forwarding policy. |
   +-----------+--------+-----------------------------------------------------------------+

Example Request
---------------

-  Example request: Updating a forwarding policy

   .. code-block:: text

      PUT https://{Endpoint}/v2.0/lbaas/l7policies/5ae0e1e7-5f0f-47a1-b39f-5d4c428a1586

      {
          "l7policy": {
              "name": "test"
          }
      }

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
              "action": "REDIRECT_TO_POOL",
              "provisioning_status": "ACTIVE",
              "position": 2,
              "id": "5ae0e1e7-5f0f-47a1-b39f-5d4c428a1586",
              "name": "test"
          }
      }

Status Code
-----------

For details, see :ref:`HTTP Status Codes of Shared Load Balancers <elb_gc_0002>`.

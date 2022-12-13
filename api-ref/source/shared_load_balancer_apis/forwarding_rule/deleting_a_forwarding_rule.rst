:original_name: elb_zq_zg_0005.html

.. _elb_zq_zg_0005:

Deleting a Forwarding Rule
==========================

Function
--------

This API is used to delete a specific forwarding rule.

URI
---

DELETE /v2.0/lbaas/l7policies/{l7policy_id}/rules/{l7rule_id}

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

None

Example Request
---------------

-  Example request: Deleting a forwarding rule

   .. code-block:: text

      DELETE https://{Endpoint}/v2.0/lbaas/l7policies/5ae0e1e7-5f0f-47a1-b39f-5d4c428a1586/rules/c6f457b8-bf6f-45d7-be5c-a3226945b7b1

Example Response
----------------

-  Example response

   None

Status Code
-----------

For details, see :ref:`HTTP Status Codes of Shared Load Balancers <elb_gc_0002>`.

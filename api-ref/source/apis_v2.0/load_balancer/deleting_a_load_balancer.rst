:original_name: elb_zq_fz_0006.html

.. _elb_zq_fz_0006:

Deleting a Load Balancer
========================

Function
--------

This API is used to delete a specific load balancer.

Constraints
-----------

All listeners added to the load balancer must be deleted before the load balancer is deleted.

URI
---

DELETE /v2.0/lbaas/loadbalancers/{loadbalancer_id}

.. table:: **Table 1** Parameter description

   =============== ========= ====== ===============================
   Parameter       Mandatory Type   Description
   =============== ========= ====== ===============================
   loadbalancer_id Yes       String Specifies the load balancer ID.
   =============== ========= ====== ===============================

Request
-------

None

Response
--------

None

Example Request
---------------

Example request: Deleting a load balancer

.. code-block:: text

   DELETE https://{endpoint}/v2.0/lbaas/loadbalancers/90f7c765-0bc9-47c4-8513-4cc0c264c8f8

Example Response
----------------

Example response

None

Status Code
-----------

For details, see :ref:`Status Codes <elb_gc_1102>`.

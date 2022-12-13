:original_name: elb_zq_jt_0005.html

.. _elb_zq_jt_0005:

Deleting a Listener
===================

Function
--------

This API is used to delete a listener by ID.

Constraints
-----------

All backend server groups associated with the listener must be deleted before the listener is deleted.

URI
---

DELETE /v2.0/lbaas/listeners/{listener_id}

.. table:: **Table 1** Parameter description

   =========== ========= ====== ==========================
   Parameter   Mandatory Type   Description
   =========== ========= ====== ==========================
   listener_id Yes       String Specifies the listener ID.
   =========== ========= ====== ==========================

Request
-------

None

Response
--------

None

Example Request
---------------

-  Example request: Deleting a listener

   .. code-block:: text

      DELETE https://{Endpoint}/v2.0/lbaas/listeners/35cb8516-1173-4035-8dae-0dae3453f37f

Example Response
----------------

-  Example response

   None

Status Code
-----------

For details, see :ref:`HTTP Status Codes of Shared Load Balancers <elb_gc_0002>`.

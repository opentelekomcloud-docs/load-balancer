:original_name: elb_zq_bm_0005.html

.. _elb_zq_bm_0005:

Deleting a Whitelist
====================

Function
--------

This API is used to delete a specific whitelist.

URI
---

DELETE /v2.0/lbaas/whitelists/{whitelist_id}

.. table:: **Table 1** Parameter description

   ============ ========= ====== ===========================
   Parameter    Mandatory Type   Description
   ============ ========= ====== ===========================
   whitelist_id Yes       String Specifies the whitelist ID.
   ============ ========= ====== ===========================

Request
-------

None

Response
--------

None

Example Request
---------------

-  Example request: Deleting a whitelist

   .. code-block:: text

      DELETE https://{Endpoint}/v2.0/lbaas/whitelists/35cb8516-1173-4035-8dae-0dae3453f37f

Example Response
----------------

-  Example response 1

   None

Status Code
-----------

For details, see :ref:`HTTP Status Codes of Shared Load Balancers <elb_gc_0002>`.

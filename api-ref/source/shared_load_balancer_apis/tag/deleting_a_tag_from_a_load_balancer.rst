:original_name: elb_zq_bq_0006.html

.. _elb_zq_bq_0006:

Deleting a Tag from a Load Balancer
===================================

Function
--------

This API is used to delete a tag with a specific key from a load balancer.

.. note::

   You can also use this API for dedicated load balancers.

Constraints
-----------

None

URI
---

DELETE /v2.0/{project_id}/loadbalancers/{loadbalancer_id}/tags/{key}

.. table:: **Table 1** Parameter description

   +-----------------+-----------+--------+--------------------------------------------------------------------------+
   | Parameter       | Mandatory | Type   | Description                                                              |
   +=================+===========+========+==========================================================================+
   | project_id      | Yes       | String | Specifies the ID of the project where the tag is used.                   |
   +-----------------+-----------+--------+--------------------------------------------------------------------------+
   | loadbalancer_id | Yes       | String | Specifies the ID of the load balancer from which a tag is to be deleted. |
   +-----------------+-----------+--------+--------------------------------------------------------------------------+

Request
-------

None

Response
--------

None

Example Request
---------------

-  Example request

   .. code-block:: text

      DELETE https://{Endpoint}/v2.0/6a0de1c3-7d74-4f4a-b75e-e57135bd2b97/loadbalancers/7add33ad-11dc-4ab9-a50f-419703f13163/tags/key1

Example Response
----------------

-  Example response

   None

Status Code
-----------

For details, see :ref:`Status Codes <elb_zq_bq_0013>`.

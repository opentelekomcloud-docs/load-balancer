:original_name: DeleteLoadBalancer.html

.. _DeleteLoadBalancer:

Deleting a Load Balancer
========================

Function
--------

This API is used to delete a load balancer.

Constraints
-----------

All listeners added to the load balancer must be deleted before the load balancer is deleted.

URI
---

DELETE /v3/{project_id}/elb/loadbalancers/{loadbalancer_id}

.. table:: **Table 1** Path Parameters

   =============== ========= ====== ===============================
   Parameter       Mandatory Type   Description
   =============== ========= ====== ===============================
   project_id      Yes       String Specifies the project ID.
   loadbalancer_id Yes       String Specifies the load balancer ID.
   =============== ========= ====== ===============================

Request Parameters
------------------

.. table:: **Table 2** Request header parameters

   +--------------+-----------+--------+--------------------------------------------------+
   | Parameter    | Mandatory | Type   | Description                                      |
   +==============+===========+========+==================================================+
   | X-Auth-Token | Yes       | String | Specifies the token used for IAM authentication. |
   +--------------+-----------+--------+--------------------------------------------------+

Response Parameters
-------------------

None

Example Requests
----------------

Deleting a load balancer

.. code-block:: text

   DELETE https://{ELB_Endpoint}/v3/060576782980d5762f9ec014dd2f1148/elb/loadbalancers/32c1057f-74a1-42d6-9b20-d55b80ab89c4

Example Responses
-----------------

None

Status Codes
------------

=========== ===================
Status Code Description
=========== ===================
204         Successful request.
=========== ===================

Error Codes
-----------

See :ref:`Error Codes <errorcode>`.

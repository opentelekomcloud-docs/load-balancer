:original_name: elb_jd_fz_0003.html

.. _elb_jd_fz_0003:

Deleting a Public Network Load Balancer
=======================================

Function
--------

This API is used to delete a public network load balancer. The EIP bound to the load balancer will not be deleted. If you need to delete this IP address, refer to :ref:`Deleting a Load Balancer <elb_jd_fz_0002>`.

Constraints
-----------

Before deleting a public network load balancer, you must remove all backend ECSs from the listener. This API cannot be used to delete a private network load balancer.

URI
---

DELETE /v1.0/{project_id}/elbaas/loadbalancers/{loadbalancer_id}/keep-eip

.. table:: **Table 1** Parameter description

   =============== ========= ====== ===============================
   Parameter       Mandatory Type   Description
   =============== ========= ====== ===============================
   project_id      Yes       String Specifies the project ID.
   loadbalancer_id Yes       String Specifies the load balancer ID.
   =============== ========= ====== ===============================

Request
-------

-  Request parameters

   None

-  Example request

   None

Response
--------

-  Response parameters

   .. table:: **Table 2** Parameter description

      +-----------+--------+-----------------------------------------------------------------------------------------------------+
      | Parameter | Type   | Description                                                                                         |
      +===========+========+=====================================================================================================+
      | uri       | String | Specifies the URI returned by Combined API after the job for deleting a load balancer is delivered. |
      +-----------+--------+-----------------------------------------------------------------------------------------------------+
      | job_id    | String | Specifies the unique ID assigned to the job for deleting a load balancer in Combined API.           |
      +-----------+--------+-----------------------------------------------------------------------------------------------------+

-  Example response

   .. code-block::

      {
          "uri": "/v1/8263303061de4b5d95c9cb68c3a257f4/jobs/ff808082615b23aa01616b90efc65298",
          "job_id": "ff808082615b23aa01616b90efc65298"
      }

Status Code
-----------

-  Normal

   200

-  Error

   +-------------+--------------------+----------------------------------------------------------+
   | Status Code | Message            | Description                                              |
   +=============+====================+==========================================================+
   | 400         | badRequest         | Request error.                                           |
   +-------------+--------------------+----------------------------------------------------------+
   | 401         | unauthorized       | Authentication failed.                                   |
   +-------------+--------------------+----------------------------------------------------------+
   | 403         | userDisable        | You do not have the permission to perform the operation. |
   +-------------+--------------------+----------------------------------------------------------+
   | 404         | Not Found          | The requested page does not exist.                       |
   +-------------+--------------------+----------------------------------------------------------+
   | 500         | authFault          | System error.                                            |
   +-------------+--------------------+----------------------------------------------------------+
   | 503         | serviceUnavailable | The service is unavailable.                              |
   +-------------+--------------------+----------------------------------------------------------+

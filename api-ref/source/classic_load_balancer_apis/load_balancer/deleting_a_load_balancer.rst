:original_name: elb_jd_fz_0002.html

.. _elb_jd_fz_0002:

Deleting a Load Balancer
========================

Function
--------

This API is used to delete a load balancer. If the load balancer is a public network load balancer, this API deletes the EIP bound to the load balancer.

Constraints
-----------

For a public network load balancer, you need to delete the backend ECSs added to all listeners of the load balancer before deleting it.

URI
---

DELETE /v1.0/{project_id}/elbaas/loadbalancers/{loadbalancer_id}

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
          "uri": "/v1/73cd9140bec7427ab9952b4ed75924e0/jobs/4010b39c4fbb4649014fcfd2ab7903b0",
          "job_id": "4010b39c4fbb4649014fcfd2ab7903b0"
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
   | 403         | userDisabled       | You do not have the permission to perform the operation. |
   +-------------+--------------------+----------------------------------------------------------+
   | 404         | Not Found          | The requested page does not exist.                       |
   +-------------+--------------------+----------------------------------------------------------+
   | 500         | authFault          | System error.                                            |
   +-------------+--------------------+----------------------------------------------------------+
   | 503         | serviceUnavailable | The service is unavailable.                              |
   +-------------+--------------------+----------------------------------------------------------+

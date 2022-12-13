:original_name: elb_jd_hd_0001.html

.. _elb_jd_hd_0001:

Adding Backend ECSs
===================

Function
--------

This API is used to add backend ECSs to a listener for monitoring.

To add backend ECSs to a UDP listener, IP addresses can be pinged and UDP services must be enabled.

URI
---

POST /v1.0/{project_id}/elbaas/listeners/{listener_id}/members

.. table:: **Table 1** Parameter description

   +-------------+-----------+--------+------------------------------------------------------+
   | Parameter   | Mandatory | Type   | Description                                          |
   +=============+===========+========+======================================================+
   | project_id  | Yes       | String | Specifies the project ID.                            |
   +-------------+-----------+--------+------------------------------------------------------+
   | listener_id | Yes       | String | Specifies the listener ID.                           |
   +-------------+-----------+--------+------------------------------------------------------+
   | server_id   | Yes       | String | Specifies the backend ECS ID.                        |
   +-------------+-----------+--------+------------------------------------------------------+
   | address     | Yes       | String | Specifies the private IP address of the backend ECS. |
   +-------------+-----------+--------+------------------------------------------------------+

Request
-------

-  Request parameters

   None

-  Example request

   .. code-block::

      [
          {
              "server_id": "dbecb618-2259-405f-ab17-9b68c4f541b0",
              "address": "172.16.0.31"
          }
      ]

Response
--------

-  Response parameters

   .. table:: **Table 2** Parameter description

      +-----------+--------+----------------------------------------------------------------------------------------+
      | Parameter | Type   | Description                                                                            |
      +===========+========+========================================================================================+
      | uri       | String | Specifies the URI of the job for adding a backend ECS. It is returned by Combined API. |
      +-----------+--------+----------------------------------------------------------------------------------------+
      | job_id    | String | Specifies the unique ID assigned to the job for adding a backend ECS in Combined API.  |
      +-----------+--------+----------------------------------------------------------------------------------------+

-  Example response

   .. code-block::

      {
          "uri": "/v1/55300f3c8f764c06b1a32e2302edc305/jobs/4010b39b4fd3d5ff014fd3ec3ed8002d",
          "job_id": "4010b39b4fd3d5ff014fd3ec3ed8002d"
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

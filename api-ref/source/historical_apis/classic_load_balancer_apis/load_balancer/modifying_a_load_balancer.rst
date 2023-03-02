:original_name: elb_jd_fz_0004.html

.. _elb_jd_fz_0004:

Modifying a Load Balancer
=========================

Function
--------

This API is used to modify the name, description, bandwidth, and administrative status of a load balancer.

URI
---

PUT /v1.0/{project_id}/elbaas/loadbalancers/{loadbalancer_id}

.. table:: **Table 1** Parameter description

   +-----------------+-----------------+-----------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter       | Mandatory       | Type            | Description                                                                                                                                               |
   +=================+=================+=================+===========================================================================================================================================================+
   | project_id      | Yes             | String          | Specifies the project ID.                                                                                                                                 |
   +-----------------+-----------------+-----------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------+
   | loadbalancer_id | Yes             | String          | Specifies the load balancer ID.                                                                                                                           |
   +-----------------+-----------------+-----------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------+
   | name            | No              | String          | -  Specifies the load balancer name.                                                                                                                      |
   |                 |                 |                 | -  The value can contain 1 to 64 characters that consist of letters, digits, underscores (_), and hyphens (-).                                            |
   +-----------------+-----------------+-----------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------+
   | description     | No              | String          | -  Provides supplementary information about the load balancer.                                                                                            |
   |                 |                 |                 | -  The value contains 0 to 128 characters and cannot contain angle brackets (< and >).                                                                    |
   +-----------------+-----------------+-----------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------+
   | bandwidth       | No              | Integer         | -  Specifies the bandwidth (Mbit/s). This parameter is mandatory when **type** is set to **External**.                                                    |
   |                 |                 |                 |                                                                                                                                                           |
   |                 |                 |                 | -  The value ranges from 1 to 500.                                                                                                                        |
   |                 |                 |                 |                                                                                                                                                           |
   |                 |                 |                 |    (The specific range may vary depending on the configuration in each region. You can see the bandwidth range of each region on the management console.) |
   +-----------------+-----------------+-----------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------+
   | admin_state_up  | No              | Integer/Boolean | -  Specifies the administrative status of the load balancer.                                                                                              |
   |                 |                 |                 |                                                                                                                                                           |
   |                 |                 |                 | -  Optional values:                                                                                                                                       |
   |                 |                 |                 |                                                                                                                                                           |
   |                 |                 |                 |    **0** or **false**: indicates that the load balancer is stopped. Only users are allowed to enter the two values.                                       |
   |                 |                 |                 |                                                                                                                                                           |
   |                 |                 |                 |    **1** or **true**: indicates that the load balancer is running properly.                                                                               |
   |                 |                 |                 |                                                                                                                                                           |
   |                 |                 |                 |    **2** or **false**: indicates that the load balancer is frozen. Only the administrator is allowed to enter the two values.                             |
   +-----------------+-----------------+-----------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------+

Request
-------

-  Request parameters

   None

-  Example request

   .. code-block::

      {
          "description": "simple lb",
          "name": "loadbalancer1",
          "bandwidth": 200,
          "admin_state_up": true
      }

Response
--------

-  Response parameters

   .. table:: **Table 2** Parameter description

      +-----------+--------+------------------------------------------------------------------------------------------------------+
      | Parameter | Type   | Description                                                                                          |
      +===========+========+======================================================================================================+
      | uri       | String | Specifies the URI returned by Combined API after the job for modifying a load balancer is delivered. |
      +-----------+--------+------------------------------------------------------------------------------------------------------+
      | job_id    | String | Specifies the unique ID assigned to the job for modifying a load balancer in Combined API.           |
      +-----------+--------+------------------------------------------------------------------------------------------------------+

-  Example response

   .. code-block::

      {
          "uri": "/v1/73cd9140bec7427ab9952b4ed75924e0/jobs/4010b39d4fbb4645014fcfddf4b32d15",
          "job_id": "4010b39d4fbb4645014fcfddf4b32d15"
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

Querying the Job Status
#######################

Function
^^^^^^^^

This API is used to query the job status, such as the execution status of creating or deleting a load balancer.

URI
^^^

GET /v1.0/{project_id}/jobs/{job_id}

.. table:: **Table 1** Parameter description

   ========== ========= ====== =========================
   Parameter  Mandatory Type   Description
   ========== ========= ====== =========================
   project_id Yes       String Specifies the project ID.
   job_id     Yes       String Specifies the job ID.
   ========== ========= ====== =========================

Request
^^^^^^^

-  Request parameters

   None

-  Example request

   None

Response
^^^^^^^^

-  Response parameters

.. table:: **Table 2** Parameter description

   +-------------+-----------+--------+-----------------------------+
   | Parameter   | Mandatory | Type   | Description                 |
   +=============+===========+========+=============================+
   | status      | Yes       | String | Specifies the job status.   |
   |             |           |        |                             |
   |             |           |        | -  **SUCCESS**: The job was |
   |             |           |        |    successfully executed.   |
   |             |           |        | -  **RUNNING**: The job is  |
   |             |           |        |    in progress.             |
   |             |           |        | -  **FAIL**: The job        |
   |             |           |        |    failed.                  |
   |             |           |        | -  **INIT**: The job is     |
   |             |           |        |    being initialized.       |
   +-------------+-----------+--------+-----------------------------+
   | entities    | Yes       | Object | Specifies the response to   |
   |             |           |        | the job. Each type of job   |
   |             |           |        | has different contents.     |
   +-------------+-----------+--------+-----------------------------+
   | job_id      | Yes       | String | Specifies the job ID.       |
   +-------------+-----------+--------+-----------------------------+
   | job_type    | Yes       | String | Specifies the job type.     |
   +-------------+-----------+--------+-----------------------------+
   | begin_time  | Yes       | String | Specifies the time when the |
   |             |           |        | job started.                |
   +-------------+-----------+--------+-----------------------------+
   | end_time    | Yes       | String | Specifies the time when the |
   |             |           |        | job ended.                  |
   +-------------+-----------+--------+-----------------------------+
   | error_code  | Yes       | String | Specifies the error code    |
   |             |           |        | returned after the job      |
   |             |           |        | fails to execute.           |
   +-------------+-----------+--------+-----------------------------+
   | fail_reason | Yes       | String | Indicates the cause of the  |
   |             |           |        | execution failure.          |
   +-------------+-----------+--------+-----------------------------+
   | message     | No        | String | Specifies the message       |
   |             |           |        | returned when an error      |
   |             |           |        | occurs.                     |
   +-------------+-----------+--------+-----------------------------+
   | code        | No        | String | Specifies the error code    |
   |             |           |        | returned when an error      |
   |             |           |        | occurs.                     |
   |             |           |        |                             |
   |             |           |        | For details of error code,  |
   |             |           |        | see `Error                  |
   |             |           |        | Codes <elb_gc               |
   |             |           |        | _0001.html#elb_gc_0001>`__. |
   +-------------+-----------+--------+-----------------------------+
   | sub_jobs    | No        | String | Specifies the execution     |
   |             |           |        | information of a subjob.    |
   |             |           |        | When no subjob exists, the  |
   |             |           |        | value of this parameter is  |
   |             |           |        | left empty. The structure   |
   |             |           |        | of each subjob is similar   |
   |             |           |        | to that of the parent job.  |
   +-------------+-----------+--------+-----------------------------+

-  Example response

   .. code:: json

      {
          "status": "SUCCESS",
          "entities":
           {
            "elb":
             {
              "id": "ef265755daf84333baf4ddc1d91cbc2f",
              "name": "1",
              "type": "External",
              "status": "ACTIVE",
              "bandwidth": 1,
              "vip_address": "10.154.53.4",
              "tenant_id": "cbc08e2f8c354c7aa7abb88d0a7d11dc",
              "admin_state_up": false,
              "vpc_id": "21838be1-c1ce-4c09-9184-228cdb43038d"
              }
            },
           "job_id": "ff8080825ecc523f015ecd0a98f82f77",
           "job_type": "createELB",
           "begin_time": "2017-09-29T09:49:37.399Z",
           "end_time": "2017-09-29T09:50:03.272Z",
           "error_code": null,
           "fail_reason": null
      }

Status Code
^^^^^^^^^^^

-  Normal

   200

-  Error

   +-------------+-------------------------------+----------------------------------------------------------------------+
   | Status Code | Message                       | Description                                                          |
   +=============+===============================+======================================================================+
   | 400         | Bad Request                   | The server failed to process the request.                            |
   +-------------+-------------------------------+----------------------------------------------------------------------+
   | 401         | Unauthorized                  | You must enter a username and the password to access the requested   |
   |             |                               | page.                                                                |
   +-------------+-------------------------------+----------------------------------------------------------------------+
   | 403         | Forbidden                     | You are forbidden to access the requested page.                      |
   +-------------+-------------------------------+----------------------------------------------------------------------+
   | 404         | Not Found                     | The server could not find the requested page.                        |
   +-------------+-------------------------------+----------------------------------------------------------------------+
   | 405         | Method Not Allowed            | You are not allowed to use the method specified in the request.      |
   +-------------+-------------------------------+----------------------------------------------------------------------+
   | 406         | Not Acceptable                | Response generated by the server is not acceptable to the client.    |
   +-------------+-------------------------------+----------------------------------------------------------------------+
   | 407         | Proxy Authentication Required | You must use the proxy server for authentication so that the request |
   |             |                               | can be processed.                                                    |
   +-------------+-------------------------------+----------------------------------------------------------------------+
   | 408         | Request Timeout               | The request timed out.                                               |
   +-------------+-------------------------------+----------------------------------------------------------------------+
   | 409         | Conflict                      | The request could not be processed due to a conflict.                |
   +-------------+-------------------------------+----------------------------------------------------------------------+
   | 500         | Internal Server Error         | Failed to complete the request because of an internal service error. |
   +-------------+-------------------------------+----------------------------------------------------------------------+
   | 501         | Not Implemented               | Failed to complete the request because the server does not support   |
   |             |                               | the requested function.                                              |
   +-------------+-------------------------------+----------------------------------------------------------------------+
   | 502         | Bad Gateway                   | Failed to complete the request because the server has received an    |
   |             |                               | invalid response.                                                    |
   +-------------+-------------------------------+----------------------------------------------------------------------+
   | 503         | Service Unavailable           | Failed to complete the request because the system is out of service  |
   |             |                               | temporarily.                                                         |
   +-------------+-------------------------------+----------------------------------------------------------------------+
   | 504         | Gateway Timeout               | A gateway timeout error occurred.                                    |
   +-------------+-------------------------------+----------------------------------------------------------------------+

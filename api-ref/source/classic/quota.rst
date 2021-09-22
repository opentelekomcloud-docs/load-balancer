Quota
-----

1. .. rubric:: Querying Load Balancer or Listener Quotas
      :name: querying-load-balancer-or-listener-quotas

   #. Function

This API is used to query the load balancer or listener quotas.

2. URI

GET /v1.0/{project_id}/elbaas/quotas

1. Parameter description

+------------+-----------+--------+---------------------------+
| Parameter  | Mandatory | Type   | Description               |
+============+===========+========+===========================+
| project_id | Yes       | String | Specifies the project ID. |
+------------+-----------+--------+---------------------------+

3. Request

-  Request parameters

None

-  Example request

None

#. Response

-  Response parameters

   1. Parameter description

+-----------+--------+--------------------------------+
| Parameter | Type   | Description                    |
+===========+========+================================+
| quotas    | Object | Specifies the resource quotas. |
+-----------+--------+--------------------------------+

2. **quotas** parameter description

+-----------+-------+----------------------------+
| Parameter | Type  | Description                |
+===========+=======+============================+
| resources | Array | Lists the resource quotas. |
+-----------+-------+----------------------------+

3. **resources** parameter description

+-----------+---------+--------------------------------------------+
| Parameter | Type    | Description                                |
+===========+=========+============================================+
| type      | String  | Specifies the resource type. The value can |
|           |         | be **elb** or **listener**.                |
+-----------+---------+--------------------------------------------+
| used      | Integer | Specifies the quantity of used resources.  |
+-----------+---------+--------------------------------------------+
| quota     | Integer | Specifies the total resource quotas.       |
+-----------+---------+--------------------------------------------+
| max       | Integer | Specifies the maximum number of resources. |
+-----------+---------+--------------------------------------------+
| min       | Integer | Specifies the minimum number of resources. |
+-----------+---------+--------------------------------------------+

-  Example response

| {
| "quotas": {
| "resources": [
| {
| "type": "elb",
| "used": 2,
| "quota": 5,
| "max": 100,
| "min": 1
| },
| {
| "type": "listener",
| "quota": 5,
| "max": 200,
| "min": 1
| }
| ]
| }
| }

.. image:: /media/image2.png
   :width: 0.75in
   :height: 0.26042in

The **used** parameter is unavailable for listeners, for which an empty
character string is returned.

#. Status Code

-  Normal

200

-  Error

+-------------+--------------------+--------------------------------+
| Status Code | Message            | Description                    |
+=============+====================+================================+
| 400         | badRequest         | Request error.                 |
+-------------+--------------------+--------------------------------+
| 401         | unauthorized       | Authentication failed.         |
+-------------+--------------------+--------------------------------+
| 403         | userDisabled       | You do not have the permission |
|             |                    | to perform the operation.      |
+-------------+--------------------+--------------------------------+
| 404         | Not Found          | The requested page does not    |
|             |                    | exist.                         |
+-------------+--------------------+--------------------------------+
| 500         | authFault          | System error.                  |
+-------------+--------------------+--------------------------------+
| 503         | serviceUnavailable | The service is unavailable.    |
+-------------+--------------------+--------------------------------+

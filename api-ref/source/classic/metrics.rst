Querying Monitoring Metrics
---------------------------

#. Function

This API is used to query all metrics at Layer 4 and Layer 7.

Only users can query these metrics.

2. URI

GET /v1.0/{project_id}/elbaas/monitor

1. Parameter description

+------------+-----------+------------+------------------------------+
| Parameter  | Mandatory | Type       | Description                  |
+============+===========+============+==============================+
| project_id | Yes       | String     | Specifies the project ID.    |
+------------+-----------+------------+------------------------------+

3. Request

-  Request parameters

None

-  Example request

None

#. Response

-  Response parameters

   1. Response parameters

+-----------------------+-----------------------+-----------------------+
| Parameter             | Type                  | Description           |
+=======================+=======================+=======================+
| act_conn              | Integer               | Specifies the number  |
|                       |                       | of active             |
|                       |                       | connections.          |
+-----------------------+-----------------------+-----------------------+
| cps                   | Integer               | Specifies the number  |
|                       |                       | of concurrent         |
|                       |                       | connections.          |
+-----------------------+-----------------------+-----------------------+
| create_time           | String                | Specifies the report  |
|                       |                       | time.                 |
+-----------------------+-----------------------+-----------------------+
| in_Bps                | Integer               | Specifies the inbound |
|                       |                       | rate (bytes/s).       |
+-----------------------+-----------------------+-----------------------+
| in_pps                | Integer               | Specifies the number  |
|                       |                       | of incoming data      |
|                       |                       | packets.              |
+-----------------------+-----------------------+-----------------------+
| inact_conn            | Integer               | Specifies the number  |
|                       |                       | of inactive           |
|                       |                       | connections.          |
+-----------------------+-----------------------+-----------------------+
| loadbalancer_id       | String                | Specifies the load    |
|                       |                       | balancer ID.          |
+-----------------------+-----------------------+-----------------------+
| loadbalancer_ip       | String                | Specifies the load    |
|                       |                       | balancer IP address.  |
+-----------------------+-----------------------+-----------------------+
| loadbalancer_name     | String                | Specifies the load    |
|                       |                       | balancer name.        |
+-----------------------+-----------------------+-----------------------+
| ncps                  | Integer               | Specifies the number  |
|                       |                       | of new connections.   |
+-----------------------+-----------------------+-----------------------+
| out_Bps               | Integer               | Specifies the         |
|                       |                       | outbound rate         |
|                       |                       | (bytes/s).            |
+-----------------------+-----------------------+-----------------------+
| out_pps               | Integer               | Specifies the number  |
|                       |                       | of outgoing data      |
|                       |                       | packets.              |
+-----------------------+-----------------------+-----------------------+

-  Example response

| [
| {
| "act_conn": 0,
| "cps": 0,
| "create_time": "2016-05-20 16:46:49",
| "in_Bps": 0,
| "in_pps": 0,
| "inact_conn": 0,
| "loadbalancer_id": "34cf6520808d4766ae1455586ab94ba8",
| "loadbalancer_ip": "10.10.1.233",
| "loadbalancer_name": "lb0721",
| "ncps": 0,
| "out_Bps": 0,
| "out_pps": 0
| },
| {
| "act_conn": 0,
| "cps": 0,
| "create_time": "2016-05-20 16:46:49",
| "in_Bps": 0,
| "in_pps": 0,
| "inact_conn": 0,
| "loadbalancer_id": "b44533cce271437bb692365b0c450543",
| "loadbalancer_ip": "10.10.1.253",
| "loadbalancer_name": "lb0721",
| "ncps": 0,
| "out_Bps": 0,
| "out_pps": 0
| }
| ]

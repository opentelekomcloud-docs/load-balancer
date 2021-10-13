Monitoring Metrics
==================

Overview
--------

This section describes the namespace, the metrics that can be monitored by Cloud Eye, and dimensions of these metrics. You can use APIs provided by Cloud Eye to query the metrics of a monitored object and generated alarms.

Namespace
---------

SYS.ELB

Metrics
-------



.. _elb_ug_jk_0001__en-us_topic_0109418599_en-us_topic_0021772779_en-us_topic_0021733202_table42148186162545:

+--------------------------+-------------------+-------------------+-------------------+-------------------+----------------+
| **Metric ID**            | **Name**          | **Description**   | **Value**         | **Monitored       | **Monitoring   |
|                          |                   |                   |                   | Object**          | Period**       |
|                          |                   |                   |                   |                   |                |
|                          |                   |                   |                   |                   | **(Raw Data)** |
+==========================+===================+===================+===================+===================+================+
| m1_cps                   | Concurrent        | Load balancing at | ≥ 0               | Shared load       | 1 minute       |
|                          | Connections       | Layer 4: total    |                   | balancer or its   |                |
|                          |                   | number of TCP and |                   | listener, classic |                |
|                          |                   | UDP connections   |                   | load balancer,    |                |
|                          |                   | from the          |                   | dedicated load    |                |
|                          |                   | monitored object  |                   | balancer or its   |                |
|                          |                   | to backend        |                   | listener          |                |
|                          |                   | servers           |                   |                   |                |
|                          |                   |                   |                   |                   |                |
|                          |                   | Load balancing at |                   |                   |                |
|                          |                   | Layer 7: total    |                   |                   |                |
|                          |                   | number of TCP     |                   |                   |                |
|                          |                   | connections from  |                   |                   |                |
|                          |                   | the clients to    |                   |                   |                |
|                          |                   | the monitored     |                   |                   |                |
|                          |                   | object            |                   |                   |                |
|                          |                   |                   |                   |                   |                |
|                          |                   | Unit: N/A         |                   |                   |                |
+--------------------------+-------------------+-------------------+-------------------+-------------------+----------------+
| m2_act_conn              |                   |                   | Active            | Number of TCP and | ≥ 0            |
|                          |                   |                   | Connections       | UDP connections   |                |
|                          |                   |                   |                   | in the            |                |
|                          |                   |                   |                   | **ESTABLISHED**   |                |
|                          |                   |                   |                   | state between the |                |
|                          |                   |                   |                   | monitored object  |                |
|                          |                   |                   |                   | and backend       |                |
|                          |                   |                   |                   | servers           |                |
|                          |                   |                   |                   |                   |                |
|                          |                   |                   |                   | You can run the   |                |
|                          |                   |                   |                   | following command |                |
|                          |                   |                   |                   | to view the       |                |
|                          |                   |                   |                   | connections (both |                |
|                          |                   |                   |                   | Windows and Linux |                |
|                          |                   |                   |                   | servers):         |                |
|                          |                   |                   |                   |                   |                |
|                          |                   |                   |                   | .. code::         |                |
|                          |                   |                   |                   |                   |                |
|                          |                   |                   |                   |    netstat -an    |                |
|                          |                   |                   |                   |                   |                |
|                          |                   |                   |                   | Unit: N/A         |                |
+--------------------------+-------------------+-------------------+-------------------+-------------------+----------------+
| m3_inact_conn            |                   |                   | Inactive          | Number of TCP     | ≥ 0            |
|                          |                   |                   | Connections       | connections       |                |
|                          |                   |                   |                   | between the       |                |
|                          |                   |                   |                   | monitored object  |                |
|                          |                   |                   |                   | and backend       |                |
|                          |                   |                   |                   | servers except    |                |
|                          |                   |                   |                   | those in the      |                |
|                          |                   |                   |                   | **ESTABLISHED**   |                |
|                          |                   |                   |                   | state             |                |
|                          |                   |                   |                   |                   |                |
|                          |                   |                   |                   | You can run the   |                |
|                          |                   |                   |                   | following command |                |
|                          |                   |                   |                   | to view the       |                |
|                          |                   |                   |                   | connections (both |                |
|                          |                   |                   |                   | Windows and Linux |                |
|                          |                   |                   |                   | servers):         |                |
|                          |                   |                   |                   |                   |                |
|                          |                   |                   |                   | .. code::         |                |
|                          |                   |                   |                   |                   |                |
|                          |                   |                   |                   |    netstat -an    |                |
|                          |                   |                   |                   |                   |                |
|                          |                   |                   |                   | Unit: N/A         |                |
+--------------------------+-------------------+-------------------+-------------------+-------------------+----------------+
| m4_ncps                  |                   |                   | New Connections   | Number of TCP and | ≥ 0/second     |
|                          |                   |                   |                   | UDP connections   |                |
|                          |                   |                   |                   | established       |                |
|                          |                   |                   |                   | between clients   |                |
|                          |                   |                   |                   | and the monitored |                |
|                          |                   |                   |                   | object per second |                |
|                          |                   |                   |                   |                   |                |
|                          |                   |                   |                   | Unit: N/A         |                |
+--------------------------+-------------------+-------------------+-------------------+-------------------+----------------+
| m5_in_pps                |                   |                   | Incoming Packets  | Number of packets | ≥ 0/second     |
|                          |                   |                   |                   | received by the   |                |
|                          |                   |                   |                   | monitored object  |                |
|                          |                   |                   |                   | per second        |                |
|                          |                   |                   |                   |                   |                |
|                          |                   |                   |                   | Unit: Packet/s    |                |
+--------------------------+-------------------+-------------------+-------------------+-------------------+----------------+
| m6_out_pps               |                   |                   | Outgoing Packets  | Number of packets | ≥ 0/second     |
|                          |                   |                   |                   | sent from the     |                |
|                          |                   |                   |                   | monitored object  |                |
|                          |                   |                   |                   | per second        |                |
|                          |                   |                   |                   |                   |                |
|                          |                   |                   |                   | Unit: Packet/s    |                |
+--------------------------+-------------------+-------------------+-------------------+-------------------+----------------+
| m7_in_Bps                |                   |                   | Inbound Rate      | Traffic used for  | ≥ 0 bytes/s    |
|                          |                   |                   |                   | accessing the     |                |
|                          |                   |                   |                   | monitored object  |                |
|                          |                   |                   |                   | from the Internet |                |
|                          |                   |                   |                   |                   |                |
|                          |                   |                   |                   | Unit: byte/s      |                |
+--------------------------+-------------------+-------------------+-------------------+-------------------+----------------+
| m8_out_Bps               |                   |                   | Outbound Rate     | Traffic used by   | ≥ 0 bytes/s    |
|                          |                   |                   |                   | the monitored     |                |
|                          |                   |                   |                   | object to access  |                |
|                          |                   |                   |                   | the Internet      |                |
|                          |                   |                   |                   |                   |                |
|                          |                   |                   |                   | Unit: byte/s      |                |
+--------------------------+-------------------+-------------------+-------------------+-------------------+----------------+
| m9                       | Unhealthy Servers | Number of         | ≥ 0               | Shared load       | 1 minute       |
| _abnormal_servers        |                   | unhealthy backend |                   | balancer, classic |                |
|                          |                   | servers           |                   | load balancer, or |                |
|                          |                   | associated with   |                   | dedicated load    |                |
|                          |                   | the monitored     |                   | balancer          |                |
|                          |                   | object            |                   |                   |                |
|                          |                   |                   |                   |                   |                |
|                          |                   | Unit: N/A         |                   |                   |                |
+--------------------------+-------------------+-------------------+-------------------+-------------------+----------------+
| ma_normal_servers        |                   |                   | Healthy Servers   | Number of healthy | ≥ 0            |
|                          |                   |                   |                   | backend servers   |                |
|                          |                   |                   |                   | associated with   |                |
|                          |                   |                   |                   | the monitored     |                |
|                          |                   |                   |                   | object            |                |
|                          |                   |                   |                   |                   |                |
|                          |                   |                   |                   | Unit: N/A         |                |
+--------------------------+-------------------+-------------------+-------------------+-------------------+----------------+
| **Layer 7                |                   |                   |                   |                   |                |
| (HTTP/HTTPS)             |                   |                   |                   |                   |                |
| metrics: These           |                   |                   |                   |                   |                |
| metrics are              |                   |                   |                   |                   |                |
| available only           |                   |                   |                   |                   |                |
| when the frontend        |                   |                   |                   |                   |                |
| protocol is HTTP         |                   |                   |                   |                   |                |
| or HTTPS.**              |                   |                   |                   |                   |                |
+--------------------------+-------------------+-------------------+-------------------+-------------------+----------------+
| mb_l7_qps                | Layer-7 Query     | Number of         | ≥ 0/second        | Shared load       | 1 minute       |
|                          | Rate              | requests the      |                   | balancer or its   |                |
|                          |                   | monitored object  |                   | listener,         |                |
|                          |                   | receives per      |                   | dedicated load    |                |
|                          |                   | second            |                   | balancer or its   |                |
|                          |                   |                   |                   | listener          |                |
|                          |                   | Unit: Query/s     |                   |                   |                |
+--------------------------+-------------------+-------------------+-------------------+-------------------+----------------+
| mc_l7_http_2xx           |                   |                   | 2xx Status Codes  | Number of 2xx     | ≥ 0/second     |
|                          |                   |                   |                   | status codes      |                |
|                          |                   |                   |                   | returned by the   |                |
|                          |                   |                   |                   | monitored object  |                |
|                          |                   |                   |                   |                   |                |
|                          |                   |                   |                   | Unit: Count/s     |                |
+--------------------------+-------------------+-------------------+-------------------+-------------------+----------------+
| md_l7_http_3xx           |                   |                   | 3xx Status Codes  | Number of 3xx     | ≥ 0/second     |
|                          |                   |                   |                   | status codes      |                |
|                          |                   |                   |                   | returned by the   |                |
|                          |                   |                   |                   | monitored object  |                |
|                          |                   |                   |                   |                   |                |
|                          |                   |                   |                   | Unit: Count/s     |                |
+--------------------------+-------------------+-------------------+-------------------+-------------------+----------------+
| me_l7_http_4xx           |                   |                   | 4xx Status Codes  | Number of 4xx     | ≥ 0/second     |
|                          |                   |                   |                   | status codes      |                |
|                          |                   |                   |                   | returned by the   |                |
|                          |                   |                   |                   | monitored object  |                |
|                          |                   |                   |                   |                   |                |
|                          |                   |                   |                   | Unit: Count/s     |                |
+--------------------------+-------------------+-------------------+-------------------+-------------------+----------------+
| mf_l7_http_5xx           |                   |                   | 5xx Status Codes  | Number of 5xx     | ≥ 0/second     |
|                          |                   |                   |                   | status codes      |                |
|                          |                   |                   |                   | returned by the   |                |
|                          |                   |                   |                   | monitored object  |                |
|                          |                   |                   |                   |                   |                |
|                          |                   |                   |                   | Unit: Count/s     |                |
+--------------------------+-------------------+-------------------+-------------------+-------------------+----------------+
| m10_l7_http_other_status |                   |                   | Other Status      | Number of status  | ≥ 0/second     |
|                          |                   |                   | Codes             | codes returned by |                |
|                          |                   |                   |                   | the monitored     |                |
|                          |                   |                   |                   | object except     |                |
|                          |                   |                   |                   | 2xx, 3xx, 4xx,    |                |
|                          |                   |                   |                   | and 5xx status    |                |
|                          |                   |                   |                   | codes             |                |
|                          |                   |                   |                   |                   |                |
|                          |                   |                   |                   | Unit: Count/s     |                |
+--------------------------+-------------------+-------------------+-------------------+-------------------+----------------+
| m11_l7_http_404          |                   |                   | 404 Not Found     | Number of 404 Not | ≥ 0/second     |
|                          |                   |                   |                   | Found status      |                |
|                          |                   |                   |                   | codes returned by |                |
|                          |                   |                   |                   | the monitored     |                |
|                          |                   |                   |                   | object            |                |
|                          |                   |                   |                   |                   |                |
|                          |                   |                   |                   | Unit: Count/s     |                |
+--------------------------+-------------------+-------------------+-------------------+-------------------+----------------+
| m12_l7_http_499          |                   |                   | 499 Client Closed | Number of 499     | ≥ 0/second     |
|                          |                   |                   | Request           | Client Closed     |                |
|                          |                   |                   |                   | Request status    |                |
|                          |                   |                   |                   | codes returned by |                |
|                          |                   |                   |                   | the monitored     |                |
|                          |                   |                   |                   | object            |                |
|                          |                   |                   |                   |                   |                |
|                          |                   |                   |                   | Unit: Count/s     |                |
+--------------------------+-------------------+-------------------+-------------------+-------------------+----------------+
| m13_l7_http_502          |                   |                   | 502 Bad Gateway   | Number of 502 Bad | ≥ 0/second     |
|                          |                   |                   |                   | Gateway status    |                |
|                          |                   |                   |                   | codes returned by |                |
|                          |                   |                   |                   | the monitored     |                |
|                          |                   |                   |                   | object            |                |
|                          |                   |                   |                   |                   |                |
|                          |                   |                   |                   | Unit: Count/s     |                |
+--------------------------+-------------------+-------------------+-------------------+-------------------+----------------+
| m14_l7_rt                |                   |                   | Average Layer-7   | Average response  | ≥ 0 ms         |
|                          |                   |                   | Response Time     | time of the       |                |
|                          |                   |                   |                   | monitored object  |                |
|                          |                   |                   |                   |                   |                |
|                          |                   |                   |                   | The response time |                |
|                          |                   |                   |                   | starts when the   |                |
|                          |                   |                   |                   | monitored object  |                |
|                          |                   |                   |                   | receives requests |                |
|                          |                   |                   |                   | from the clients  |                |
|                          |                   |                   |                   | and ends when it  |                |
|                          |                   |                   |                   | returns all       |                |
|                          |                   |                   |                   | responses to the  |                |
|                          |                   |                   |                   | clients.          |                |
|                          |                   |                   |                   |                   |                |
|                          |                   |                   |                   | Unit: ms          |                |
+--------------------------+-------------------+-------------------+-------------------+-------------------+----------------+
| m15_l7_upstream_4xx      | 4xx Status        | Number of 4xx     | ≥ 0/second        | Shared load       | 1 minute       |
|                          | Codes_Backend     | status codes      |                   | balancer or its   |                |
|                          |                   | returned by the   |                   | listener,         |                |
|                          |                   | monitored object  |                   | dedicated load    |                |
|                          |                   |                   |                   | balancer or its   |                |
|                          |                   | Unit: Count/s     |                   | listener          |                |
+--------------------------+-------------------+-------------------+-------------------+-------------------+----------------+
| m16_l7_upstream_5xx      |                   |                   | 5xx Status        | Number of 5xx     | ≥ 0/second     |
|                          |                   |                   | Codes_Backend     | status codes      |                |
|                          |                   |                   |                   | returned by the   |                |
|                          |                   |                   |                   | monitored object  |                |
|                          |                   |                   |                   |                   |                |
|                          |                   |                   |                   | Unit: Count/s     |                |
+--------------------------+-------------------+-------------------+-------------------+-------------------+----------------+
| m17_l7_upstream_rt       |                   |                   | Average Server    | Average response  | ≥ 0 ms         |
|                          |                   |                   | Response Time     | time of backend   |                |
|                          |                   |                   |                   | servers           |                |
|                          |                   |                   |                   |                   |                |
|                          |                   |                   |                   | The response time |                |
|                          |                   |                   |                   | starts when the   |                |
|                          |                   |                   |                   | monitored object  |                |
|                          |                   |                   |                   | routes the        |                |
|                          |                   |                   |                   | requests to the   |                |
|                          |                   |                   |                   | backend server    |                |
|                          |                   |                   |                   | and ends when the |                |
|                          |                   |                   |                   | monitored object  |                |
|                          |                   |                   |                   | receives a        |                |
|                          |                   |                   |                   | response from the |                |
|                          |                   |                   |                   | backend server.   |                |
|                          |                   |                   |                   |                   |                |
|                          |                   |                   |                   | Unit: ms          |                |
+--------------------------+-------------------+-------------------+-------------------+-------------------+----------------+

**a**: If a service is being monitored from multiple dimensions, include all dimensions when you use APIs to query the metrics.

-  Example of querying a single metric from both dimensions: dim.0=lbaas_instance_id,223e9eed-2b02-4ed2-a126-7e806a6fee1f&dim.1=lbaas_listener_id,3baa7335-8886-4867-8481-7cbba967a917

-  Example of querying metrics in batches from both dimensions:

   .. code::

      "dimensions": [
      {
      "name": "lbaas_instance_id",
      "value": "223e9eed-2b02-4ed2-a126-7e806a6fee1f"
      }
      {
      "name": "lbaas_listener_id",
      "value": "3baa7335-8886-4867-8481-7cbba967a917"
      }
      ],

Dimensions
----------



.. _elb_ug_jk_0001__en-us_topic_0109418599_en-us_topic_0021772779_en-us_topic_0021733202_table24384314162910:

================= ======================================================
Key               Value
================= ======================================================
lb_instance_id    Specifies the ID of the classic load balancer.
lbaas_instance_id Specifies the ID of the shared load balancer.
lbaas_listener_id Specifies the ID of the shared load balancer listener.
lbaas_pool_id     Specifies the backend server group ID.
================= ======================================================

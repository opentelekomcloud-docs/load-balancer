:original_name: elb_fl_0002.html

.. _elb_fl_0002:

ELB Metrics
===========

Introduction
------------

This section describes the metrics that can be monitored by Cloud Eye as well as their namespaces and dimensions. You can use APIs provided by Cloud Eye to query the metrics of a monitored object and the generated alarms.

Namespace
---------

SYS.ELB

Metrics
-------

+---------------------+------------------------+-------------------------------------------------------------------------------------+-------------+------------------------------------------------------------------------------------------------------+
| Metric              | Metric Name            | Description                                                                         | Value Range | Remarks                                                                                              |
+=====================+========================+=====================================================================================+=============+======================================================================================================+
| m1_cps              | Concurrent Connections | Total number of concurrent connections processed by the monitored object per second | >= 0        | Monitored object: an elastic load balancer, elastic load balancer listener, or classic load balancer |
|                     |                        |                                                                                     |             |                                                                                                      |
|                     |                        | Unit: count                                                                         |             |                                                                                                      |
+---------------------+------------------------+-------------------------------------------------------------------------------------+-------------+------------------------------------------------------------------------------------------------------+
| m2_act_conn         | Active Connections     | Total number of active connections processed by the monitored object per second     | >= 0        | Monitored object: an elastic load balancer, elastic load balancer listener, or classic load balancer |
|                     |                        |                                                                                     |             |                                                                                                      |
|                     |                        | Unit: count                                                                         |             |                                                                                                      |
+---------------------+------------------------+-------------------------------------------------------------------------------------+-------------+------------------------------------------------------------------------------------------------------+
| m3_inact_conn       | Inactive Connections   | Total number of inactive connections processed by the monitored object per second   | >= 0        | Monitored object: an elastic load balancer, elastic load balancer listener, or classic load balancer |
|                     |                        |                                                                                     |             |                                                                                                      |
|                     |                        | Unit: count                                                                         |             |                                                                                                      |
+---------------------+------------------------+-------------------------------------------------------------------------------------+-------------+------------------------------------------------------------------------------------------------------+
| m4_ncps             | New Connections        | Total number of new connections processed by the monitored object per second        | >= 0        | Monitored object: an elastic load balancer, elastic load balancer listener, or classic load balancer |
|                     |                        |                                                                                     |             |                                                                                                      |
|                     |                        | Unit: count                                                                         |             |                                                                                                      |
+---------------------+------------------------+-------------------------------------------------------------------------------------+-------------+------------------------------------------------------------------------------------------------------+
| m5_in_pps           | Incoming Packets       | Incoming packets received by the monitored object per second                        | >= 0        | Monitored object: an elastic load balancer, elastic load balancer listener, or classic load balancer |
|                     |                        |                                                                                     |             |                                                                                                      |
|                     |                        | Unit: count                                                                         |             |                                                                                                      |
+---------------------+------------------------+-------------------------------------------------------------------------------------+-------------+------------------------------------------------------------------------------------------------------+
| m6_out_pps          | Outgoing Packets       | Outgoing packets sent from the monitored object per second                          | >= 0        | Monitored object: an elastic load balancer, elastic load balancer listener, or classic load balancer |
|                     |                        |                                                                                     |             |                                                                                                      |
|                     |                        | Unit: count                                                                         |             |                                                                                                      |
+---------------------+------------------------+-------------------------------------------------------------------------------------+-------------+------------------------------------------------------------------------------------------------------+
| m7_in_Bps           | Inbound Rate           | Incoming bytes received by the monitored object per second                          | >= 0        | Monitored object: an elastic load balancer, elastic load balancer listener, or classic load balancer |
|                     |                        |                                                                                     |             |                                                                                                      |
|                     |                        | Unit: Byte/s                                                                        |             |                                                                                                      |
+---------------------+------------------------+-------------------------------------------------------------------------------------+-------------+------------------------------------------------------------------------------------------------------+
| m8_out_Bps          | Outbound Rate          | Outgoing bytes sent from the monitored object per second                            | >= 0        | Monitored object: an elastic load balancer, elastic load balancer listener, or classic load balancer |
|                     |                        |                                                                                     |             |                                                                                                      |
|                     |                        | Unit: Byte/s                                                                        |             |                                                                                                      |
+---------------------+------------------------+-------------------------------------------------------------------------------------+-------------+------------------------------------------------------------------------------------------------------+
| m9_abnormal_servers | Unhealthy Servers      | Number of backend servers considered unhealthy                                      | >= 0        | Monitored object: an elastic load balancer or classic load balancer                                  |
|                     |                        |                                                                                     |             |                                                                                                      |
|                     |                        | Unit: count                                                                         |             |                                                                                                      |
+---------------------+------------------------+-------------------------------------------------------------------------------------+-------------+------------------------------------------------------------------------------------------------------+
| ma_normal_servers   | Healthy Servers        | Number of backend servers considered healthy                                        | >= 0        | Monitored object: an elastic load balancer or classic load balancer                                  |
|                     |                        |                                                                                     |             |                                                                                                      |
|                     |                        | Unit: count                                                                         |             |                                                                                                      |
+---------------------+------------------------+-------------------------------------------------------------------------------------+-------------+------------------------------------------------------------------------------------------------------+

Dimensions
----------

================= =======================================
Key               Value
================= =======================================
lb_instance_id    ID of a classic load balancer
lbaas_instance_id ID of an elastic load balancer
lbaas_listener_id ID of an elastic load balancer listener
================= =======================================

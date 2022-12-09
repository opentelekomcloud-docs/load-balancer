:original_name: elb_ug_jk_0005.html

.. _elb_ug_jk_0005:

Viewing Metrics
===============

Scenarios
---------

Cloud Eye allows you to monitor your resources, including load balancers. You can view metrics on either the ELB console or the Cloud Eye console

The transmission of monitoring data takes a while, so the status of each load balancer displayed on the Cloud Eye dashboard is not its real-time status. For a newly created load balancer or a newly added listener, you need to wait for about 5 minutes to 10 minutes before you can view its metrics.

Prerequisites
-------------

-  The load balancer is running properly.

   If backend servers are stopped, faulty, or deleted, no monitoring data is displayed.

   .. note::

      Cloud Eye stops monitoring a load balancer and removes it from the monitored object list if its backend servers have been deleted or are in stopped or faulty state for over 24 hours. However, the configured alarm rules will not be automatically deleted.

-  You have interconnected ELB with Cloud Eye and configured an alarm rule for the load balancer on the Cloud Eye console.

   Without alarm rules, there is no monitoring data. For details, see :ref:`Setting an Alarm Rule <elb_ug_jk_0002>`.

-  If an IAM user wants to view the ELB monitoring data on the Cloud Eye console, the IAM user must be granted the **ELB Administrator** permission. Otherwise, the IAM user cannot view all monitoring data.

Viewing Monitoring Metrics on the Cloud Eye Console
---------------------------------------------------

#. Log in to the management console.
#. Under **Management & Deployment**, click **Cloud Eye**.
#. In the navigation pane on the left, choose **Cloud Service Monitoring** > **Elastic Load Balancing**.
#. On the **Cloud Service Monitoring** page, click the name of the load balancer. Alternatively, locate the load balancer and click **View Metric** in the **Operation** column.
#. Select the time period during which you want to view metrics. You can select a system-defined time period (for example, last 1 hour) or specify a time period.
#. Click **Select Metric** in the upper right corner and select the metrics to be viewed.

.. note::

   For more details, see the Cloud Eye User Guide.

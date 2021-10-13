Viewing Metrics
===============

Scenarios
---------

Cloud Eye allows you to monitor your resources, including load balancers.

The transmission of monitoring data takes a while, so the status of each load balancer displayed on the Cloud Eye dashboard is not its real-time status. For a newly created load balancer or a newly added listener, you need to wait for about 5 minutes to 10 minutes before you can view its metrics.

Prerequisites
-------------

-  The load balancer is running properly.

   If backend servers are stopped, faulty, or deleted, no monitoring data is displayed.

   |image1|

   Cloud Eye stops monitoring a load balancer and removes it from the monitored object list if its backend servers have been deleted or are in stopped or faulty state for over 24 hours. However, the configured alarm rules will not be automatically deleted.

-  You have interconnected ELB with Cloud Eye and configured an alarm rule for the load balancer on the Cloud Eye console.

   Without alarm rules configured, there is no monitoring data. For details, see `Setting an Alarm Rule <elb_ug_jk_0002.html>`__.

-  If an IAM user wants to view the ELB monitoring data on the Cloud Eye console, the IAM user must be granted the E\ **LB Administrator** permission. Otherwise, the IAM user cannot view all monitoring data.

Background
----------

If you set the weight of a backend server to 0, the load balancer will not route traffic to this server even if it is included in **Healthy Servers** on the Cloud Eye console.

Procedure
---------

#. Log in to the management console.
#. Under **Management & Deployment**, click **Cloud Eye**.
#. In the navigation pane on the left, choose **Cloud Service Monitoring** > **Elastic Load Balancing**.
#. Locate the load balancer and click **View Metric** in the **Operation** column.

.. |image1| image:: /images/note_3.0-en-us.png

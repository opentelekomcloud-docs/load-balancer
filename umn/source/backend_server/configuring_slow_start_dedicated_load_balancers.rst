:original_name: elb_ug_hd_0006.html

.. _elb_ug_hd_0006:

Configuring Slow Start (Dedicated Load Balancers)
=================================================

Scenarios
---------

You can enable slow start for HTTP or HTTPS listeners. After you enable it, the load balancer linearly increases the proportion of requests to send to backend servers in this mode. When the slow start duration elapses, the load balancer sends full share of requests to backend servers and exits the slow start mode. Slow start gives applications time to warm up and respond to requests with optimal performance. When the health check function is enabled, slow start takes effect after backend servers are detected healthy. If the health check is not working normally during the slow start, the slow start duration will not stop.

The slow start duration ranges from 30 to 1,200, in seconds. The default value is 30.

Backend servers will exit slow start in either of the following cases:

-  The slow start duration elapses.
-  Backend servers become unhealthy during the slow start duration.

If an unhealthy backend server exits slow start, it will enter slow start again once it is detected healthy.

Prerequisites
-------------

-  You have created a dedicated load balancer.
-  You have added an HTTP or HTTPS listener to the dedicated load balancer.

Procedure
---------

#. Log in to the management console.
#. In the upper left corner of the page, click |image1| and select the desired region and project.
#. Hover on |image2| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.
#. On the **Load Balancers** page, locate the dedicated load balancer that you have created and click its name.
#. On the **Backend Server Groups** tab page, click **Add Backend Server Group**.
#. Enable **Slow Start** and set the slow start duration. Set other parameters based on service requirements.
#. Click **OK**.

Follow-Up Operations
--------------------

-  For a created backend server group, on the **Add Backend Server Group** tab page, click |image3| to enable slow start.
-  Add backend servers to the newly added backend server group by performing the operations in :ref:`Adding or Removing Backend Servers (Dedicated Load Balancers) <elb_ug_hd_0003>`.

.. |image1| image:: /_static/images/en-us_image_0000001211126503.png
.. |image2| image:: /_static/images/en-us_image_0000001417088430.png
.. |image3| image:: /_static/images/en-us_image_0291965517.png

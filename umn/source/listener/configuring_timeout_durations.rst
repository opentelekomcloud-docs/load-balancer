:original_name: elb_ug_jt_0014.html

.. _elb_ug_jt_0014:

Configuring Timeout Durations
=============================

Scenarios
---------

You can configure timeout durations (idle timeout, request timeout, and response timeout) for your listeners to meet varied demands. For example, if the size of a request from an HTTP or HTTPS client is large, you can increase the request timeout duration to ensure that the request can be successfully routed.

For shared load balancers, you can only change the timeout durations of TCP, HTTP, and HTTPS listeners, but cannot change the timeout durations of UDP listeners.

For dedicated load balancers, you can change the timeout durations of TCP, UDP, HTTP, and HTTPS listeners.

Procedure
---------

#. Log in to the management console.
#. In the upper left corner of the page, click |image1| and select the desired region and project.
#. Hover on |image2| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.
#. Locate the load balancer and click its name.
#. On the **Listeners** tab page, locate the listener, click |image3| next to the listener name, and select **Modify Listener**.
#. In the **Modify Listener** dialog box, expand **Advanced Settings**.
#. Configure **Idle Timeout (s)**, **Request Timeout (s)**, or **Response Timeout (s)** and click **Next**.
#. Click **Finish**.

.. |image1| image:: /_static/images/en-us_image_0000001211126503.png
.. |image2| image:: /_static/images/en-us_image_0000001417088430.png
.. |image3| image:: /_static/images/en-us_image_0000001504255021.png

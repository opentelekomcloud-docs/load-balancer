:original_name: elb_ug_jt_0014.html

.. _elb_ug_jt_0014:

Configuring or Modifying Timeout Durations
==========================================

Scenarios
---------

You can configure and modify timeout durations (idle timeout, request timeout, and response timeout) for your listeners to meet varied demands. For example, if the size of a request from an HTTP or HTTPS client is large, you can increase the request timeout duration to ensure that the request can be successfully routed.

For shared load balancers, you can only change the timeout durations of TCP, HTTP, and HTTPS listeners, but cannot change the timeout durations of UDP listeners.

For dedicated load balancers, you can change the timeout durations of TCP, UDP, HTTP, and HTTPS listeners.

Configuring Timeout Durations
-----------------------------

#. Log in to the management console.
#. In the upper left corner of the page, click |image1| and select the desired region and project.
#. Hover on |image2| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.
#. On the **Load Balancers** page, locate the load balancer that you want to add a listener to and click its name.
#. Under **Listeners**, click **Add Listener**.
#. In the **Configure Listener** step, specify the timeout durations based on service requirements. Check the modifications and Click **Next: Configure Request Routing Policy**.

7. Complete other configurations as required.
8. Confirm the configuration and click **Submit**.

Modifying Timeout Durations
---------------------------

#. Log in to the management console.
#. In the upper left corner of the page, click |image3| and select the desired region and project.
#. Hover on |image4| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.
#. Locate the load balancer and click its name.
#. On the **Listeners** tab page, locate the listener, click |image5| next to the listener name, and select **Modify Listener**.
#. In the **Modify Listener** dialog box, expand **Advanced Settings**.
#. Modify **Idle Timeout (s)**, **Request Timeout (s)**, or **Response Timeout (s)** and click **Next**.
#. Click **Finish**.
#. Click **OK**.

Follow-Up Operations
--------------------

After you add a listener, associate backend servers with it by performing the operations in :ref:`Adding or Removing Backend Servers (Shared Load Balancers) <en-us_topic_0052569729>`.

.. |image1| image:: /_static/images/en-us_image_0000001211126503.png
.. |image2| image:: /_static/images/en-us_image_0000001417088430.png
.. |image3| image:: /_static/images/en-us_image_0000001211126503.png
.. |image4| image:: /_static/images/en-us_image_0000001417088430.png
.. |image5| image:: /_static/images/en-us_image_0000001504255021.png

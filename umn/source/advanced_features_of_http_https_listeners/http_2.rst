:original_name: en-us_topic_0150301849.html

.. _en-us_topic_0150301849:

HTTP/2
======

Scenarios
---------

Hypertext Transfer Protocol 2.0 (HTTP/2) is the next-generation HTTP protocol. HTTP/2 is used to secure connections between the load balancer and clients. You can enable HTTP/2 when you add HTTPS listeners. If you have already added an HTTPS listener, you can also enable this function.

Constraints
-----------

You can enable HTTP/2 only for HTTPS listeners.

Enabling HTTP/2 When Adding a Listener
--------------------------------------

#. Log in to the management console.
#. In the upper left corner of the page, click |image1| and select the desired region and project.
#. Hover on |image2| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.
#. Locate the load balancer and click its name.
#. Under **Listeners**, click **Add Listener**.
#. In the **Add Listener** dialog box, set **Frontend Protocol** to **HTTPS**.
#. Expand **Advanced Settings** and enable HTTP/2.
#. Walk through the steps, set relevant parameters and in the end click **Submit**.

Enabling or Disabling HTTP/2 When Modifying a Listener
------------------------------------------------------

#. Log in to the management console.
#. In the upper left corner of the page, click |image3| and select the desired region and project.
#. Hover on |image4| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.
#. Locate the load balancer and click its name.
#. Click **Listeners**, locate the listener, click |image5| next to the listener name, and select **Modify Listener**.
#. In the **Modify Listener** dialog box, expand **Advanced Settings** and enable or disable HTTP/2.
#. Confirm the parameters, and click **Next**.
#. Click **Finish**.
#. Click **OK**.

.. |image1| image:: /_static/images/en-us_image_0000001747739624.png
.. |image2| image:: /_static/images/en-us_image_0000001794660485.png
.. |image3| image:: /_static/images/en-us_image_0000001747739624.png
.. |image4| image:: /_static/images/en-us_image_0000001794660485.png
.. |image5| image:: /_static/images/en-us_image_0000001794819893.png

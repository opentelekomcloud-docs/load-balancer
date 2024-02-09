:original_name: elb_ug_hc_0003.html

.. _elb_ug_hc_0003:

Disabling a Health Check
========================

Scenarios
---------

If you do not require health check, you can disable it when you add listeners. If you have already added listeners with health check enabled, you can also disable it when you modify the listeners.

After health check is disabled, the load balancer will consider all backend servers healthy and will still route requests to backend servers even if they are not working normally. As a result, applications on these servers are inaccessible. If this happens, ensure that the ports used by the backend servers are normal. Do not disable health check unless necessary.

Procedure
---------

#. Log in to the management console.
#. In the upper left corner of the page, click |image1| and select the desired region and project.
#. Hover on |image2| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.
#. Locate the load balancer and click its name.

5. Click **Backend Server Groups**, locate the backend server group, and click its name.
6. In the **Basic Information** area, click **Configure** next to **Health Check**.

7. In the **Configure Health Check** dialog box, disable the health check.

8. Click **OK**.

.. |image1| image:: /_static/images/en-us_image_0000001747739624.png
.. |image2| image:: /_static/images/en-us_image_0000001794660485.png

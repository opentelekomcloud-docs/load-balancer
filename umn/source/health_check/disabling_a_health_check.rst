Disabling a Health Check
========================

Scenarios
---------

If you do not require health check, you can disable it when you add listeners. If you have already added listeners with health check enabled, you can also disable it when you modify the listeners.

After health check is disabled, the load balancer will consider all backend servers healthy and will still route requests to a backend server even if this server becomes faulty or is working abnormally. As a result, applications on this server are inaccessible. If this happens, ensure that the ports used by the backend servers are normal. You are advised not to disable health checks unless necessary.

Procedure
---------

#. Log in to the management console.
#. In the upper left corner of the page, click |image1| and select the desired region and project.
#. Hover on |image2| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.
#. Locate the load balancer and click its name.

5. Click **Backend Server Groups**, locate the backend server group, and click its name.
6. Click **More** in the **Operation** column.
7. Select **Configure Health Check** from the drop-down list.

8. In the **Configure Health Check** dialog box, disable the health check.

9. Click **OK**.

.. |image1| image:: /images/en-us_image_0241356603.png

.. |image2| image:: /images/en-us_image_0000001120894978.png


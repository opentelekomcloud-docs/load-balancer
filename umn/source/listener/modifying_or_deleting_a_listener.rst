:original_name: elb_ug_jt_0012.html

.. _elb_ug_jt_0012:

Modifying or Deleting a Listener
================================

Scenarios
---------

You can modify a listener as needed or delete a listener if you no longer need it.

Deleted listeners cannot be recovered.

.. note::

   **Frontend Protocol/Port** and **Backend Protocol** cannot be modified after you have configured them. If you want to modify the protocol or port of the listener, add another listener to the load balancer.

Modifying a listener
--------------------

#. Log in to the management console.
#. In the upper left corner of the page, click |image1| and select the desired region and project.
#. Click |image2| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.
#. Locate the load balancer and click its name.
#. Modify the listener in either of the following ways:

   -  On the **Listeners** page, locate the listener, and click **Edit** in the **Operation** column.
   -  Click the name of the target listener. On the **Basic Information** page, click **Edit** on the top right corner.

#. On the **Edit** dialog box, modify parameters, and click **OK**.

.. _elb_ug_jt_0012__section630190201235:

Deleting a Listener
-------------------

#. Log in to the management console.
#. In the upper left corner of the page, click |image3| and select the desired region and project.
#. Click |image4| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.
#. Locate the load balancer and click its name.

   .. note::

      -  If the listener has backend servers associated, disassociate the backend servers before deleting the listener.
      -  If HTTP requests are redirected to an HTTPS listener, delete the redirect before deleting the HTTPS listener.
      -  If the listener has a forwarding policy, delete the forwarding policy before deleting the listener.
      -  After a listener is deleted, the associated backend server group is also deleted.

#. Click **Listeners**, locate the listener, and click **Delete** in the **Operation** column.
#. In the displayed dialog box, enter **DELETE**.
#. Click **OK**.

.. |image1| image:: /_static/images/en-us_image_0000001747739624.png
.. |image2| image:: /_static/images/en-us_image_0000001794660485.png
.. |image3| image:: /_static/images/en-us_image_0000001747739624.png
.. |image4| image:: /_static/images/en-us_image_0000001794660485.png

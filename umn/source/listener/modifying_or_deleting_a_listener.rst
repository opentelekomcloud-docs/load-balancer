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

Modifying a Listener
--------------------

#. Log in to the management console.
#. In the upper left corner of the page, click |image1| and select the desired region and project.
#. Hover on |image2| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.
#. Locate the load balancer and click its name.
#. Click **Listeners**.

   -  Shared load balancers: Locate the listener and click |image3| on the right of its name. In the **Modify Listener** dialog box, modify the parameters as needed.
   -  Dedicated load balancers: Locate the listener and click |image4| on the right of its name. In the **Modify Listener** dialog box, modify the parameters as needed.

#. Click **OK**.

Deleting a Listener
-------------------

#. Log in to the management console.
#. In the upper left corner of the page, click |image5| and select the desired region and project.
#. Hover on |image6| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.
#. Locate the load balancer and click its name.

   .. note::

      -  If the listener has backend servers associated, disassociate the backend servers before deleting the listener.
      -  If HTTP requests are redirected to an HTTPS listener, delete the redirect before deleting the HTTPS listener.
      -  If the listener has a forwarding policy, delete the forwarding policy before deleting the listener.
      -  After a listener is deleted, the associated backend server group is also deleted.

#. Click **Listeners**.

   -  Shared or dedicated load balancers: Locate the listener and click |image7| on the right of its name.

#. Click **Yes**.

.. |image1| image:: /_static/images/en-us_image_0000001211126503.png
.. |image2| image:: /_static/images/en-us_image_0000001120894978.png
.. |image3| image:: /_static/images/en-us_image_0238446387.png
.. |image4| image:: /_static/images/en-us_image_0000001202965532.png
.. |image5| image:: /_static/images/en-us_image_0000001211126503.png
.. |image6| image:: /_static/images/en-us_image_0000001120894978.png
.. |image7| image:: /_static/images/en-us_image_0000001163728097.png

:original_name: elb_ug_fz_0008.html

.. _elb_ug_fz_0008:

Deleting a Load Balancer
========================

Scenarios
---------

You can delete a load balancer if you do not need it any longer.

.. caution::

   A deleted load balancer cannot be recovered.

After a public network load balancer is deleted, its EIP will not be released and can be used by other resources.

Prerequisites
-------------

Delete the resources configured for the load balancer in the following sequence:

#. Delete all the forwarding policies added to HTTP and HTTPS listeners of the load balancer.
#. Delete the redirect created for each HTTP listener of the load balancer.
#. Remove all the backend servers from the backend server groups associated with each listener of the load balancer.
#. Delete all the listeners added to the load balancer.
#. Delete all backend server groups associated with each listener of the load balancer.


Deleting a Load Balancer
------------------------

#. Log in to the management console.
#. In the upper left corner of the page, click |image1| and select the desired region and project.
#. Hover on |image2| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.
#. Locate the load balancer and click **Delete** in the **Operation** column.
#. Click **Yes**.

.. |image1| image:: /_static/images/en-us_image_0000001211126503.png
.. |image2| image:: /_static/images/en-us_image_0000001120894978.png

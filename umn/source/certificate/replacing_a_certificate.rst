:original_name: elb_ug_zs_0005.html

.. _elb_ug_zs_0005:

Replacing a Certificate
=======================

Scenarios
---------

You need to bind a certificate when you add an HTTPS listener to a load balancer. If the certificate used by the load balancer has expired or needs to be replaced due to other reasons, you can replace the certificate.

If the certificate is also used by other services such as WAF, replace the certificate on all these services to prevent service unavailability.

.. note::

   Replacing certificates and private keys does not affect your applications.

Prerequisites
-------------

You have created a certificate by following the instructions in :ref:`Creating a Certificate <en-us_elb_03_0005__section26868475171830>`.

Binding a Certificate
---------------------

You can bind certificates when you add an HTTPS listener. For details, see :ref:`Adding a Listener <elb_ug_jt_0011>`.


Replacing a Certificate
-----------------------

#. Log in to the management console.
#. In the upper left corner of the page, click |image1| and select the desired region and project.
#. Hover on |image2| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.
#. Locate the load balancer and click its name.
#. Click **Listeners**.

   -  Shared load balancers: Locate the listener and click |image3| on the right of its name. In the **Modify Listener** dialog box, select the certificate.
   -  Dedicated load balancers: Locate the listener, click |image4| on the right of its name, and click **Modify Listener**. In the **Modify Listener** dialog box, select the certificate.

#. Select a server certificate and click **Next**.
#. In the **Configure Backend Server Group** dialog box, click **Finish**.

.. |image1| image:: /_static/images/en-us_image_0000001211126503.png
.. |image2| image:: /_static/images/en-us_image_0000001120894978.png
.. |image3| image:: /_static/images/en-us_image_0000001179564316.png
.. |image4| image:: /_static/images/en-us_image_0000001246898749.png

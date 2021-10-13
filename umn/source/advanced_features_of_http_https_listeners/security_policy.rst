Security Policy
===============

Scenarios
---------

When you add HTTPS listeners, you can select desired security policies to improve service security. A security policy is a combination of TLS protocols and cipher suites.

Adding a Security Policy
------------------------

#. Log in to the management console.
#. In the upper left corner of the page, click |image1| and select the desired region and project.
#. Hover on |image2| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.
#. Locate the load balancer and click its name.
#. Under **Listeners**, click **Add Listener**.
#. In the **Add Listener** dialog, expand **Advanced Settings**, and select a security policy. `Table 1 <#elb_ug_jt_0022__table1247813103533>`__ lists the parameters to be configured.
   

.. _elb_ug_jt_0022__table1247813103533:

   .. table:: **Table 1** Security policy parameters

      +-----------------------------+-----------------------------+-----------------------------+-----------------------------+
      | **Parameter**               | **Description**             | **TLS Version**             | **Cipher Suite**            |
      +=============================+=============================+=============================+=============================+
      | TLS-1-0                     | TLS 1.0, TLS 1.1, and TLS   | TLS 1.2                     | ECDHE-RSA-A                 |
      |                             | 1.2 and supported cipher    |                             | ES256-GCM-SHA384:ECDHE-RSA- |
      |                             | suites (high compatibility  | TLS 1.1                     | AES128-GCM-SHA256:ECDHE-ECD |
      |                             | and moderate security)      |                             | SA-AES256-GCM-SHA384:ECDHE- |
      |                             |                             | TLS 1.0                     | ECDSA-AES128-GCM-SHA256:AES |
      |                             |                             |                             | 128-GCM-SHA256:AES256-GCM-S |
      |                             |                             |                             | HA384:ECDHE-ECDSA-AES128-SH |
      |                             |                             |                             | A256:ECDHE-RSA-AES128-SHA25 |
      |                             |                             |                             | 6:AES128-SHA256:AES256-SHA2 |
      |                             |                             |                             | 56:ECDHE-ECDSA-AES256-SHA38 |
      |                             |                             |                             | 4:ECDHE-RSA-AES256-SHA384:E |
      |                             |                             |                             | CDHE-ECDSA-AES128-SHA:ECDHE |
      |                             |                             |                             | -RSA-AES128-SHA:ECDHE-RSA-A |
      |                             |                             |                             | ES256-SHA:ECDHE-ECDSA-AES25 |
      |                             |                             |                             | 6-SHA:AES128-SHA:AES256-SHA |
      +-----------------------------+-----------------------------+-----------------------------+-----------------------------+
      | TLS-1-1                     |                             | TLS 1.1 and TLS 1.2 and     | TLS 1.2                     |
      |                             |                             | supported cipher suites     |                             |
      |                             |                             | (moderate compatibility and | TLS 1.1                     |
      |                             |                             | moderate security)          |                             |
      +-----------------------------+-----------------------------+-----------------------------+-----------------------------+
      | TLS-1-2                     |                             | TLS 1.2 and supported       | TLS 1.2                     |
      |                             |                             | cipher suites (moderate     |                             |
      |                             |                             | compatibility and high      |                             |
      |                             |                             | security)                   |                             |
      +-----------------------------+-----------------------------+-----------------------------+-----------------------------+
      | TLS-1-2-Strict              | Strict TLS 1.2 and          | TLS 1.2                     | ECDHE-RSA                   |
      |                             | supported cipher suites     |                             | -AES256-GCM-SHA384:ECDHE-RS |
      |                             | (low compatibility and      |                             | A-AES128-GCM-SHA256:ECDHE-E |
      |                             | ultra-high security)        |                             | CDSA-AES256-GCM-SHA384:ECDH |
      |                             |                             |                             | E-ECDSA-AES128-GCM-SHA256:A |
      |                             |                             |                             | ES128-GCM-SHA256:AES256-GCM |
      |                             |                             |                             | -SHA384:ECDHE-ECDSA-AES128- |
      |                             |                             |                             | SHA256:ECDHE-RSA-AES128-SHA |
      |                             |                             |                             | 256:AES128-SHA256:AES256-SH |
      |                             |                             |                             | A256:ECDHE-ECDSA-AES256-SHA |
      |                             |                             |                             | 384:ECDHE-RSA-AES256-SHA384 |
      +-----------------------------+-----------------------------+-----------------------------+-----------------------------+

#. Click **OK**.

Differences Between Security Policies
-------------------------------------



.. _elb_ug_jt_0022__table8551776916:

.. table:: **Table 2** Differences among the four types of security policies

   ============================= ======= ======= ======= ============== ==========
   Security Policy               TLS-1-0 TLS-1-1 TLS-1-2 TLS-1-2-Strict TLS-1-2-FS
   ============================= ======= ======= ======= ============== ==========
   TLS versions                                                         
   Protocol-TLS 1.3              -       -       -       -              Y
   Protocol-TLS 1.2              Y       Y       Y       Y              Y
   Protocol-TLS 1.1              Y       Y       -       -              -
   Protocol-TLS 1.0              Y       -       -       -              -
   Cipher suites                                                        
   EDHE-RSA-AES128-GCM-SHA256    Y       Y       Y       Y              -
   ECDHE-RSA-AES256-GCM-SHA384   Y       Y       Y       Y              Y
   ECDHE-RSA-AES128-SHA256       Y       Y       Y       Y              Y
   ECDHE-RSA-AES256-SHA384       Y       Y       Y       Y              Y
   AES128-GCM-SHA256             Y       Y       Y       Y              -
   AES256-GCM-SHA384             Y       Y       Y       Y              -
   AES128-SHA256                 Y       Y       Y       Y              -
   AES256-SHA256                 Y       Y       Y       Y              -
   ECDHE-RSA-AES128-SHA          Y       Y       Y       -              -
   ECDHE-RSA-AES256-SHA          Y       Y       Y       -              -
   AES128-SHA                    Y       Y       Y       -              -
   AES256-SHA                    Y       Y       Y       -              -
   ECDHE-ECDSA-AES128-GCM-SHA256 Y       Y       Y       Y              Y
   ECDHE-ECDSA-AES128-SHA256     Y       Y       Y       Y              Y
   ECDHE-ECDSA-AES128-SHA        Y       Y       Y       -              -
   ECDHE-ECDSA-AES256-GCM-SHA384 Y       Y       Y       Y              Y
   ECDHE-ECDSA-AES256-SHA384     Y       Y       Y       Y              Y
   ECDHE-ECDSA-AES256-SHA        Y       Y       Y       -              -
   ============================= ======= ======= ======= ============== ==========

Modifying a Security Policy
---------------------------

When you modify a security policy, ensure that the security group containing backend servers allows access from 100.125.0.0/16 and allows ICMP packets for UDP health checks. Otherwise, backend servers will be considered unhealthy, and routing will be affected.

#. Log in to the management console.
#. In the upper left corner of the page, click |image3| and select the desired region and project.
#. Hover on |image4| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.
#. Locate the load balancer and click its name.
#. Locate the listener and click |image5| on the right of its name.
#. On the **Modify Listener** page, expand **Advanced Settings** and modify the security policy.
#. Click **OK**.

.. |image1| image:: /images/en-us_image_0241356603.png

.. |image2| image:: /images/en-us_image_0000001120894978.png

.. |image3| image:: /images/en-us_image_0241356603.png

.. |image4| image:: /images/en-us_image_0000001120894978.png

.. |image5| image:: /images/en-us_image_0238408794.png

